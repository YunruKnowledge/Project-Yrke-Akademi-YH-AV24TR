#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

constexpr int WAIT_FOR_SECOND = 1;

void print_ping(void);

void print_pong(void);

void create_thread(void);

std::mutex mtx_ping, mtx_pong;

int main() {
    create_thread();
    return 0;
}

void create_thread(void) {
    mtx_pong.lock();
    std::thread ping(print_ping);
    std::thread pong(print_pong);

    ping.join();
    pong.join();
}

void print_ping() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(WAIT_FOR_SECOND));
        mtx_ping.lock();
        std::cout << "Ping - ";
        mtx_pong.unlock();
    }
}

void print_pong() {
    while (true) {
        mtx_pong.lock();
        std::cout << "Pong" << std::endl;
        mtx_ping.unlock();
    }
}
