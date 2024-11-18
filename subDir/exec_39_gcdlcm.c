/**
 * @file exec_39_gcdlcm.c
 * @author Khanh Tran (88000687+YunruKnowledge@users.noreply.github.com)
 * @brief Module including GCD, LCM and string sorter.
 * @version 1.0
 * @date 2024-11-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "exec_39_gcdlcm.h"

/**
 * @brief Least Common Multiple, the smallest positive integer that is divisible
 * by both a and b.
 *
 * @param _value_one
 * @param _value_two
 * @return 5
 */
uint_t LCM(const uint_t _value_one, const uint_t _value_two) {
  uint_t _lcm = 0;
  for (uint_t a = 0; a < sizeof(uint_t) * 8; a++) {
    if (_lcm)
      break;
    for (uint_t b = 0; b < sizeof(uint_t) * 8; b++) {
      if (_value_one * a == _value_two * b) {
        _lcm = _value_one * a;
      } else if (_value_one * a < _value_two * b) {
        break;
      }
    }
  }
  return _lcm;
}

/**
 * @brief Greatest Common Divisor Calculator, GCD(a,b) = (a * b) / LCM(a,b)
 *
 * @param _value_one
 * @param _value_two
 * @return unsigned int
 */
uint_t GCD(const uint_t _value_one, const uint_t _value_two) {
  return (_value_one * _value_two) / LCM(_value_one, _value_two);
}

/**
 * @brief Sorts a string alphbetically with special characters first.
 * ENG ASCII only. Uppercase before lowercase.
 *
 * @param _string
 * @param _size
 * @param _verbal
 */
void stringAplhaSort(char *_string, const size_t _size,
                     const short int _verbal) {
  int _continue = 1;
  int _capitalDiff = ('a' - 'A');
  while (_continue) {
    _continue = 0;

    for (size_t i = 0; i < _size - 2; i++) {
      if (_verbal)
        (void)printf("%c/%c ", _string[i], _string[i + 1]);
      // if char a is a letter
      if ((_string[i] >= 'A' && _string[i] <= 'Z') ||
          (_string[i] >= 'a' && _string[i] <= 'z')) {
        // if char b is a letter
        if (((_string[i + 1] >= 'A' && _string[i + 1] <= 'Z') ||
             (_string[i + 1] >= 'a' && _string[i + 1] <= 'z'))) {

          // if a is lowercase, *higher interger,
          if ((_string[i] >= 'a' && _string[i] <= 'z')) {

            // if b is lowercase
            if ((_string[i + 1] >= 'a' && _string[i + 1] <= 'z')) {
              // if a's lowercase ASCII is higher than b lowercase, then swap.
              // 'A' is lowest.
              if ((_string[i] - _capitalDiff) >
                  (_string[i + 1] - _capitalDiff)) {
                swap(_string, i);

                _continue = 1;
              }
            } else {
              // if a's lowercase ASCII is higher, then swap. 'A' is lowest.
              if ((_string[i] - _capitalDiff) > _string[i + 1]) {
                swap(_string, i);

                _continue = 1;
              } else if ((_string[i] - _capitalDiff) == _string[i + 1]) {
                swap(_string, i);
                _continue = 1;
              }
            }

          } else {
            // else a is uppercase
            // if a's ASCII is higher, then swap. 'A' is lowest.
            if (_string[i] > _string[i + 1]) {
              swap(_string, i);
              _continue = 1;
            }
          }

        } else {
          // else b is a special character, swap.
          swap(_string, i);
          _continue = 1;
        }

      } // no else
    }
  }

  if (_verbal)
    (void)printf("\n");
}

/**
 * @brief Swaps two chars inside a array, uses no size, becareful with index.
 *
 * @param _string
 * @param _index
 */
void swap(char *_string, const size_t _index) {
  const char _temp = _string[_index];
  _string[_index] = _string[_index + 1];
  _string[_index + 1] = _temp;
}