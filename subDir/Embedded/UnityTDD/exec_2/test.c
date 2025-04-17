#include "strintergers.h"
#include "unity.h"

void setUp() {}
void tearDown() {}

void test_valid(void) {
  TEST_ASSERT_EQUAL_INT(24, strnum("24"));
  TEST_ASSERT_EQUAL_INT(49218409, strnum("49218409"));
  TEST_ASSERT_EQUAL_INT(-24, strnum("-24"));
  TEST_ASSERT_EQUAL_INT(0, strnum("0"));
  
  TEST_ASSERT_EQUAL_INT(-24, strnum("-24 aw2"));
  TEST_ASSERT_EQUAL_INT(22, strnum(" 22 a"));
}

void test_invalid(void) {
  TEST_ASSERT_EQUAL_INT(0, strnum("a"));
  TEST_ASSERT_EQUAL_INT(0, strnum("a"));
  TEST_ASSERT_EQUAL_INT(22, strnum(" 22a"));
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_valid);
  RUN_TEST(test_invalid);

  UNITY_END();
}
