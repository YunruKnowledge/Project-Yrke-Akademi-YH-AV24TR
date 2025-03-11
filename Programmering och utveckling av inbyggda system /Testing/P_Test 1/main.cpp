#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex mtx0, mtx1;

int wait_for_seconds{1};
size_t thread_loop{10};

void task(void);

void task1(void);

void make_threads(void);

int main(void) {
  for (size_t i = 0; i < thread_loop; i++) {
    make_threads();
  }

  return 0;
}

void make_threads(void) {
  std::thread t1(task);
  std::thread t2(task1);

  t1.join();
  t2.join();
}

void task(void) {
  std::lock_guard<std::mutex> lock(mtx0, std::adopt_lock);
  std::cout << "Ping - ";

  std::this_thread::sleep_for(std::chrono::seconds(wait_for_seconds));
}

void task1(void) {
  std::lock_guard<std::mutex> lock(mtx1, std::adopt_lock);
  std::cout << "Pong" << std::endl;

  std::this_thread::sleep_for(std::chrono::seconds(wait_for_seconds));
}
