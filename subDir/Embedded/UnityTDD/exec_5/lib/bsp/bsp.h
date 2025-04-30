#ifndef BSP_H
#define BSP_H

#include <stdbool.h>

#define BSP_CONSOLE_EOF -1
#define BSP_PIN_INPUT_OUTPUT 3

int bsp_console_getchar(void);

bool bsp_console_print(const char *str);

bool bsp_pin_config(int pin, int mode);

bool bsp_pin_write(int pin, int state);

int bsp_pin_read(int pin);

#endif