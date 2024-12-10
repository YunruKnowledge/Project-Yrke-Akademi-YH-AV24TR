#include <stdarg.h>
#include <stdio.h>

int addSum(int _num1, int _num2, ...);

int main(void) {
  printf("Sum is %i", addSum(2, 3, 4, 6, 7)); // -> 22
  return 0;
}

int addSum(int _num1, int _num2, ...) {
  va_list args;
  va_start(args, _num2);
  int _num3 = va_arg(args, int);
  int _num4 = va_arg(args, int);
  int _num5 = va_arg(args, int);
  va_end(args);
  return (_num1 + _num2 + _num3 + _num4 + _num5);

}