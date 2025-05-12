#ifndef BSP_H
#define BSP_H

#include <stdint.h>
#include <stdbool.h>

#define BSP_LOW 0
#define BSP_HIGH 1
#define BSP_PULL_UP 0
#define BSP_MODE_INPUT 1

bool bsp_pin_config(int pin, int mode, int pull);

int bsp_pin_read(int pin);

#endif /* BSP_H */
