#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define BUFFER 5

typedef bool (*compare_t)(int, int);

bool compare_asc(int a, int b);
bool compare_desc(int a, int b);
void setIntArray(int *_array, int _size);
void printIntArray(int *_array, int _size);
void swapIntValues(int *a, int *b);
void sort_array(int *arr, size_t length, compare_t compare);

int main(void) {
  int array[BUFFER] = {0};
  printIntArray(array, BUFFER);

  setIntArray(array, BUFFER);
  printIntArray(array, BUFFER);

  sort_array(array, BUFFER, compare_asc);
  printIntArray(array, BUFFER);
  sort_array(array, BUFFER, compare_desc);
  printIntArray(array, BUFFER);
  return 0;
}

void setIntArray(int *_array, int _size) {
  for (int i = 0; i < _size; i++) {
    _array[i] = rand() % MAX;
  }
}

void printIntArray(int *_array, int _size) {
  for (int i = 0; i < _size; i++) {
    (void)printf("%i ", _array[i]);
  }
  (void)printf("\n");
}

void swapIntValues(int *a, int *b) {
  int _temp = *a;
  *a = *b;
  *b = _temp;
}

void sort_array(int *arr, size_t length, compare_t compare) {

  while (length) {
    int loop = 0;
    for (size_t i = 0; i < length - 1; i++) {
      if (compare(arr[i], arr[i + 1])) {
        swapIntValues(&arr[i], &arr[i + 1]);
        loop = 1;
      }
    }
    if (!loop)
      break;
  }
}

bool compare_asc(int a, int b) { return (a > b) ? true : false; }
bool compare_desc(int a, int b) { return (a < b) ? true : false; };
