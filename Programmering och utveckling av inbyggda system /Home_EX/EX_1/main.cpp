//
// Created by roki on 2025-03-11.
//
#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>

void create_threads(void);

void print_ping(void);

void print_pong(void);

constexpr static int PING = 0;
constexpr static int PONG = 1;
constexpr static int LOOP = 10;
constexpr static int WAIT = 1;

static volatile int ping_pong = PING;

std::mutex mtx;
std::condition_variable cv;

int main(void) {
    create_threads();

    return 0;
}

void create_threads() {
    std::thread t1{print_ping};
    std::thread t2{print_pong};

    t1.join();
    t2.join();
}


void print_ping(void) {
    for (int i = 0; i < LOOP; i++) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [] { return ping_pong == PING; });

        std::cout << "Ping - ";
        ping_pong = PONG;

        mtx.unlock();
        cv.notify_all();
    }
}

void print_pong(void) {
    for (int i = 0; i < LOOP; i++) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [] { return ping_pong == PONG; });

        std::cout << "Pong" << std::endl;
        ping_pong = PING;

        std::this_thread::sleep_for(std::chrono::seconds(WAIT));

        mtx.unlock();
        cv.notify_all();
    }
}
