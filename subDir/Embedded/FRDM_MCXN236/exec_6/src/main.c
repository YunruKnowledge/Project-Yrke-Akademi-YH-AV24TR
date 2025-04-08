#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys_clock.h>

#define ZEPHYR_USER_NODE DT_PATH(zephyr_user)
LOG_MODULE_REGISTER(Actuator, 4);

#define INTERVAL 250

static volatile uint64_t upTime = 0, prevUpTime = 0;
static volatile int8_t btnState = 0, prevBtnState = 0;
static const struct gpio_dt_spec button =
    GPIO_DT_SPEC_GET(ZEPHYR_USER_NODE, gate_gpios);

static void btnInterupt(const struct device *port, struct gpio_callback *cb,
                        gpio_port_pins_t pins) {
  (void)port;
  (void)pins;
  (void)cb;

  int key = irq_lock();
  upTime = k_ticks_to_us_floor64(k_uptime_ticks());
  if (upTime - prevUpTime >= (INTERVAL * 1000)) {
    btnState = !btnState;
    prevUpTime = upTime;
    LOG_DBG("BUTTON: Set state.\n");
  }
  irq_unlock(key);
}

int main(void) {
  const struct gpio_dt_spec led =
      GPIO_DT_SPEC_GET(ZEPHYR_USER_NODE, lamp_gpios);
  struct gpio_callback button_callback;

  if (0 == gpio_is_ready_dt(&led)) {
    LOG_ERR("LED: GPIO port is not ready!\n");
    exit(1);
  } else if (0 != gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE)) {
    LOG_ERR("LED: Failed to configure the gpio pin\n");
    exit(1);
  } else if (0 == gpio_is_ready_dt(&button)) {
    LOG_ERR("BUTTON: GPIO port is not ready!\n");
    exit(1);
  } else if (0 != gpio_pin_configure_dt(&button, GPIO_INPUT)) {
    LOG_ERR("BUTTON: Failed to configure the gpio pin\n");
    exit(1);
  } else if (0 != gpio_pin_interrupt_configure_dt(&button,
                                                  GPIO_INT_EDGE_TO_ACTIVE)) {
    LOG_ERR("BUTTON: Failed to configure the gpio pin interrupt\n");
    exit(1);
  } else if (0 != gpio_add_callback(button.port, &button_callback)) {
    LOG_ERR("BUTTON: Failed to add the gpio callback\n");
    exit(1);
  } else {
    LOG_DBG("All DT ready.\n");
  }

  gpio_init_callback(&button_callback, btnInterupt, BIT(button.pin));

  while (1) {
    if (btnState != prevBtnState) {
      (void)gpio_pin_interrupt_configure_dt(&button, GPIO_INT_DISABLE);
      (void)gpio_pin_set(led.port, led.pin, btnState);
      prevBtnState = btnState;
      LOG_DBG("LED: Set state.\n");
      (void)gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
    }
  }

  return 0;
}