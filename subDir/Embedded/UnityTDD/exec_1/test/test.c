#include "fizzbuzz.h"
#include "unity.h"

void setUp() {}
void tearDown() {}

void test_fizz_buzz_returns_digits(void) {
  TEST_ASSERT_EQUAL_STRING("0", fizz_buzz(0));
  TEST_ASSERT_EQUAL_STRING("1", fizz_buzz(1));
  TEST_ASSERT_EQUAL_STRING("7", fizz_buzz(7));
}

void test_fizz_buzz_returns_fizz(void) {
  TEST_ASSERT_EQUAL_STRING("Fizz", fizz_buzz(3));
  TEST_ASSERT_EQUAL_STRING("Fizz", fizz_buzz(9));
}

void test_fizz_buzz_returns_buzz(void) {
  TEST_ASSERT_EQUAL_STRING("Buzz", fizz_buzz(10));
  TEST_ASSERT_EQUAL_STRING("Buzz", fizz_buzz(20));
}

void test_fizz_buzz_returns_fizzbuzz(void) {
  TEST_ASSERT_EQUAL_STRING("FizzBuzz", fizz_buzz(15));
  TEST_ASSERT_EQUAL_STRING("FizzBuzz", fizz_buzz(30));
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_fizz_buzz_returns_digits);
  RUN_TEST(test_fizz_buzz_returns_fizz);
  RUN_TEST(test_fizz_buzz_returns_buzz);
  RUN_TEST(test_fizz_buzz_returns_fizzbuzz);

  UNITY_END();
}
