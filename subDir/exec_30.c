#include <stdio.h>
void say_value(int a);
void changeInt(int *_target, const int _value);

int main(void) {
  int a = 5;
  char b = 's';

  int *iptr = &a;
  char *cptr = &b;

  *iptr = 2;
  *cptr = 'r';

  changeInt(iptr, 4);

  void (*fptr)(int) = {say_value};
  fptr(a);

  return 0;
}

void changeInt(int *_target, const int _value) { *_target = _value; }
void say_value(int a) { printf("Value of a is %d\n", a); }