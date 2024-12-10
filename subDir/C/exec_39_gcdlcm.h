
#ifndef MODULE_EXEC_39_STRINGGCDLCM
#define MODULE_EXEC_39_STRINGGCDLCM

#include <stdio.h>
typedef unsigned int uint_t;

/**
 * @brief Least Common Multiple, the smallest positive integer that is divisible
 * by both a and b.
 *
 * @param _value_one
 * @param _value_two
 * @return unsigned int
 */
uint_t LCM(const uint_t _value_one, const uint_t _value_two);

/**
 * @brief Greatest Common Divisor Calculator, GCD(a,b) = (a * b) / LCM(a,b)
 *
 * @param _value_one
 * @param _value_two
 * @return unsigned int
 */
uint_t GCD(const uint_t _value_one, const uint_t _value_two);

/**
 * @brief Sorts a string alphbetically with special characters first.
 * ENG ASCII only. Uppercase before lowercase.
 *
 * @param _string
 * @param _size
 * @param _verbal
 */
void stringAplhaSort(char *_string, const size_t _size,
                     const short int _verbal);

#endif