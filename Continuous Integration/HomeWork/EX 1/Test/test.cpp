#include <cassert>
#include <iostream>
#include <unity.h>
#include <unity_internals.h>
#include "fizzbuzz.h"

void setUp(void) {}

void tearDown(void) {}

void test_fizzbuzz_null(void)
{
    TEST_ASSERT_EQUAL_STRING("", fizzBuzz(0));
}

void test_fizzbuzz_digits(void)
{
    TEST_ASSERT_EQUAL_STRING("2", fizzBuzz(2));
}

void test_fizzbuzz_fizz(void)
{
    TEST_ASSERT_EQUAL_STRING("Fizz", fizzBuzz(3));
}

void test_fizzbuzz_buzz(void)
{
    TEST_ASSERT_EQUAL_STRING("Buzz", fizzBuzz(5));
}

void test_fizzbuzz_fizzbuzz(void)
{
    TEST_ASSERT_EQUAL_STRING("FizzBuzz", fizzBuzz(15));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_fizzbuzz_null);
    RUN_TEST(test_fizzbuzz_digits);
    RUN_TEST(test_fizzbuzz_fizz);
    RUN_TEST(test_fizzbuzz_buzz);
    RUN_TEST(test_fizzbuzz_fizzbuzz);

    return UNITY_END();
}