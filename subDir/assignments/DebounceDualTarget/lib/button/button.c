#include "button.h"
#include "bsp.h"

#define SAMPLES (5U)

static int CURRENT_PIN = -1;
static uint8_t SAMPLE_SUCCESS_COUNT = 0;
static int CURRENT_PIN_STATE = -1;
static int NEW_PIN_STATE = -1;
static int BUTTON_STATUS = BUTTON_UNINITITIALIZED;

bool button_init(int pin) {
  bool status = false;

  status = bsp_pin_config(pin, BSP_MODE_INPUT, BSP_PULL_UP);
  CURRENT_PIN = pin;
  CURRENT_PIN_STATE = BUTTON_RELEASED;
  NEW_PIN_STATE = CURRENT_PIN_STATE;

  if (status) {
    BUTTON_STATUS = BUTTON_RELEASED;
  } else {
    BUTTON_STATUS = BUTTON_UNINITITIALIZED;
    CURRENT_PIN_STATE = -1;
  }

  return status;
}

void button_update_state(void) {
  if (CURRENT_PIN_STATE != -1) {
    NEW_PIN_STATE = bsp_pin_read(CURRENT_PIN);

    if (BUTTON_STATUS == BUTTON_FALLING_EDGE) {
      BUTTON_STATUS = BUTTON_PRESSED;
    } else if (BUTTON_STATUS == BUTTON_RISING_EDGE) {
      BUTTON_STATUS = BUTTON_RELEASED;
    } else {
      ;
    }

    if (NEW_PIN_STATE != CURRENT_PIN_STATE) {
      SAMPLE_SUCCESS_COUNT++;
    } else {
      SAMPLE_SUCCESS_COUNT = 0;
    }

    if (SAMPLE_SUCCESS_COUNT >= SAMPLES) {
      SAMPLE_SUCCESS_COUNT = 0;
      CURRENT_PIN_STATE = NEW_PIN_STATE;

      if (NEW_PIN_STATE == BUTTON_PRESSED) {
        BUTTON_STATUS = BUTTON_FALLING_EDGE;
      } else {
        BUTTON_STATUS = BUTTON_RISING_EDGE;
      }
    }
  }
}

int button_get_state(void) {
  int temp = BUTTON_STATUS;

  if (BUTTON_STATUS == BUTTON_FALLING_EDGE) {
    BUTTON_STATUS = BUTTON_PRESSED;
  } else if (BUTTON_STATUS == BUTTON_RISING_EDGE) {
    BUTTON_STATUS = BUTTON_RELEASED;
  }

  return temp;
}