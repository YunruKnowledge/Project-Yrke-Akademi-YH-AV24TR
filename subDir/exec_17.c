#include <stdio.h>

const char NAME[20];

int main() {
  scanf("%20s", *&NAME);
  int nameLength = (sizeof(NAME) / sizeof(NAME[0])) - 1;
  for (int i = nameLength; i >= 0; i--) {
    (void)printf("%c", NAME[i]);
  }
  return 0;
}