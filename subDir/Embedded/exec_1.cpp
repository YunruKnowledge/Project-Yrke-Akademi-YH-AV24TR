#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
std::mutex mtx2;

void ping(void) {
  mtx.lock();
  std::cout << "Ping";
  mtx2.unlock();
}

void pong(void) {
  mtx2.lock();
  std::cout << " - Pong" << std::endl;
  mtx.unlock();
}

int main(void) {
  for (size_t i = 0; i < 10; i++) {
    std::thread t1{ping};
    std::thread t2{pong};

    t2.detach();
    t1.detach();

    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  return 0;
}