//
// Created by roki on 2025-03-11.
//
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

void create_threads(void);

void print_ping(void);

void print_pong(void);

constexpr static int LOOP = 10;
constexpr static int WAIT = 1;

std::mutex mtx_ping, mtx_pong;

int main(void) {
    for (int i = 0; i < LOOP; i++) {
        create_threads();
    }

    return 0;
}

void create_threads() {
    std::thread t1{print_ping};
    std::thread t2{print_pong};

    t1.join();
    t2.join();

    std::this_thread::sleep_for(std::chrono::seconds(WAIT));
}


void print_ping(void) {
    mtx_ping.lock();
    std::cout << "Ping - ";
    mtx_ping.unlock();
}

void print_pong(void) {
    mtx_pong.lock();
    std::cout << "Pong" << std::endl;
    mtx_pong.unlock();
}
