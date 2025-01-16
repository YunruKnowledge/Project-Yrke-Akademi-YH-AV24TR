
#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>


constexpr size_t GENERATE{1000};
constexpr size_t MAX{100000};
constexpr size_t MIN{100};
constexpr size_t DIVISOR{2};

int main(void) {
  srand(time(NULL));

  std::vector<size_t> viktor;
  for (size_t i = 0; i < GENERATE; i++) {
    viktor.push_back(rand() % MAX + MIN);
  }

  // no handling for temp <= 1, min range is 100
  for (size_t i = 0; i < viktor.size(); i++) {
    bool divisable = false;
    auto temp = viktor[i];

    for (size_t div = DIVISOR; div * div < temp; div++) {
      if ((temp % div) == 0) {
        divisable = true;
        break;
      }
    }

    if (divisable) {
      viktor.erase(viktor.begin() + i--);
    }
  }

  std::sort(viktor.begin(), viktor.end(),
            [](auto _a, auto _b) { return (_a < _b); });

  for (auto temp : viktor) {
    std::cout << temp << " ";
  }

  return 0;
}
