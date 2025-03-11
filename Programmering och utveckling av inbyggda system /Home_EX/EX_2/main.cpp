//
// Created by roki on 2025-03-11.
//
#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>

void create_threads(void);

static void case_one(void);

static void case_two(void);

static void case_three(void);

constexpr int ONE = 1;
constexpr int TWO = 2;
constexpr int THREE = 3;
constexpr int LOOP = 10;
constexpr int WAIT_FOR_SECONDS{1};

static volatile int number = ONE;

std::mutex mtx;
std::condition_variable cv;

int main(void) {
    create_threads();

    return 0;
}

void create_threads() {
    std::thread t1(case_one);
    std::thread t2(case_two);
    std::thread t3(case_three);

    t1.join();
    t2.join();
    t3.join();
}

static void case_one(void) {
    for (int i = 0; i < LOOP; i++) {
        std::unique_lock<std::mutex> lock{mtx};

        cv.wait(lock, [] { return number == ONE; });

        std::cout << "1 - ";
        number = TWO;

        lock.unlock();
        cv.notify_all();
    }
}

static void case_two(void) {
    for (int i = 0; i < LOOP; i++) {
        std::unique_lock<std::mutex> lock{mtx};

        cv.wait(lock, [] { return number == TWO; });

        std::cout << "2 - ";
        number = THREE;

        lock.unlock();
        cv.notify_all();
    }
}

static void case_three(void) {
    for (int i = 0; i < LOOP; i++) {
        std::unique_lock<std::mutex> lock{mtx};

        cv.wait(lock, [] { return number == THREE; });

        std::cout << "3" << std::endl;
        number = ONE;

        std::this_thread::sleep_for(std::chrono::seconds(WAIT_FOR_SECONDS));

        lock.unlock();
        cv.notify_all();
    }
}
