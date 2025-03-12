

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

static std::mutex mtx;
static std::shared_mutex shmtx;
static std::condition_variable condition;

template <typename T> class Stack {
  static constexpr uint32_t BUFFER_SIZE = 5;
  volatile T array[BUFFER_SIZE];
  volatile uint32_t amount{0};

public:
  Stack(const T &) = delete;
  Stack &operator=(const T &) = delete;
  Stack() = default;

public:
  /**
   * @brief Returns the max size of the stack.
   *
   * @return uint32_t
   */
  uint32_t size(void) {
    shmtx.lock_shared();
    uint32_t value{BUFFER_SIZE};
    shmtx.unlock_shared();
    return value;
  }

  /**
   * @brief Returns the amount of valid data in the stack.
   *
   * @return uint32_t
   */
  uint32_t length(void) {
    shmtx.lock_shared();
    uint32_t value{amount};
    shmtx.unlock_shared();
    return value;
  }

  /**
   * @brief
   *
   * @return `true` when length is same as size, otherwise `false`.
   */
  bool isFull(void) {
    shmtx.lock_shared();
    bool value{(amount == BUFFER_SIZE) ? true : false};
    shmtx.unlock_shared();
    return value;
  }

  /**
   * @brief
   *
   * @return `true` when length is 0, otherwise `false`.
   */
  bool isEmpty(void) {
    shmtx.lock_shared();
    bool value{(amount == 0) ? true : false};
    shmtx.unlock_shared();
    return value;
  }

  /**
   * @brief Adds a value into stack.
   *
   * @param _value
   */
  void push(const T _value) {
    std::unique_lock<std::mutex> lock{mtx};
    while (isFull()) {
      condition.wait(lock);
    }

    array[amount] = _value;
    amount++;
    lock.unlock();
    condition.notify_one();
  }

  /**
   * @brief Returns and removes top layer.
   *
   * @return The value stored at the top.
   */
  T pop(void) {
    std::unique_lock<std::mutex> lock{mtx};
    while (isEmpty()) {
      condition.wait(lock);
    }

    T var = array[amount - 1];
    amount--;
    lock.unlock();
    condition.notify_one();
    return var;
  }
};

void th_push(Stack<int> &_stack) {
  _stack.push(100);
  _stack.push(200);
  _stack.push(300);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  _stack.push(400);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  _stack.push(500);
  std::this_thread::sleep_for(std::chrono::seconds(1));

  for (size_t i = 0; i < 7; i++) {
    _stack.push(600 + i);
  }

  std::this_thread::sleep_for(std::chrono::seconds(8));
  for (size_t i = 0; i < 1000; i++) {
    int var = 10 + i;
    _stack.push(var);
    {
      std::scoped_lock<std::mutex> lock{mtx};
      std::cout << "->" << var << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds((rand() % 10 + 1)));
  }
}

void th_pop(Stack<int> &_stack) {
  for (size_t i = 0; i < 5; i++) {
    int var = _stack.pop();
    std::cout << var << std::endl;
  }

  std::this_thread::sleep_for(std::chrono::seconds(1));

  for (size_t i = 0; i < 7; i++) {
    int var = _stack.pop();
    std::cout << var << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  for (size_t i = 0; i < 1000; i++) {
    int var = _stack.pop();
    {
      std::scoped_lock<std::mutex> lock{mtx};
      std::cout << "<-" << var << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds((rand() % 10 + 1)));
  }
}

/**
 * @brief Explaination.
 * 2 threads, one push, one pop.
 *
 * Stage 1:
 * 5 Pops & 3 Pushes + 2 with delay.
 *
 * Stage 2:
 * 7 Pops with delay & 7 Pushes.
 *
 * Stage 3:
 * Forloop random delay, Push & Pop.
 *
 * @return int
 */
int main(void) {
  Stack<int> stack;

  std::thread thread2{th_pop, std::ref(stack)};
  std::thread thread1{th_push, std::ref(stack)};

  thread1.join();
  thread2.join();

  // stack.push(2);
  // std::cout << stack.pop() << std::endl;
  return 0;
}