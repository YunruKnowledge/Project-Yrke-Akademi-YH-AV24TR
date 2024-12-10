

#ifndef MODULE_EX241119_STRING
#define MODULE_EX241119_STRING
#include <stdio.h>

/**
 * @brief Gives length of string without null terminator.
 *
 * @return unsigned int
 */
unsigned int giveLength(const char *_string);

/**
 * @brief Checks if two strings are the same,
 * length of `_string_first` is prioritized.
 *
 * @param _string_first
 * @param _string_second
 * @return unsigned int - 1 if true and 0 if false.
 */
unsigned int stringCompare(const char *_string_first,
                           const char *_string_second);

#endif