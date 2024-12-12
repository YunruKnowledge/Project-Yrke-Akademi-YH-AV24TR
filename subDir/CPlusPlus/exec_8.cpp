#include <iostream>

int main(void) {
  unsigned int _input{0};

  std::cout << "Give a number between 0 and 255." << std::endl;
  do {
    std::cout << "Input: ";
    std::cin >> _input;
    std::cin.clear();
    std::cin.ignore();
  } while (_input > 255);

  std::cout << "BYTE: ";
  for (std::uint8_t i = 8 + 1; i > 0; i--) {
    std::cout << ((_input >> (i - 1)) & 0b1);
  }
  std::cout << std::endl;

  return 0;
}
