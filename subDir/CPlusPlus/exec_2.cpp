#include <cstdio>

int main(void) {
  unsigned int input;
  do {
    (void)printf("Input: ");
    if (scanf(" %u", &input) == 1) {
      if (input < 255) {
        break;
      }
    } else {
      int c;
      while ((c = getchar()) != '\n' && c != EOF) {
      }
    }
  } while (true);
  return 0;
}
