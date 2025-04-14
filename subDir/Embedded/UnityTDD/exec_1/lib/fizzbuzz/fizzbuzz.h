#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <stdint.h>

#define BUFFER_LENGTH 12

/**
 * @brief Returns a special string when `_number` matches a specific order
 * comparison.
 *
 * @param _number
 * @return char*
 */
char *fizz_buzz(int _number);

/**
 * @brief Print out stats of orders.
 *
 */
void fizz_buzz_stat_print(void);

/**
 * @brief Sets stat values to zero.
 *
 */
void fizz_buzz_stat_reset(void);

/**
 * @brief Sets what string to return with what modulus comparision value.
 *
 * @param _order Starts at `1`, lowest order has priority.
 * @param _cmp_value Value to modulus with, `if (_number % _cmp_value)`
 * @param _str Max. len 12
 * @return `0` when successful, `-1` on failure.
 */
int fizz_buzz_set(uint8_t _order, int _cmp_value, const char *_str);

#endif