#include <iostream>
#include <random>

int main(void) {
  unsigned int _input{0};

  std::cin >> _input;
  while (std::cin.fail()) {
    std::cout << "Input: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> _input;
  };
  std::cout << "INPUT->" << _input << std::endl;

  bool _isPrime{true};
  for (size_t i = 2; i < _input; i++) {
    if (_input % i == 0) {
      _isPrime = false;
      break;
    }
  }
  
  if (_isPrime) {
    std::cout << "Is it prime number!" << std::endl;
  } else {
    std::cout << "Not prime number!" << std::endl;
  }

  return 0;
}