#include <cassert>
#include <iostream>
#include "fizzbuzz.h"

void test_fizz_buzz_null(void)
{
    assert(fizzBuzz(0) == "");
    std::cout << "[Passed] test_fizz_buzz_null" << std::endl;
}

void test_fizz_buzz_digits(void)
{
    assert(fizzBuzz(2) == "2");
    std::cout << "[Passed] test_fizz_buzz_digits" << std::endl;
}

void test_fizz_buzz_fizz(void)
{
    assert(fizzBuzz(3) == "Fizz");
    std::cout << "[Passed] test_fizz_buzz_fizz" << std::endl;
}

void test_fizz_buzz_buzz(void)
{
    assert(fizzBuzz(5) == "Buzz");
    std::cout << "[Passed] test_fizz_buzz_buzz" << std::endl;
}

void test_fizz_buzz_fizzbuzz(void)
{
    assert(fizzBuzz(15) == "FizzBuzz");
    std::cout << "[Passed] test_fizz_buzz_fizzbuzz" << std::endl;
}

int main(void)
{
    test_fizz_buzz_null();
    test_fizz_buzz_digits();
    test_fizz_buzz_fizz();
    test_fizz_buzz_buzz();
    test_fizz_buzz_fizzbuzz();

    return 0;
}