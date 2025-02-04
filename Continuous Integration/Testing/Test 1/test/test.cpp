#include "fizzbuzz.h"
#include <unity.h>

void setUp() {}
void tearDown() {}

void test_fizz_buzz_returns_nothing(void)
{
    TEST_ASSERT_EQUAL_STRING("", fizzbuzz::check(0));
}

void test_fizz_buzz_returns_digits(void)
{
    TEST_ASSERT_EQUAL_STRING("1", fizzbuzz::check(1));
}

void test_fizz_buzz_returns_fizz(void)
{
    TEST_ASSERT_EQUAL_STRING("Fizz", fizzbuzz::check(3));
}

void test_fizz_buzz_returns_buzz(void)
{
    TEST_ASSERT_EQUAL_STRING("Buzz", fizzbuzz::check(10));
}

void test_fizz_buzz_returns_fizzbuzz(void)
{
    TEST_ASSERT_EQUAL_STRING("FizzBuzz", fizzbuzz::check(15));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_fizz_buzz_returns_nothing);
    RUN_TEST(test_fizz_buzz_returns_digits);
    RUN_TEST(test_fizz_buzz_returns_fizz);
    RUN_TEST(test_fizz_buzz_returns_buzz);
    RUN_TEST(test_fizz_buzz_returns_fizzbuzz);

    return UNITY_END();
}
