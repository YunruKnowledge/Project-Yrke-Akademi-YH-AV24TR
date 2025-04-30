#include "bsp.h"
#include <stdio.h>
#include <driver/gpio.h>

int bsp_console_getchar(void)
{
    return getchar();
}

bool bsp_console_print(const char *str)
{
    return (BSP_CONSOLE_EOF != printf("%s", str));
}

bool bsp_pin_config(int pin, int mode)
{
    return (ESP_OK == gpio_reset_pin(pin)) && (ESP_OK == gpio_set_direction(pin, mode));
}

bool bsp_pin_write(int pin, int state)
{
    return (ESP_OK == gpio_set_level(pin, state));
}

int bsp_pin_read(int pin)
{
    return gpio_get_level(pin);
}