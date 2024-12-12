#include <stdio.h>
#include <stdlib.h>

int listDigits(int _number);
int exponent(int _number, int _exponent);

int main(void) {
  printf("Digits: %i\n", listDigits(999));
  printf("Expo: %i\n", exponent(3, 2));
  return 0;
}

int listDigits(int _number) {
  return (abs(_number) < 10) ? 1 : 1 + listDigits(_number / 10);
}

int exponent(int _number, int _exponent) {
  return (_exponent == 0) ? 1 : _number * exponent(_number, _exponent - 1);
}
