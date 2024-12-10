#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1u
#define MAX 99u
#define INT_ARR_SIZE sizeof(arr) / sizeof(arr[0])
#define GEN_RANDOM rand() % MAX + MIN

void generateArray(unsigned int *arr, unsigned int length) {
  for (unsigned int i = 0; i < length; i++) {
    unsigned int randomNum = GEN_RANDOM;

    for (unsigned int arrCompIndex = 0;
         arrCompIndex < i; // indez < i for compare to given indexes only.
         arrCompIndex++) {
      if (arr[arrCompIndex] == randomNum) {
        (void)printf("INVALID MATCH -> [%02u] %2u -> [%02u] %2u\n", i,
                     arr[arrCompIndex], arrCompIndex, randomNum);
        randomNum = GEN_RANDOM;
        arrCompIndex = 0;
        continue;
      }
    }

    arr[i] = randomNum;
  }
};

void printArray(unsigned int *arr, unsigned int length) {
  for (unsigned int i = 0; i < length; i++) {
    (void)printf("[%02u] %2u\n", i, arr[i]);
  }
}

int main(void) {
  srand(time(NULL));
  unsigned int arr[MAX] = {0};

  generateArray(arr, INT_ARR_SIZE);
  printArray(arr, INT_ARR_SIZE);

  return 0;
}