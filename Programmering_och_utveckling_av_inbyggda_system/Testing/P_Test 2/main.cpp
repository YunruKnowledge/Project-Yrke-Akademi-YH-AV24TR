#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>

constexpr int LOOP = 1000;
constexpr int WAIT_FOR_MILLISECONDS = 300;

template<typename T, size_t N>
class Stack {
    volatile T arr[N];
    volatile size_t capacity{0};

    std::mutex mutex;
    std::condition_variable cv;

public:
    Stack() = default;

    Stack(const Stack &) = delete;

    Stack &operator=(const Stack &) = delete;

    ~Stack() = default;

public:
    void push(T const &value);

    T pop();
};

template<typename T, size_t N>
void Stack<T, N>::push(T const &value) {
    std::unique_lock<std::mutex> lock(mutex);
    cv.wait(lock, [&] { return capacity != N; });

    arr[capacity++] = value;

    cv.notify_one();
}

template<typename T, size_t N>
T Stack<T, N>::pop() {
    std::unique_lock<std::mutex> lock(mutex);
    cv.wait(lock, [&] { return capacity != 0; });

    T value = arr[--capacity];

    cv.notify_one();
    return value;
}

void create_threads(void);

void push_to_stack(int offset);

void pop_from_stack(void);

Stack<int, 100> stack;

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    create_threads();

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start);
    std::cout << "Time: " << duration.count() << "s" << std::endl;
    return 0;
}

void create_threads(void) {
    std::thread push_one(push_to_stack, 1);
    std::thread pop_one(pop_from_stack);

    std::thread push_two(push_to_stack, 20);
    std::thread pop_two(pop_from_stack);

    std::thread push_three(push_to_stack, 30);
    std::thread pop_four(pop_from_stack);

    push_one.join();
    pop_one.join();
    push_two.join();
    pop_two.join();
    push_three.join();
    pop_four.join();
}

void push_to_stack(int offset) {
    std::mutex mutex;
    for (int i = 0; i < LOOP; i++) {
        std::this_thread::sleep_for(
            std::chrono::milliseconds((rand() % WAIT_FOR_MILLISECONDS + 1) + WAIT_FOR_MILLISECONDS + offset));
        stack.push(i * offset);
        std::scoped_lock<std::mutex> c_lock{mutex}; {
            std::cout << "Pushed <- " << i * offset << std::endl;
        }
    }
}

void pop_from_stack(void) {
    std::mutex mutex;
    for (int i = 0; i < LOOP; i++) {
        int var = stack.pop();
        std::scoped_lock<std::mutex> lock(mutex); {
            std::cout << "Popped -> " << var << std::endl;
        }
        std::this_thread::sleep_for(
            std::chrono::milliseconds((rand() % WAIT_FOR_MILLISECONDS + 1) + WAIT_FOR_MILLISECONDS));
    }
}
