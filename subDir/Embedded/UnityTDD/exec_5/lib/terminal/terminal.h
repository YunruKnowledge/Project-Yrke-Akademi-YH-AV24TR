#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdbool.h>

#define TERMINAL_LED_PIN 4
#define TERMINAL_LED_ON '1'
#define TERMINAL_LED_OFF '0'

#define TERMINAL_DONE_MSG " => done\n"
#define TERMINAL_FAILED_MSG " => failed\n"
#define TERMINAL_COMMAND_MSG "Enter a command [0: Off, 1: On]: "

bool terminal_init(void);

bool terminal_run(void);

#endif