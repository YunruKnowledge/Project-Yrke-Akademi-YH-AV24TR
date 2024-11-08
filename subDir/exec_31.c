#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 7
#define MATRIX_SIZE 2

void RandomFillIntArray(int *_array, int _size);
void printIntArray(int *_array, int _size);
void printIntMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]);

int main(void) {
  int intArr[ARR_SIZE] = {0};
  int intArrMatrix[MATRIX_SIZE][MATRIX_SIZE] = {{1, 2}, {3, 4}};
  srand(time(NULL));

  printIntArray(intArr, ARR_SIZE);
  (void)printf("\n");
  RandomFillIntArray(intArr, ARR_SIZE);
  printIntArray(intArr, ARR_SIZE);
  (void)printf("\n");
  printIntMatrix(intArrMatrix);
  (void)printf("\n");

  return 0;
}

void RandomFillIntArray(int *_array, int _size) {
  for (int i = 0; i < _size; i++) {
    _array[i] = rand() % 100;
  }
}

void printIntArray(int *_array, int _size) {
  for (int i = 0; i < _size; i++) {
    (void)printf("%i ", _array[i]);
  }
}

void printIntMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
  for (int i = 0; i < (MATRIX_SIZE * MATRIX_SIZE); i++) {
    if ((i + 1) % MATRIX_SIZE == 0) {
      (void)printf("%i ", matrix[0][i]);
      (void)printf("\n");
    } else {
      (void)printf("%i ", matrix[0][i]);
    }
  }
}