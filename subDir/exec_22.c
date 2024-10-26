#include <ctype.h>
#include <stdio.h>

int main(void) {
  char _char;
  char *ptr = &_char;
  while ((*ptr = getchar()) != '\n') {
    if (*ptr == toupper(*ptr)) {
      *ptr = tolower(*ptr);
      putchar(*ptr);
    } else {
      *ptr = toupper(*ptr);
      putchar(*ptr);
    }
  }
  printf("\n");
  return 0;
}