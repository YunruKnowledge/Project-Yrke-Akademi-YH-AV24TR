/**
 * @file main.cpp
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program that prints the numbers from one to an entered number between 1 and 255 by the user.
 *             If a number is a multiple of three, print “Fizz” instead
 *             If a number is a multiple of five, print “Buzz” instead
 *             If a number is a multiple of both three and five, print “FizzBuzz” instead
 *
 *             For example; The sequence from one to twenty looks like this:
 *                 1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz
 *
 *             You should follow the TDD technique to develop the program.
 *
 *             Source: https://en.wikipedia.org/wiki/Fizz_buzz
 *
 * @version 0.1
 * @date 2021-04-11
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include "fizzbuzz.h"

constexpr int RANGE_MIN = 1;
constexpr int RANGE_MAX = 255;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid number of arguments!" << std::endl;
        exit(1);
    }

    int number = std::stoi(argv[1]);

    if ((number < RANGE_MIN) || (number > RANGE_MAX))
    {
        std::cout << "The number shall be in the range of " << RANGE_MIN << " and " << RANGE_MAX << std::endl;
        exit(1);
    }

    for (int i = 1; i <= number; i++)
    {
        std::cout << fizz_buzz(i) << "\t";
    }

    std::cout << std::endl;

    return 0;
}
