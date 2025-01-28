#include "fizzbuzz.h"
#include <cstdio>
#include <cstring>

constexpr int FIZZ_DIVISOR{3};
#define FIZZ "Fizz"

constexpr int BUZZ_DIVISOR{5};
#define BUZZ "Buzz"

constexpr int FIZZBUZZ_DIVISOR{FIZZ_DIVISOR * BUZZ_DIVISOR};
#define FIZZBUZZ "FizzBuzz"

static char output[sizeof(FIZZBUZZ)];

const char *fizzBuzz(int num)
{
    if (num < 1)
    {
        std::strcpy(output, "");
    }
    else if (num % FIZZBUZZ_DIVISOR == 0)
    {
        std::strcpy(output, FIZZBUZZ);
    }
    else if (num % FIZZ_DIVISOR == 0)
    {
        std::strcpy(output, FIZZ);
    }
    else if (num % BUZZ_DIVISOR == 0)
    {
        std::strcpy(output, BUZZ);
    }
    else
    {
        std::sprintf(output, "%d", num);
    }

    return output;
}