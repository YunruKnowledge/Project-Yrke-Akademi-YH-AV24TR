#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

#define FORMAT "YYYY-MM-DD hh:mm:ss"
#define BUFFER 20u

#define LIMIT_YEAR 9999u
#define LIMIT_MONTH 12u
#define LIMIT_DAY 31u
#define MIN_DATE 1u

enum MONTH_NAMES {
  JANUARY,
  FEBRUARY,
  MARCH,
  APRIL,
  MAY,
  JUNE,
  JULY,
  AUGUST,
  SEPTEMBER,
  OCTOBER,
  NOVEMBER,
  DECEMBER
};
#define MONTH_DAY_MODIFIER {0, -3, 0, -1, 0, -1, 0, 0, -1, 0, -1, 0}

#define LIMIT_HOUR 23u
#define LIMIT_MINUTE 59u
#define LIMIT_SECOND 59u
#define MIN_TIME 0u

int leapYearSearch(const int input) {
  int nextLeapYear = 0;
  int index = input;
  int isSameYear = 0;

  while (1) {
    if (!nextLeapYear) {
      if ((index % 4 == 0 && index % 100 != 0) || index % 400 == 0) {
        if (index == input) {
          (void)printf("Same year is leap year [%i].\n", index);
          (void)printf("(Next) ");
          isSameYear = 1;
        } else {
          (void)printf("Closest leap year is [%i].\n", index);
          nextLeapYear = index;
        }
      }
      index++;
    } else {
      index--;
      if ((index % 4 == 0 && index % 100 != 0) || index % 400 == 0) {
        if (index == nextLeapYear || index == input) {
          // skip
        } else {
          (void)printf("Previous leap year is [%i].\n", index);
          break;
        }
      }
    }
  }

  return isSameYear;
}

int main(void) {
  char _char;
  unsigned char inputString[BUFFER] = {0};
  uint8_t i = 0;
  while ((i < sizeof(inputString))) {
    _char = getchar();
    if (_char == '\n' || _char == EOF) {
      break;
    } else {
      inputString[i++] = _char;
    }
  }

  unsigned int year = 0;
  unsigned int month = 0, day = 0, hour = 0, minute = 0, second = 0;
  int8_t dayModifier[LIMIT_MONTH] = MONTH_DAY_MODIFIER;

  (void)printf(FORMAT);
  (void)printf("\n");
  (void)sscanf(inputString, "%04u-%02u-%02u %02u:%02u:%02u", &year, &month,
               &day, &hour, &minute, &second);
  // (void)printf("%u,%u,%u,%u,%u,%u\n", year, month, day, hour, minute, second); // for debugging type

  if (month - 1 == FEBRUARY) { // only run search when FEB is entered--
    if (leapYearSearch(year)) {
      dayModifier[FEBRUARY] = dayModifier[FEBRUARY] + 1;
    } else {
      // nothin -3, 28th
    }
  }

  if (year > LIMIT_YEAR || month > LIMIT_MONTH || day > LIMIT_DAY ||
      hour > LIMIT_HOUR || minute > LIMIT_MINUTE || second > LIMIT_SECOND ||
      year < MIN_DATE || month < MIN_DATE || day < MIN_DATE) {
    (void)printf("INVALID INPUT.\n");
  } else if (day > (LIMIT_DAY + dayModifier[month - 1])) {
    (void)printf(
        "Days exceeded month days. - Input: %i, Max date:%i, (Modifier [%i])\n",
        day, (LIMIT_DAY + dayModifier[month - 1]), dayModifier[month - 1]);
  } else {
    (void)printf("It was indeed valid date... and time.\n");
  }

  return 0;
}