#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>

constexpr int LOOP = 100;
constexpr int WAIT_FOR_MILLISECONDS = 200;

std::mutex mtx;
std::condition_variable cv;

template<typename T, volatile size_t N>
class Stack {
    volatile T arr[N];
    volatile int capacity{0};

public:
    Stack() = default;

    Stack(const Stack &) = delete;

    Stack &operator=(const Stack &) = delete;

    ~Stack() = default;

public:
    void pop(T &var) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return (capacity > 0); });

        var = arr[--capacity];
        std::cout << "Popped " << var << std::endl;

        lock.unlock();
        cv.notify_all();
    }

    void push(T data) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return (capacity != N); });

        arr[capacity++] = data;
        std::cout << "Pushed " << data << std::endl;

        lock.unlock();
        cv.notify_all();
    }

    size_t size(void) { return capacity; }
};

Stack<int, 10> stack;

void pust_to_stack(int offset);

void pop_from_stack(void);

int main(void) {
    std::thread push_thread(pust_to_stack, 1);
    std::thread p_push_thread(pust_to_stack, 100);
    std::thread pop_thread(pop_from_stack);


    push_thread.join();
    p_push_thread.join();
    pop_thread.join();

    return 0;
}

void pust_to_stack(int offset) {
    for (int i = 1; i <= LOOP; i++) {
        stack.push(i * offset);
        std::this_thread::sleep_for(std::chrono::milliseconds(WAIT_FOR_MILLISECONDS + offset));
    }
}

void pop_from_stack(void) {
    int var{0};
    for (int i = 1; i <= LOOP * 2; i++) {
        stack.pop(var);
        std::this_thread::sleep_for(std::chrono::milliseconds(WAIT_FOR_MILLISECONDS));
    }
}
