#include <stdio.h>
#define BUFFER 20

void printHello(void);

void basicPrint(const char _string[BUFFER]);

int getSum(const int a, const int b);

int getSquare(const int a);

int getSquareRoot(const int a);

float getAvarage(const int a, const int b, const int c);

int checkPrime(const int _val);

void readString(const char *_string, const char _size);

int main(void) {

  printHello();

  const char hewo[BUFFER] = "Hewo World :3\n";
  basicPrint(hewo);

  (void)printf("Sum of 2 and 5 is %i.\n", getSum(2, 5));

  (void)printf("The square of 9 is %i.\n", getSquare(9));

  (void)printf("The square root of 9 is %i.\n", getSquareRoot(9));

  (void)printf("The avarage of 3, 7 and 9 is %.02f.\n", getAvarage(3, 7, 9));

  checkPrime(27) ? printf("Its in fact a PRIME!! 27\n")
                 : printf("Its in fact NOT PRIME!! 27\n");
  checkPrime(7) ? printf("Its in fact a PRIME!! 7\n")
                : printf("Its in fact NOT PRIME!! 7\n");
  checkPrime(269) ? printf("Its in fact a PRIME!! 269\n")
                  : printf("Its in fact NOT PRIME!! 269\n");

  const char newString[] = "String Deeznuts";
  readString(newString, sizeof(newString) - 1);

  return 0;
}

void printHello(void) { (void)printf("HELLO WORLD!\n"); }

void basicPrint(const char _string[BUFFER]) {
  (void)printf("%s", _string);
  (void)printf("\n");
}

int getSum(const int a, const int b) { return (a + b); }

int getSquare(const int a) { return (a * a); }

int getSquareRoot(const int a) {
  unsigned int _index = 0;
  while (_index < a) {
    if (_index * _index == a) {
      break;
    } else {
      _index++;
    }
  };
  return _index;
}

float getAvarage(const int a, const int b, const int c) {
  return (float)(a + b + c) / 3;
}

int checkPrime(const int _val) {
  int _isPrime = 1;
  int _index = 2;
  while (_index < _val) {
    if (_val % _index == 0) {
      _isPrime = 0;
      break;
    }
    _index++;
  }
  return _isPrime;
}

void readString(const char *_string, const char _size) {
  int _index = 0;
  while (_index < _size) {
    (void)printf("%c ", _string[_index]);
    _index++;
  }
  (void)printf("\n");
}