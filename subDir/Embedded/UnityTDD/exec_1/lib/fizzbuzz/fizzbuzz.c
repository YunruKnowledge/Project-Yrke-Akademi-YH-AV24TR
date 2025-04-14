
#include "fizzbuzz.h"
#include <stdio.h>
#include <string.h>

static char string[BUFFER_LENGTH];
static char FIZZBUZZ[BUFFER_LENGTH] = "FizzBuzz";
static char FIZZ[BUFFER_LENGTH] = "Fizz";
static char BUZZ[BUFFER_LENGTH] = "Buzz";

static int ORDER_1 = 3 * 5;
static int ORDER_2 = 5;
static int ORDER_3 = 3;

static uint32_t STAT_FIZZ = 0, STAT_BUZZ = 0, STAT_FIZZBUZZ = 0, STAT_MISC = 0;

char *fizz_buzz(int _number) {
  if (_number == 0) {
    sprintf(string, "%d", _number);
  } else if (_number % ORDER_1 == 0) {
    strcpy(string, FIZZBUZZ);
    STAT_FIZZBUZZ++;
  } else if (_number % ORDER_2 == 0) {
    strcpy(string, BUZZ);
    STAT_BUZZ++;
  } else if (_number % ORDER_3 == 0) {
    strcpy(string, FIZZ);
    STAT_FIZZ++;
  } else {
    sprintf(string, "%d", _number);
    STAT_MISC++;
  }
  return string;
};

void fizz_buzz_stat_print(void) {
  printf("\nStats: %s:%d | %s:%d | %s:%d | Other:%d\n\n", FIZZ, STAT_FIZZ,
         BUZZ, STAT_BUZZ, FIZZBUZZ, STAT_FIZZBUZZ, STAT_MISC);
}

void fizz_buzz_stat_reset(void) {
  STAT_FIZZ = 0;
  STAT_BUZZ = 0;
  STAT_FIZZBUZZ = 0;
  STAT_MISC = 0;
}

int fizz_buzz_set(uint8_t _order, int _cmp_value, const char *_str) {
  int status = 0;
  if (strlen(_str) <= BUFFER_LENGTH) {
    if (_order == 1) {
      strcpy(FIZZBUZZ, _str);
      ORDER_1 = _cmp_value;
    } else if (_order == 2) {
      strcpy(BUZZ, _str);
      ORDER_2 = _cmp_value;
    } else if (_order == 3) {
      strcpy(FIZZ, _str);
      ORDER_3 = _cmp_value;
    } else {
      status = -1;
    }
  } else {
    status = -1;
  }
  return status;
}