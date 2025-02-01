#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

/**
 * @brief The function returns an empty string, a number, Fizz, Buzz or FizzBuzz based on num.
 *
 * @param num The number to check
 * @return char* The ouput string.
 *               An empty string if num is 0, FizzBuzz if num is divisible by 3 and 5,
 *               Buzz if the num is divisible by 5, Fuzz if the num is divisible by 3,
 *               otherwise num as a string.
 */
char *fizz_buzz(int num);

#endif
