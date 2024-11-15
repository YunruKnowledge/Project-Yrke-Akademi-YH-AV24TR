/**
 * @file luhnAlgorithm.c
 * @author Khanh Tran
 * @brief Ask and verify Social Security numbers, using only stdio.h
 * @version 1.1
 * @date 2024-11-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

#define LUHN_MODULUS 10
#define INPUT_BUFFER 11
#define BUFFER_AMOUNT_WITHOUT_CONTROL 10
#define INPUT_CONTROL_INDEX 10
#define EVEN 2
#define INVALID -1
#define IGNORE 0
#define TENTH 10
#define LAST_DECIMAL_DIGIT 9

#define FORMAT "YYMMDD-nnnC"
#define FORMAT_TOTAL 5
#define YY 99
#define YEAR_DiFFERENTIAL 30
#define FIRST_YEAR 0
#define MM 12
#define DD 31
#define FIRST_DATE 1
#define MONTH_DAY_MODIFIER                                                     \
  { 0, -3, 0, -1, 0, -1, 0, 0, -1, 0, -1, 0 }
#define MONTH_DAY_MODIFIER_BUFFER 12

#define FEBRUARY 2
#define LEAP_FEBRUARY_MODIFIER -2
#define CENTURY 100
#define LEAP 4
#define LEAP_CENTURY 400

#define TWENTY_FIRST_CENTURY 2000
#define TWENTYTH_CENTURY 1900

int charNumberToInt(const char _char);
int verifySocialString(const char *_string);
int verifyStringFormat(const char *_string);
int isLeapYear(const int _year);
int convertToFullYear(const int _year_two_digit);

/**
 * @brief Program to ask and verify a Social Security number.
 * 
 * @return int
 */
int main(void) {
  char _inputString[INPUT_BUFFER];

  (void)printf("Please enter your social security number.\n(%s)\n ", FORMAT);

  char _letter;
  unsigned int _index = 0;
  while (_index < INPUT_BUFFER && _letter != '\n' && _letter != EOF) {
    _letter = getchar();
    _inputString[_index] = _letter;
    _index++;
  }

  if (verifyStringFormat(_inputString) && verifySocialString(_inputString)) {
    (void)printf("Valid Social Security Number!\n");
  } else {
    (void)printf("This is not a valid Social Security Number.\n");
  }

  return 0;
}

/**
 * @brief Converts char number into int equivalent. Ex. '9' -> 9.
 * Non digits returns -1.
 *
 * @param _char
 * @return int
 */
int charNumberToInt(const char _char) {
  if (_char > '9' || _char < '0') {
    return INVALID;
  }
  return (_char - '0');
}

/**
 * @brief Verify Social Security number using the Luhn Algorithm.
 *
 * @param _string
 * @return int
 */
int verifySocialString(const char *_string) {
  int _total = 0, _order = 0;

  for (int i = 0; i < BUFFER_AMOUNT_WITHOUT_CONTROL; i++) {
    int _digit = charNumberToInt(_string[i]);

    // step 1, alternately multiply digits with 2 and 1.
    if (_digit == (INVALID)) {
      _digit = IGNORE;
    } else if (_order % EVEN == 0) {
      _digit *= 2;
      _order++;
    } else {
      _order++;
    }

    // step 2, sum idividual digits, even if the multiplied _digit has more than one.
    if (_digit > LAST_DECIMAL_DIGIT) {
      int _tenth = _digit / TENTH;
      int _tenthRemainder = _digit % TENTH;
      _digit = _tenth + _tenthRemainder;
    }

    _total += _digit;
  }

  // step 3, control, luhn modulus of total sum of all digits.
  int _control = (LUHN_MODULUS - (_total % LUHN_MODULUS)) % LUHN_MODULUS;

  return (charNumberToInt(_string[INPUT_CONTROL_INDEX]) == _control);
}

/**
 * @brief Verify by converting a string into integers based on format, checking
 * if it exceeds date max or min -including leap years.
 *
 * @param _string
 * @return int
 */
int verifyStringFormat(const char *_string) {
  int _year, _month, _day, _number, _control;
  const int dayModifier[MONTH_DAY_MODIFIER_BUFFER] = MONTH_DAY_MODIFIER;
  if (sscanf(_string, "%2d%2d%2d-%3d%d", &_year, &_month, &_day, &_number,
             &_control) != FORMAT_TOTAL) {
    // if string is not following format.
    return 0;
  } else if (_year > YY || _year < FIRST_YEAR || _month > MM ||
             _month < FIRST_DATE || _control > LAST_DECIMAL_DIGIT) {
    // if year or month or control exceed max or min.
    return 0;
  } else if (isLeapYear(convertToFullYear(_year))) {
    if ((_month == FEBRUARY && _day > (DD + LEAP_FEBRUARY_MODIFIER)) ||
        _day < FIRST_DATE) {
      // if leap month and exceed leap day.
      return 0;
    } else if ((_day > (DD + dayModifier[_month]) || _day < FIRST_DATE)) {
      // if exceed day max (no leap day)
      return 0;
    }
  } else if (_day > (DD + dayModifier[_month]) || _day < FIRST_DATE) {
    // if exceed day max (no leap year)
    return 0;
  }

  return 1;
}

/**
 * @brief Check if inputted year is a leap year. E.g. divisable by 4 & 400 but
 * not 100 and anything else.
 *
 * @param _year
 * @return int
 */
int isLeapYear(const int _year) {
  if ((_year % LEAP == 0 && _year % CENTURY != 0) ||
      _year % LEAP_CENTURY == 0) {
    return 1;
  } else {
    return 0;
  }
}

/**
 * @brief Converts a two digit year date into a four digits. Only 1900 between
 * 2000.
 *
 * @param _year_two_digit
 * @return int
 */
int convertToFullYear(const int _year_two_digit) {
  return (_year_two_digit >= YEAR_DiFFERENTIAL && _year_two_digit <= YY)
             ? (TWENTYTH_CENTURY + _year_two_digit)
             : (TWENTY_FIRST_CENTURY + _year_two_digit);
}