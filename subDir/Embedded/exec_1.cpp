#include <iostream>
#include <mutex>
#include <thread>


std::mutex mtx;
std::mutex mtx2;

void ping(void) {
  while(true) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mtx.lock();
    std::cout << "Ping";
    mtx2.unlock();
  }
}

void pong(void) {
  while(true) {
    mtx2.lock();
    std::cout << " - Pong" << std::endl;
    mtx.unlock();
    // std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

int main(void) {
  mtx2.lock();

  std::thread t1{ping};
  std::thread t2{pong};

  t2.join();
  t1.join();

  return 0;
}