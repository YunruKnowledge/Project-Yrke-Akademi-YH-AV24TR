#include "exec_39_gcdlcm.h"
#include <assert.h>
#include <stdio.h>

void testGCD(void);
void testCharSort(void);
void testLCM(void);

int main(void) {
  (void)printf("\n***START GCD TEST***\n");
  testGCD();
  (void)printf("***END GCD TEST***\n");

  (void)printf("\n***START LCM TEST***\n");
  testLCM();
  (void)printf("***END LCM TEST***\n");

  (void)printf("\n***START CHAR_SORT TEST***\n");
  testCharSort();
  (void)printf("***END CHAR_SORT TEST***\n");

  return 0;
}

void testGCD(void) {
  const uint_t _num[2] = {8, 12};
  assert(4 == GCD(_num[0], _num[1]));
  (void)printf("GCD result: [%02i,%02i]=%u\n", _num[0], _num[1],
               GCD(_num[0], _num[1]));
}

void testLCM(void) {
  const uint_t _num[2] = {5, 7};
  assert(35 == LCM(_num[0], _num[1]));
  (void)printf("LCM result: [%02i,%02i]=%u\n", _num[0], _num[1],
               LCM(_num[0], _num[1]));
}

void testCharSort(void) {
  char charArr[8] = "Abc_aBC";
  assert('_' == charArr[3]);
  (void)printf("Unsorted: %s\n", charArr);

  stringAplhaSort(charArr, 8, 0);
  assert('_' == charArr[0]);
  (void)printf("Sorted: %s\n", charArr);
}