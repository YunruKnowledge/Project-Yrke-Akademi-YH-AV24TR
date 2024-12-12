/**
 * @file ex241114.c
 * @author Khanh Tran
 * @brief Ask user to allocate int array size, then initialize and print.
 * @version 0.1
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>

void scanfFlush() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

int main(void) {
  int allocMemSize, validCount = 0;

  do {
    validCount = 0;
    (void)printf("Size:\n");
    validCount = scanf(" %i", &allocMemSize);
    scanfFlush();
  } while (!validCount);

  // int *arrAlloc = (int *)calloc(allocMemSize, sizeof(int));
  int *arrAlloc = (int *)malloc(sizeof(int) * allocMemSize);

  for (int i = 0; i < allocMemSize; i++) {
    arrAlloc[i] = 2;
    printf("%i", arrAlloc[i]);
  }

  do {
    validCount = 0;
    (void)printf("New size:\n");
    validCount = scanf(" %i", &allocMemSize);
    scanfFlush();
  } while (!validCount);

  int *newArrAlloc = (int *)realloc(arrAlloc, sizeof(int) * allocMemSize);

  for (int i = 0; i < allocMemSize; i++) {
    // newArrAlloc[i] = 2;
    (void)printf("%i", newArrAlloc[i]);
  }

  free(newArrAlloc);
  // free(arrAlloc);

  return 0;
}
