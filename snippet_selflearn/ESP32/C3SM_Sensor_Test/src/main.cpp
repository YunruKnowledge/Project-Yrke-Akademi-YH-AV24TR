#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

// Define the GPIO pin connected to the IR sensor's OUT pin
#define IR_SENSOR_PIN GPIO_NUM_4

// Tag for logging
static const char *TAG = "IR_SENSOR";

extern "C" void app_main(void)
{
    ESP_LOGI(TAG, "Initializing IR Sensor example...");

    // --- 1. Configure the GPIO pin --- 
    gpio_config_t io_conf;
    // Pin bit mask to specify which pin to configure
    io_conf.pin_bit_mask = (1ULL << IR_SENSOR_PIN);
    // Set as Input
    io_conf.mode = GPIO_MODE_INPUT;
    // Enable the internal pull-up resistor
    // The IR-08H is active-low, so when no object is detected, its output is HIGH.
    // The pull-up ensures a stable HIGH state and prevents the pin from floating.
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    // Disable the pull-down resistor
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    // Disable interrupts for this simple polling example
    io_conf.intr_type = GPIO_INTR_DISABLE;

    // Apply the configuration
    gpio_config(&io_conf);

    ESP_LOGI(TAG, "GPIO configuration complete. Starting loop.");

    // --- 2. Main loop to read the sensor ---
    while (1) {
        // Read the level of the GPIO pin
        int level = gpio_get_level(IR_SENSOR_PIN);

        // The sensor output is LOW when an object is detected
        if (level == 0) {
            ESP_LOGI(TAG, "Object DETECTED!");
        } else {
            ESP_LOGI(TAG, "No object............");
        }

        // Wait for 500 milliseconds before reading again
        vTaskDelay(24 / portTICK_PERIOD_MS);
    }
}