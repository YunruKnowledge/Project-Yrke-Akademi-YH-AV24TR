#include <stdio.h>

#define FORMAT "YYMMDD-nnnC"
#define SOCIAL_DIGIT_AMOUNT 10
#define INPUT_BUFFER 11
#define BUFFER_AMOUNT_WITHOUT_CONTROL 10
#define EVEN 2
#define INVALID -1
#define RESET 0
#define LAST_DECIMAL_DIGIT 9

#define LIMIT_YEAR 9999u
#define LIMIT_MONTH 12u
#define LIMIT_DAY 31u
#define FIRST_DATE 1u
enum MONTH_NAMES {
  JANUARY = 1,
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
#define MONTH_DAY_MODIFIER                                                     \
  { 0, -3, 0, -1, 0, -1, 0, 0, -1, 0, -1, 0 }

int charNumberToInt(const char _char);
int verifySocialString(const char *_string);

/**
 * @brief Program to ask and verify a Social Security number.
 *
 * @return int
 */
int main(void) {
  char _inputString[INPUT_BUFFER];

  char _letter;
  unsigned int _index = 0;
  while (_index < INPUT_BUFFER) {
    _letter = getchar();
    _inputString[_index] = _letter;
    // printf("%c - %i - %i\n", _letter, charNumberToInt(_letter),
    //        _inputIntArray[_index]);
    _index++;
  }

  // ***verify format l8r

  if (verifySocialString(_inputString)) {
    printf("Valid Social Security Number!");
  } else {
    printf("This is not a valid Social Security Number.");
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
 * @brief Verify Social Security Number using the Luhn Algorithm provided by
 * PDF.
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
      _digit = RESET; // skip, and set zero.
    } else if (_order % EVEN == 0) {
      _digit *= 2;
      _order++;
    } else {
      // * 1 is same result
      _order++;
    }

    // step 2, sum idividual digits if _digit is more than one.
    if (_digit > LAST_DECIMAL_DIGIT) {
      int _tenth = _digit / 10;
      int _tenthRemainder = _digit % 10;
      _digit = _tenth + _tenthRemainder;
    }

    // step 3, sum into total.
    _total += _digit;
  }

  // step 4, control - compare with C in format.
  int _control = (SOCIAL_DIGIT_AMOUNT - (_total % SOCIAL_DIGIT_AMOUNT)) %
                 SOCIAL_DIGIT_AMOUNT;

  return (charNumberToInt(_string[SOCIAL_DIGIT_AMOUNT]) == _control);
}