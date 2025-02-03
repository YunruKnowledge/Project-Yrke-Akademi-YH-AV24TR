#include "unity.h"
#include "fizzbuzz.h"

void setUp() {}
void tearDown() {}

void test_fizz_buzz_returns_nothing(void)
{
    TEST_ASSERT_EQUAL_STRING("", fizz_buzz(0));
}

void test_fizz_buzz_returns_digits(void)
{
    TEST_ASSERT_EQUAL_STRING("1", fizz_buzz(1));
}

void test_fizz_buzz_returns_fizz(void)
{
    TEST_ASSERT_EQUAL_STRING("Fizz", fizz_buzz(3));
}

void test_fizz_buzz_returns_buzz(void)
{
    TEST_ASSERT_EQUAL_STRING("Buzz", fizz_buzz(10));
}

void test_fizz_buzz_returns_fizzbuzz(void)
{
    TEST_ASSERT_EQUAL_STRING("FizzBuzz", fizz_buzz(15));
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
