#include <iostream>

size_t countDigits(int _number, size_t _offset);
int mathExponent(int _x, unsigned int _y);

int main(void) {
  std::cout << "Digits->" << countDigits(456, 0) << std::endl;
  std::cout << "Expo->" << mathExponent(2, 3) << std::endl;
  return 0;
}

size_t countDigits(int _number, size_t _offset) {
  if (_number != 0)
    return _number / 10 != 0 ? countDigits(_number / 10, _offset + 1)
                             : _offset + 1;
  else
    return 0;
}

int mathExponent(int _x, unsigned int _y) {
  return _y - 1 == 0 ? _x : mathExponent(_x + _x, _y - 1);
}