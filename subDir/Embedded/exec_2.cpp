#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
static int var{1};

void fthread1(void) {
  while (true) {
    if (var == 1) {
      std::cout << "1 -";
      mtx.lock();
      var++;
      mtx.unlock();
      break;
    }
  }
}
void fthread2(void) {
  while (true) {
    if (var == 2) {
      std::cout << " 2 -";
      mtx.lock();
      var++;
      mtx.unlock();
      break;
    }
  }
}
void fthread3(void) {
  while (true) {
    if (var == 3) {
      std::cout << " 3\n";
      mtx.lock();
      var = 1;
      mtx.unlock();
      break;
    }
  }
}

int main(void) {
  for (size_t i = 0; i < 10; i++) {
    std::thread t1{fthread1};
    std::thread t3{fthread3};
    std::thread t2{fthread2};

    t2.detach();
    t1.detach();
    t3.detach();
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  return 0;
}