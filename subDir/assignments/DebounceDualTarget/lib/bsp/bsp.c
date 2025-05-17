#include "bsp.h"
#include <driver/gpio.h>

bool bsp_pin_config(int pin, int mode, int pull)
{
    return (ESP_OK == gpio_reset_pin((gpio_num_t)pin)) &&
           (ESP_OK == gpio_set_direction((gpio_num_t)pin, (gpio_mode_t)mode)) &&
           (ESP_OK == gpio_set_pull_mode((gpio_num_t)pin, (gpio_pull_mode_t)pull));
}

int bsp_pin_read(int pin)
{
    return gpio_get_level((gpio_num_t)pin);
}