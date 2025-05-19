#include "bsp.h"
#include "button.h"
#include <unity.h>

#define GPIO_PIN 4

void setUp() {}
void tearDown() {}

void test_button_init(void) {
  bsp_set_config_return(0);
  bsp_set_read_return(0);
  button_init(GPIO_PIN);
  TEST_ASSERT_EQUAL_INT(BUTTON_UNINITITIALIZED, button_get_state());

  bsp_set_read_return(0);
  for (size_t i = 0; i < 5; i++) {
    button_update_state();
  }
  TEST_ASSERT_EQUAL_INT(BUTTON_UNINITITIALIZED, button_get_state());

  bsp_set_config_return(1);
  button_init(GPIO_PIN);
  TEST_ASSERT_EQUAL(BUTTON_RELEASED, button_get_state());
}

void test_button_press() {
  bsp_set_config_return(1);
  button_init(GPIO_PIN);
  TEST_ASSERT_EQUAL_INT(BUTTON_RELEASED, button_get_state());

  bsp_set_read_return(0);
  button_update_state();
  button_update_state();
  button_update_state();
  button_update_state();
  button_update_state();
  TEST_ASSERT_EQUAL_INT(BUTTON_FALLING_EDGE, button_get_state());
  TEST_ASSERT_EQUAL_INT(BUTTON_PRESSED, button_get_state());

  bsp_set_read_return(1);
  button_update_state();
  button_update_state();
  button_update_state();
  button_update_state();
  button_update_state();
  TEST_ASSERT_EQUAL_INT(BUTTON_RISING_EDGE, button_get_state());
  TEST_ASSERT_EQUAL_INT(BUTTON_RELEASED, button_get_state());
}

void test_button_unique_event() {
  bsp_set_config_return(1);
  button_init(GPIO_PIN);
  TEST_ASSERT_EQUAL_INT(BUTTON_RELEASED, button_get_state());

  bsp_set_read_return(0);
  for (size_t i = 0; i < 5; i++) {
    button_update_state();
  }
  TEST_ASSERT_EQUAL_INT(BUTTON_FALLING_EDGE, button_get_state());
  TEST_ASSERT_EQUAL_INT(BUTTON_PRESSED, button_get_state());

  bsp_set_read_return(1);
  for (size_t i = 0; i < 5; i++) {
    button_update_state();
  }
  TEST_ASSERT_EQUAL_INT(BUTTON_RISING_EDGE, button_get_state());
  TEST_ASSERT_EQUAL_INT(BUTTON_RELEASED, button_get_state());

  // Missing an edge.
  bsp_set_read_return(0);
  for (size_t i = 0; i < 6; i++) {
    button_update_state();
  }
  TEST_ASSERT_NOT_EQUAL_INT(BUTTON_FALLING_EDGE, button_get_state());
  TEST_ASSERT_NOT_EQUAL_INT(BUTTON_RISING_EDGE, button_get_state());
  TEST_ASSERT_EQUAL_INT(BUTTON_PRESSED, button_get_state());

  bsp_set_read_return(1);
  for (size_t i = 0; i < 6; i++) {
    button_update_state();
  }
  TEST_ASSERT_NOT_EQUAL_INT(BUTTON_FALLING_EDGE, button_get_state());
  TEST_ASSERT_NOT_EQUAL_INT(BUTTON_RISING_EDGE, button_get_state());
  TEST_ASSERT_EQUAL_INT(BUTTON_RELEASED, button_get_state());
}

void test_button_bounce(void) {
  bsp_set_config_return(1);
  button_init(GPIO_PIN);
  TEST_ASSERT_EQUAL_INT(BUTTON_RELEASED, button_get_state());

  bsp_set_read_return(0);
  button_update_state();
  button_update_state();
  button_update_state();
  button_update_state();
  bsp_set_read_return(1); // bounce
  button_update_state();

  TEST_ASSERT_EQUAL_INT(BUTTON_RELEASED, button_get_state());

  bsp_set_read_return(0);
  for (size_t i = 0; i < 5; i++) {
    button_update_state();
  }
  TEST_ASSERT_EQUAL_INT(BUTTON_FALLING_EDGE, button_get_state());
  TEST_ASSERT_EQUAL_INT(BUTTON_PRESSED, button_get_state());

  bsp_set_read_return(1);
  button_update_state();
  button_update_state();
  button_update_state();
  button_update_state();
  bsp_set_read_return(0); // bounce
  button_update_state();
  button_update_state();
  button_update_state();
  button_update_state();
  TEST_ASSERT_NOT_EQUAL_INT(BUTTON_RISING_EDGE, button_get_state());
  
  TEST_ASSERT_EQUAL_INT(BUTTON_PRESSED, button_get_state());
  
  bsp_set_read_return(1);
  for (size_t i = 0; i < 5; i++) {
    button_update_state();
  }
  TEST_ASSERT_EQUAL_INT(BUTTON_RISING_EDGE, button_get_state());
  button_update_state();
  TEST_ASSERT_EQUAL_INT(BUTTON_RELEASED, button_get_state());


  bsp_set_read_return(0);
  for (size_t i = 0; i < 5; i++) {
    button_update_state();
  }
  bsp_set_read_return(1);
  for (size_t i = 0; i < 5; i++) {
    button_update_state();
  }
  TEST_ASSERT_EQUAL_INT(BUTTON_RISING_EDGE, button_get_state());
  button_update_state();
  TEST_ASSERT_EQUAL_INT(BUTTON_RELEASED, button_get_state());

}

#ifdef NO_ESP
int main()
#else
void app_main(void)
#endif
{
  UNITY_BEGIN();

  RUN_TEST(test_button_init);
  RUN_TEST(test_button_press);
  RUN_TEST(test_button_unique_event);
  RUN_TEST(test_button_bounce);

#ifdef NO_ESP
  return UNITY_END();
#else
  UNITY_END();
#endif
}