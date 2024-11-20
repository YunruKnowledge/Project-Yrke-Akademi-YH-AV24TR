/**
 * @file zLibRunner.c
 * @author Khanh Tran (88000687+YunruKnowledge@users.noreply.github.com)
 * @brief Script file to run the module exercises.
 * @version 0.1
 * @date 2024-11-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "exec_39_gcdlcm.h"
#include <assert.h>
#include <stdio.h>

void exec39(void) {
  const uint_t _num[4] = {8, 12, 5, 7};
  (void)printf("GCD result: [%02i,%02i]=%u\n", _num[0], _num[1],
               GCD(_num[0], _num[1]));
  assert(4 == GCD(_num[0], _num[1]));
  (void)printf("LCM result: [%02i,%02i]=%u\n", _num[2], _num[3],
               LCM(_num[2], _num[3]));
  assert(35 == LCM(_num[2], _num[3]));

  char charArr[8] = "Abc_aBC";
  (void)printf("Inputted string: \"%s\"\n", charArr);
  stringAplhaSort(charArr, 8, 0);
  assert('_' == charArr[0]);
  (void)printf("  Sorted string: \"%s\"\n", charArr);
}

int main(void) {
  exec39();
  return 0;
}
