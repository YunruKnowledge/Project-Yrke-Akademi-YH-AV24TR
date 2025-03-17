

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

static std::mutex mtx;
static std::condition_variable condition;

template <typename T, int SIZE> class Stack {
  T array[SIZE];
  uint32_t amount{0};

public:
  Stack(const T &) = delete;
  Stack &operator=(const T &) = delete;
  Stack() = default;

  /**
   * @brief Adds a value into stack.
   *
   * @param _value
   */
  void push(const T _value) {
    std::unique_lock<std::mutex> lock{mtx};
    while (amount >= SIZE) {
      condition.wait(lock);
    }

    array[amount] = _value;
    amount++;
    lock.unlock();
    condition.notify_all();
  }

  /**
   * @brief Returns and removes top layer.
   *
   * @return The value stored at the top.
   */
  T pop(void) {
    std::unique_lock<std::mutex> lock{mtx};
    while (amount == 0) {
      condition.wait(lock);
    }

    T var = array[amount - 1];
    amount--;
    lock.unlock();
    condition.notify_all();
    return var;
  }
};

void th_push(Stack<int, 5> &_stack) {
  for (size_t i = 0; i < 50000; i++) {
    int var = 10 + i;
    _stack.push(var);
    {
      std::scoped_lock<std::mutex> lock{mtx};
      std::cout << "->" << var << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds((rand() % 100 + 1)));
    }
  }
}

void th_pop(Stack<int, 5> &_stack) {
  for (size_t i = 0; i < 10000; i++) {
    int var = _stack.pop();
    {
      std::scoped_lock<std::mutex> lock{mtx};
      std::cout << "<-" << var << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds((rand() % 100 + 1)));
  }
}

int main(void) {
  Stack<int, 5> stack;

  std::thread thread1{th_push, std::ref(stack)};
  std::thread thread2{th_pop, std::ref(stack)};
  std::thread thread3{th_pop, std::ref(stack)};
  std::thread thread4{th_pop, std::ref(stack)};
  std::thread thread5{th_pop, std::ref(stack)};
  std::thread thread6{th_pop, std::ref(stack)};

  thread1.join();
  thread2.join();
  thread3.join();
  thread4.join();
  thread5.join();
  thread6.join();

  // stack.push(2);
  // std::cout << stack.pop() << std::endl;
  return 0;
}