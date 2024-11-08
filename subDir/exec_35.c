#include <stdbool.h>
#include <stdio.h>

bool checkPrime(const int _val);

int main(void) {
  printf("Prime checker.\n");
  printf("Please enter a number.\n");
  unsigned int input = 0;

  if (scanf("%u", &input) != 1) {
    (void)printf("Balls...");
  } else {
    if ((input >> ((sizeof(input) * 8) - 1)) & 1) {
      (void)printf("Warning last bit is 1\n");
      (void)printf("Input value: %u\n", input);
    }
    checkPrime(input) ? (void)printf("The input was a prime number.")
                      : (void)printf("It was not a prime number.");
  }
  return 0;
}

bool checkPrime(const int _val) {
  int _isPrime = 1, _index = 2;
  while (_index < _val) {
    if (_val % _index == 0) {
      _isPrime = 0;
      break;
    } else {
      _index++;
    }
  }
  return _isPrime;
}