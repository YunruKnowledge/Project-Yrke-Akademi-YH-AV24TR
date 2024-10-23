#include <stdio.h>

int main(void) {
  char _char;
  while ((_char = getchar()) != '\n') {
    if (_char == ' ') {
        (void)printf("\n");
    } else {
      (void)printf("%c", _char);
    }
  }

  return 0;
}