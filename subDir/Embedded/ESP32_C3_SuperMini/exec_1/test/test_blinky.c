#include <unity.h>
#include <unistd.h>
#include <driver/gpio.h>

#define LOW 0
#define HIGH 1
#define DELAY 500000U
#define MAX_BLINKS 5U

void setUp(void) {}
void tearDown(void) {}

void test_led_pin_number(void)
{
    TEST_ASSERT_EQUAL(4, GPIO_NUM_4);
}

void test_led_toggle_state(void)
{
    for (int i = 0; i < MAX_BLINKS; i++)
    {
        gpio_set_level(GPIO_NUM_4, HIGH);
        TEST_ASSERT_EQUAL(HIGH, gpio_get_level(GPIO_NUM_4));
        usleep(DELAY);

        gpio_set_level(GPIO_NUM_4, LOW);
        TEST_ASSERT_EQUAL(LOW, gpio_get_level(GPIO_NUM_4));
        usleep(DELAY);
    }
}

void app_main(void)
{
    ESP_ERROR_CHECK(gpio_reset_pin(GPIO_NUM_4));

    ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_4, GPIO_MODE_INPUT_OUTPUT)); // Configure pin 4 as a digital I/O pin

    UNITY_BEGIN();

    RUN_TEST(test_led_pin_number);

    RUN_TEST(test_led_toggle_state);

    UNITY_END();
}