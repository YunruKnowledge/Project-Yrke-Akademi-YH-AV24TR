#include "bsp.h"

static bool PIN_CONFIG_STATUS = false;
static int PIN_READ_STATUS = BSP_LOW;
static int PIN = -1;
static int MODE = -1;
static int PULL = -1;

bool bsp_pin_config(int pin, int mode, int pull) {
  PIN = pin;
  MODE = mode;
  PULL = pull;
  return PIN_CONFIG_STATUS;
}

int bsp_pin_read(int pin) {
  (void)pin;
  return PIN_READ_STATUS;
}

// Helpers
void bsp_set_config_return(bool _boolean) { PIN_CONFIG_STATUS = _boolean; }
void bsp_set_read_return(int _intBool) { PIN_READ_STATUS = _intBool; }