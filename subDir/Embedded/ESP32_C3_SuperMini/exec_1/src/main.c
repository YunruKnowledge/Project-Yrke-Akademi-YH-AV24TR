/**
 * @file main.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of making a LED connected to pin 4 (GPIO4) blinking every 0.5s using delays.
 *        Look at: https://docs.espressif.com/projects/esp-idf/en/latest/esp32c6/api-reference/peripherals/gpio.html
 *
 * @version 0.1
 * @date 2025-03-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <driver/gpio.h>

#define DELAY 500000 // 0.5s

void app_main(void)
{
    ESP_ERROR_CHECK(gpio_reset_pin(GPIO_NUM_4));

    ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT)); // Configure pin 4 as a digital output pin

    uint32_t state = 0;

    while (1)
    {
        state = !state;

        ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_4, state));

        usleep(DELAY);
    }
}
