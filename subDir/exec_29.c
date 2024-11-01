#include <stdio.h>
#define MAX_INPUT ((2) - 1)

void findPrime(const unsigned int m, const unsigned int n);

int main(void) {
  unsigned int input[MAX_INPUT] = {0};
  scanf("%u %u", &input[0], &input[1]);

  (void)printf("Entered range: %u - ", input[0]);
  (void)printf("%u\n", input[1]);

  findPrime(input[0], input[1]);
  return 0;
}

void findPrime(const unsigned int m, const unsigned int n) {
  for (unsigned int _index = m; _index <= n; _index++) {
    unsigned int _isPrime = 1;
    if (_index <= 1) {
      // 1 - not prime
      _isPrime = 0;
    } else if (_index == 2) {
      // prime start
    } else if (_index & 0b1) {
      // odds
      for (unsigned int _oddIndex = 3; _oddIndex < _index; _oddIndex += 2) {
        if (_index % _oddIndex == 0) {
          // not prime
          _isPrime = 0;
        }
        // prime
      }
    } else {
      // even - not prime
      _isPrime = 0;
    }
    _isPrime ? (void)printf("%u", _index) : (void)printf("_");
  }
  (void)printf("\n");
}