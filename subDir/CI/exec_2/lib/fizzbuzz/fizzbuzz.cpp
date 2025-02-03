#include <cstdio>
#include <cstring>
#include "fizzbuzz.h"

#define FIZZ "Fizz"
constexpr int FIZZ_DIV = 3;

#define BUZZ "Buzz"
constexpr int BUZZ_DIV = 5;

#define FIZZBUZZ "FizzBuzz"
constexpr int FIZZBUZZ_DIV = (FIZZ_DIV * BUZZ_DIV);

static char result[sizeof(FIZZBUZZ)];

char *fizz_buzz(int num)
{
    if (num < 1)
    {
        std::strcpy(result, "");
    }
    else if (num % FIZZBUZZ_DIV == 0)
    {
        std::strcpy(result, FIZZBUZZ);
    }
    else if (num % BUZZ_DIV == 0)
    {
        std::strcpy(result, BUZZ);
    }
    else if (num % FIZZ_DIV == 0)
    {
        std::strcpy(result, FIZZ);
    }
    else
    {
        std::sprintf(result, "%d", num);
    }

    return result;
}
