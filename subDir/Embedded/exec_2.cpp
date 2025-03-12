#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
static std::condition_variable condition;
static int var{1};

void fthread1(void) {
  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::unique_lock<std::mutex> lock{mtx};
    while (var != 1) {
      condition.wait(lock);
    }
    std::cout << "1 -";
    var++;
    lock.unlock();
    condition.notify_all();
  }
}
void fthread2(void) {
  while (true) {
    std::unique_lock<std::mutex> lock{mtx};
    while (var != 2) {
      condition.wait(lock);
    }
    std::cout << " 2 -";
    var++;
    lock.unlock();
    condition.notify_all();
  }
}
void fthread3(void) {
  while (true) {
    std::unique_lock<std::mutex> lock{mtx};
    while (var != 3) {
      condition.wait(lock);
    }
    std::cout << " 3\n";
    var = 1;
    lock.unlock();
    condition.notify_all();
  }
}

int main(void) {
  std::thread t1{fthread1};
  std::thread t3{fthread3};
  std::thread t2{fthread2};

  t2.join();
  t1.join();
  t3.join();
  
  return 0;
}