#include "fizzbuzz.h"
#include <stdio.h>
#include <string.h>

int main(void) {
  (void)fizz_buzz_set(1, 2, "Balls");
  while (1) {
    int input = 0;
    fizz_buzz_stat_reset();

    printf("Input: ", input);
    if (scanf("%d", &input)) {
      for (size_t i = 1; i <= input; i++) {
        printf("%s ", fizz_buzz(i));
      }
    }

    fizz_buzz_stat_print();

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
  }

  return 0;
}