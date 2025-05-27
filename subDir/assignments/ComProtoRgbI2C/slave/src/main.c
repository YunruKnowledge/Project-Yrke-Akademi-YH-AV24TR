#include <stdint.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define I2C_MSG_SIZE 1

#define I2C_NODE DT_PROP(DT_PATH(zephyr_user), i2c)
#define ADDRESS DT_PROP(DT_PATH(zephyr_user), address)

#define RED_LED_NODE DT_ALIAS(led0)
#define GREEN_LED_NODE DT_ALIAS(led1)
#define BLUE_LED_NODE DT_ALIAS(led2)

static const enum LED_STATE_CODES { CODE_OFF = 0, CODE_RED, CODE_GREEN, CODE_BLUE };

static const struct gpio_dt_spec RED_LED =
    GPIO_DT_SPEC_GET(RED_LED_NODE, gpios);

static const struct gpio_dt_spec GREEN_LED =
    GPIO_DT_SPEC_GET(GREEN_LED_NODE, gpios);

static const struct gpio_dt_spec BLUE_LED =
    GPIO_DT_SPEC_GET(BLUE_LED_NODE, gpios);

static uint8_t BUFFER[I2C_MSG_SIZE];

static int on_write_requested(struct i2c_target_config *_cfg) { return 0; }

static int on_write_received(struct i2c_target_config *_cfg, uint8_t _val) {
  uint8_t status = 0;

  if (_val == CODE_OFF) {
    if (!gpio_pin_set_dt(&RED_LED, 0) && !gpio_pin_set_dt(&GREEN_LED, 0) &&
        !gpio_pin_set_dt(&BLUE_LED, 0)) {
      status = 1;
    } else {
			;
		}

  } else if (_val == CODE_RED) {
    (void)gpio_pin_set_dt(&GREEN_LED, 0);
    (void)gpio_pin_set_dt(&BLUE_LED, 0);
    status = (gpio_pin_set_dt(&RED_LED, 1) == 0);

  } else if (_val == CODE_GREEN) {
    (void)gpio_pin_set_dt(&RED_LED, 0);
    (void)gpio_pin_set_dt(&BLUE_LED, 0);
    status = (gpio_pin_set_dt(&GREEN_LED, 1) == 0);

  } else if (_val == CODE_BLUE) {
    (void)gpio_pin_set_dt(&RED_LED, 0);
    (void)gpio_pin_set_dt(&GREEN_LED, 0);
    status = (gpio_pin_set_dt(&BLUE_LED, 1) == 0);

  } else {
    ;
  }

  BUFFER[0] = status;
  return 0;
}

static int on_read_requested(struct i2c_target_config *_cfg, uint8_t *_val) {
  *_val = BUFFER[0];
  return 0;
}

static int on_read_processed(struct i2c_target_config *_cfg, uint8_t *_val) {
  *_val = BUFFER[0];
  return 0;
}

static int on_stop(struct i2c_target_config *_cfg) { return 0; }

int main(void) {
  //  LED INIT
  if (!DT_NODE_HAS_STATUS(RED_LED_NODE, okay) ||
      !DT_NODE_HAS_STATUS(GREEN_LED_NODE, okay) ||
      !DT_NODE_HAS_STATUS(BLUE_LED_NODE, okay)) {
    printk("LED missing in devicetree.\n");
    exit(EXIT_FAILURE);
  } else {
    ;
  }

  if (!gpio_is_ready_dt(&RED_LED)) {
    printk("FATAL ERROR: Red LED GPIO port not ready!\n");
    exit(EXIT_FAILURE);
  } else if (!gpio_is_ready_dt(&GREEN_LED)) {
    printk("FATAL ERROR: Green LED GPIO port not ready!\n");
    exit(EXIT_FAILURE);
  } else if (!gpio_is_ready_dt(&BLUE_LED)) {
    printk("FATAL ERROR: Blue LED GPIO port not ready!\n");
    exit(EXIT_FAILURE);
  }

  if (gpio_pin_configure_dt(&RED_LED, GPIO_OUTPUT_INACTIVE)) {
    printk("FATAL ERROR: Failed to configure Red LED.\n");
    exit(EXIT_FAILURE);
  } else if (gpio_pin_configure_dt(&GREEN_LED, GPIO_OUTPUT_INACTIVE)) {
    printk("FATAL ERROR: Failed to configure Green LED.\n");
    exit(EXIT_FAILURE);
  } else if (gpio_pin_configure_dt(&BLUE_LED, GPIO_OUTPUT_INACTIVE)) {
    printk("FATAL ERROR: Failed to configure Blue LED.\n");
    exit(EXIT_FAILURE);
  }

  // I2C INIT
  const struct device *i2c_dev = DEVICE_DT_GET(I2C_NODE);

  if (!device_is_ready(i2c_dev)) {
    printk("FATAL ERROR: Device not ready.\n");
    exit(EXIT_FAILURE);
  }

  const struct i2c_target_callbacks callbacks = {
      .write_requested = on_write_requested,
      .read_requested = on_read_requested,
      .write_received = on_write_received,
      .read_processed = on_read_processed,
      .stop = on_stop,
  };

  struct i2c_target_config config = {
      .address = ADDRESS,
      .callbacks = &callbacks,
  };

  if (0 != i2c_target_register(i2c_dev, &config)) {
    printk("FATAL ERROR: i2c_target_register return non-zero. (Failure)\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    k_sleep(K_FOREVER);
  }

  return 0;
}
