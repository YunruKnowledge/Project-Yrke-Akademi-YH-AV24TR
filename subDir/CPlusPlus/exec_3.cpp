#include <iostream>

int main(void) {
  size_t _temp;
  std::cout << "Give a number." << std::endl << "Input: ";
  std::cin >> _temp;

  size_t _sum = 0;
  for (size_t i = 0; i < _temp; i++) {
    if (i % 2 == 0) {
      std::cout << "[i]=" << i << " | [sum]=" << _sum << std::endl;
      _sum += i;
    }
  }

  std::cout << "Total: " << _sum;

  return 0;
}
