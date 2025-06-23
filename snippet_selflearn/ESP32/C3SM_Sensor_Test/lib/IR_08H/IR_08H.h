#ifndef IR_08H
#define IR_08H

#include <iostream>
#include "driver/gpio.h"
#include "esp_log.h"

namespace IR_SENSOR_08H
{
    static gpio_num_t CONFIG_GPIO_PIN = GPIO_NUM_NC;
    static gpio_config_t CONFIG;
    static const char *TAG = "IR_SENSOR_08H";

    void init(gpio_num_t _gpio_pin)
    {
        CONFIG.intr_type = GPIO_INTR_DISABLE;
        CONFIG.mode = GPIO_MODE_INPUT;
        CONFIG.pull_down_en = GPIO_PULLDOWN_DISABLE;
        CONFIG.pull_up_en = GPIO_PULLUP_ENABLE;
        CONFIG.pin_bit_mask = (1ULL << _gpio_pin);

        if (ESP_OK == gpio_config(&CONFIG))
        {
            CONFIG_GPIO_PIN = _gpio_pin;
            ESP_LOGI(TAG, "IR Sensor GPIO %d initialized as input.", _gpio_pin);
        };
    }

    int get(void)
    {
        if (CONFIG_GPIO_PIN != GPIO_NUM_NC)
        {
            int sensor_value = gpio_get_level(CONFIG_GPIO_PIN);
            return sensor_value;
        }
        else
        {
            return ESP_FAIL;
        }
    }
}

#endif