#include "fizzbuzz.h"
#include <string>

constexpr int FIZZ_DIVISOR{3};
#define FIZZ "Fizz"

constexpr int BUZZ_DIVISOR{5};
#define BUZZ "Buzz"

constexpr int FIZZBUZZ_DIVISOR{FIZZ_DIVISOR * BUZZ_DIVISOR};
#define FIZZBUZZ "FizzBuzz"

static std::string output;

const std::string fizzBuzz(int num)
{
    if (num < 1)
    {
        output = "";
    }
    else if (num % FIZZBUZZ_DIVISOR == 0)
    {
        output = FIZZBUZZ;
    }
    else if (num % FIZZ_DIVISOR == 0)
    {
        output = FIZZ;
    }
    else if (num % BUZZ_DIVISOR == 0)
    {
        output = BUZZ;
    }
    else
    {
        output = std::to_string(num);
    }

    return output;
}