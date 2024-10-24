#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define RANDOM_VAL (rand() % MAX)
#define ARR_SIZE (int)6

int main(void) {
  int arr[2][3];
  srand(time(NULL));

  int *ptr = &arr[0][0];
  for (int i = 0; i < ARR_SIZE; i++) {
    *(ptr + i) = RANDOM_VAL;
    (void)printf("%i - ", i);
    (void)printf("%i\n", *(ptr + i));
  }

  return 0;
}