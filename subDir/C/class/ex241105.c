#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define STRING "string7 hello world"

#define min 0
#define max 255
#define INT_ARRAY_BUFFER 24

int checkStringLength(const char *_string);
void swapIntValues(int *a, int *b);
void rawPrintByte(const int _value);
void sortIntArray(int *_array, int _size);
int *newMergeIntArray(const int *_array_one, const int _size_one,
                      const int *_array_two, const int _size_two);

int main(void) {
  // 1
  const char buh[64];
  (void)printf("\"%s\" - [%i]\n", STRING, checkStringLength(STRING));
  (void)printf("\"%s\" - [%i]\n", buh, checkStringLength(buh));

  // 2
  int a = 1;
  int b = 9;
  (void)printf("a:%i\nb:%i\n", a, b);
  swapIntValues(&a, &b);
  (void)printf("*swap*\n");
  (void)printf("a:%i\nb:%i\n", a, b);

  // 3

  int input = 123;
  // scanf("%i", &input);
  printf("%i\n", input);
  printf("binary goal -> %b\n", input);

  if (input < min || input > max) {
    printf("Invalid number, exiting...\n");
  } else {
    rawPrintByte(input);
  }

  // 4
  int intarr[7] = {0, 2, 4, 8, 6, 5, 3};
  for (size_t i = 0; i < 7; i++) {
    printf("%i ", intarr[i]);
  }
  printf("\n");
  sortIntArray(intarr, sizeof(intarr) / sizeof(intarr[0]));
  for (size_t i = 0; i < 7; i++) {
    printf("%i ", intarr[i]);
  }
  printf("\n");

  // 4.5
  int intarr_two[5] = {1, 13, 7, 12, 24};
  sortIntArray(intarr_two, sizeof(intarr_two) / sizeof(intarr_two[0]));
  for (size_t i = 0; i < 5; i++) {
    printf("%i ", intarr_two[i]);
  }
  printf("\n");
  int *resultArr =
      newMergeIntArray(intarr, sizeof(intarr) / sizeof(intarr[0]), intarr_two,
                       sizeof(intarr_two) / sizeof(intarr_two[0])); // 24 buffer
  int totalSize = sizeof(intarr) / sizeof(intarr[0]) +
                  sizeof(intarr_two) / sizeof(intarr_two[0]);

  for (size_t i = 0; i < totalSize; i++) {
    printf("%i ", resultArr[i]);
  }
  printf("\n");

  return 0;
}

int *newMergeIntArray(const int *_array_one, const int _size_one,
                      const int *_array_two, const int _size_two) {
  int *_temp = malloc((_size_one + _size_two) * sizeof(int));
  for (int i = 0; i < _size_one; i++) {
    _temp[i] = _array_one[i];
  }
  for (int i = 0; i < _size_two; i++) {
    _temp[_size_one + i] = _array_two[i];
  }
  sortIntArray(_temp, _size_one + _size_two);
  return _temp;
}

void sortIntArray(int *_array, int _size) {
  while (_size) {
    int loop = 0;
    for (int i = 0; i < _size - 1; i++) {
      if (_array[i] > _array[i + 1]) {
        swapIntValues(&_array[i], &_array[i + 1]);
        loop = 1;
      }
    }
    if (!loop)
      break;
  }
}

int checkStringLength(const char *_string) {
  int _index = 0;
  while (_string[_index]) {
    if (_string[_index] == '\0' || _string[_index] == '\n' ||
        _string[_index] == EOF) {
      break;
    } else {
      _index++;
    }
  }

  return _index;
}

void swapIntValues(int *a, int *b) {
  int _temp = *a;
  *a = *b;
  *b = _temp;
}

void rawPrintByte(const int _value) {
  printf("Raw binary read output:\n         ");
  int _temp = _value;
  for (size_t i = 0; i < (sizeof(char) * 8); i++) {
    printf("%i", _temp & 1);
    _temp >>= 1;
  }
  printf("\nLowest <-        -> Highest\n");
}