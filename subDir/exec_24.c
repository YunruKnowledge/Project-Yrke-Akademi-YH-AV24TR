#include <stdio.h>
int main(void) {

  printf("Leap year checker.\n");
  printf("Enter a year...\n");
  int input = 0;
  printf("YEAR: ");
  scanf("%i", &input);

  int nextLeapYear = 0;
  int index = input;
  while (1) {
    if (!nextLeapYear) {
      if ((index % 4 == 0 && index % 100 != 0) || index % 400 == 0) {
        if (index == input) {
          printf("Same year is leap year. [%i]\n", index);
          printf("(Next) ");
        } else {
          printf("Closest leap year is [%i].\n", index);
          nextLeapYear = index;
        }
      }
      index++;
    } else {
      index--;
      if ((index % 4 == 0 && index % 100 != 0) || index % 400 == 0) {
        if (index == nextLeapYear || index == input) {
          // skip
        } else {
          printf("Previous leap year is [%i].\n", index);
          break;
        }
      }
    }
  }

  return 0;
}