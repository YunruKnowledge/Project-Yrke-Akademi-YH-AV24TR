
#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

static int n{0};
static std::atomic<int> aN{0};
static int mN{0};
std::mutex mtx;

void atomicIncrement(void) {
  for (size_t i = 0; i < 10000; i++) {
    aN++;
  }
}

void mutexIncrement(void) {
  for (size_t i = 0; i < 100; i++) {
    mtx.lock();
    mN++;
    mtx.unlock();
  }
}

void printLoop(void) {
  while (n < 3) {
    ;
  }
  std::cout << "Fumoes wer found.\n";
}

void printID(void) {
  std::cout << std::this_thread::get_id() << "->start\n";
  n++;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  n++;
  std::cout << std::this_thread::get_id() << "->end\n";
}

int main(void) {
  std::cout << std::this_thread::get_id() << "->Main start\n";

  std::thread t1{printID};
  std::thread t2{printLoop};
  
  t2.detach();
  t1.join();
  n++;

  std::thread a_t3{atomicIncrement};
  std::thread a_t4{atomicIncrement};
  std::thread a_t5{atomicIncrement};

  std::thread m_t3{mutexIncrement};
  std::thread m_t4{mutexIncrement};
  std::thread m_t5{mutexIncrement};

  a_t3.detach();
  a_t4.join();
  a_t5.detach();

  m_t3.join();
  m_t4.detach();
  m_t5.join();

  std::cout << "atomic: " << aN << std::endl;
  std::cout << "mutex: " << mN << std::endl;

  std::cout << std::this_thread::get_id() << "->Main end reached\n";
  return 0;
}
