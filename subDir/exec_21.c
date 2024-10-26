#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define RANDOM_VAL (rand() % MAX)
#define ARR_SIZE (sizeof(arr) / sizeof(arr[0]))
int arr[10];

int main(void) {
  srand(time(NULL));
  int(*ptr)[10] = &arr;

  // setval
  for (size_t i = 0; i < ARR_SIZE; i++) // sizeof 10
  {
    (*ptr)[i] = RANDOM_VAL;
    (void)printf("%02i ", (*ptr)[i]);
  }

  // sort
  int loopIndex = 0;
  int sortedAmountBuffer = 0;
  while (1) {
    if ((*ptr)[loopIndex] > (*ptr)[loopIndex + 1] &&
        loopIndex < (int)ARR_SIZE - 1) {
      int temp = (*ptr)[loopIndex];
      (*ptr)[loopIndex] = (*ptr)[loopIndex + 1];
      (*ptr)[loopIndex + 1] = temp;
      sortedAmountBuffer++;
    } else if (loopIndex >= (int)ARR_SIZE) {
      if (sortedAmountBuffer == 0) {
        break; // <----------------------------------
      } else {
        loopIndex = 0;
        sortedAmountBuffer = 0;
      }
    } else {
      loopIndex++;
    }
  }

  // print
  printf("\n***Sorted values***\n");
  for (size_t i = 0; i < ARR_SIZE; i++) // sizeof 10
  {
    (void)printf("%02i ", (*ptr)[i]);
  }
  (void)printf("\n");

  return 0;
}