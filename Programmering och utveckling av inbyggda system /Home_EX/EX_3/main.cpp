#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>

constexpr int LOOP = 100;
constexpr int WAIT_FOR_MILLISECONDS = 300;

std::mutex mtx;
std::condition_variable cv;

template<typename T, size_t N>
class Stack {
    T arr[N];

    int capacity{0};

public:
    Stack() {
    }

    Stack(const Stack &) = delete;

    Stack &operator=(const Stack &) = delete;

    ~Stack() {
    }

public:
    void pop(void) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [&] { return capacity != 0; });
        T var = arr[--capacity];

        std::cout << "Popped " << var << std::endl;

        cv.notify_all();
    }

    void push(T data) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [&] { return capacity != N; });
        arr[capacity++] = data;

        std::cout << "Pushed " << data << std::endl;

        cv.notify_all();
    }
};

Stack<int, 10> stack;

void pust_to_stack(void);

void pop_from_stack(void);

int main(void) {
    std::thread push_thread(pust_to_stack);
    std::thread pop_thread(pop_from_stack);

    push_thread.join();
    pop_thread.join();

    return 0;
}

void pust_to_stack(void) {
    for (int i = 1; i <= LOOP; i++) {
        stack.push(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(WAIT_FOR_MILLISECONDS));
    }
}

void pop_from_stack(void) {
    for (int i = 1; i <= LOOP; i++) {
        stack.pop();
        std::this_thread::sleep_for(std::chrono::milliseconds(WAIT_FOR_MILLISECONDS));
    }
}
