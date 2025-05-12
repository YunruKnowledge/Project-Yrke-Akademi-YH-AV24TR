#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>
#include <stdbool.h>

#define BUTTON_PRESSED (0U)
#define BUTTON_RELEASED (1U)
#define BUTTON_RISING_EDGE (2U)
#define BUTTON_FALLING_EDGE (3U)
#define BUTTON_UNINITITIALIZED (4U)

/**
 * @brief This function is used to initialize the module.
 *
 * @param pin The pin number used to connect a button.
 * @return true if the module is initialized successfully; otherwise false
 */
bool button_init(int pin);

/**
 * @brief This function is used to update the debounced state of the button.
 *        This function is called intervally by the client.
 *
 */
void button_update_state(void);

/**
 * @brief This function is used to get the debounced state of the button.
 *
 * @return int The state; BUTTON_UNINITITIALIZED if the module has not been initialized, otherwise
 *                        BUTTON_PRESSED, BUTTON_RELEASED, BUTTON_RISING_EDGE or BUTTON_FALLING_EDGE
 */
int button_get_state(void);

#endif /* BUTTON_H */