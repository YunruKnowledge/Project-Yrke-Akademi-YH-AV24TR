#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdbool.h>

/**
 * @brief This function is used to initialize the driver.
 *
 * @param _pin The pin number used by the LED
 * @return bool true if the pin is initialized successfully; otherwise false.
 */
bool led_driver_init(int pin);

/**
 * @brief This function is used to change the state of the LED.
 *
 * @param state The set state. It can be 0 or 1.
 * @return bool true if state is set successfully; otherwise false.
 */
bool led_driver_set_state(int state);

#endif