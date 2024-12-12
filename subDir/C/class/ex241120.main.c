#include "ex241120.h"
#include <assert.h>
#include <stdio.h>

#define BUFF 5

void testCheck(const int *_int_array, const int _size, const int _bool);
void testRead(const int *_int_array, const int _size);
void readInt(const int *_int_array, const int _size);

int main(void) {
  int intArr[BUFF] = {1, 4, 2, 5, 3};

  // read
  (void)printf("Current input: ");
  readInt(intArr, BUFF);

  // check
  (void)printf("\n***CHECK TEST START***\n");
  testCheck(intArr, BUFF, 0);
  (void)printf("Check returned: %i\n", intArrayCheck(intArr, BUFF));
  (void)printf("***CHECK TEST END  ***\n");

  // sort & read
  intSorterASC(intArr, BUFF);
  (void)printf("\n***SORT TEST START***\n");
  testRead(intArr, BUFF);
  (void)printf("***SORT TEST END  ***\n");

  // check
  (void)printf("\n***CHECK TEST START***\n");
  testCheck(intArr, BUFF, 1);
  (void)printf("Check returned: %i\n", intArrayCheck(intArr, BUFF));
  (void)printf("***CHECK TEST END  ***\n");

  return 0;
}

void readInt(const int *_int_array, const int _size) {
  for (int i = 0; i < _size; i++) {
    (void)printf("%i", _int_array[i]);
    if (i < _size - 1) {
      (void)printf(", ");
    } else {
      (void)printf("\n");
    }
  }
}

void testRead(const int *_int_array, const int _size) {
  for (int i = 0; i < _size; i++) {
    assert((i + 1) == _int_array[i]);

    (void)printf("%i", _int_array[i]);
    if (i < _size - 1) {
      (void)printf(", ");
    } else {
      (void)printf("\n");
    }
  }
}

void testCheck(const int *_int_array, const int _size, const int _bool) {
  assert(_bool == intArrayCheck(_int_array, _size));
}