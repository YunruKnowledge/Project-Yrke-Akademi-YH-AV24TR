#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/__assert.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys_clock.h>

#define ZEPHYR_USER_NODE DT_PATH(zephyr_user)

class Metro {
  uint64_t now{0}, then{0};
  uint64_t interval;

public:
  Metro(uint64_t _interval) : interval{_interval * 1000} {};

  bool check(void) {
    bool status{false};
    now = k_ticks_to_us_floor64(k_uptime_ticks());
    if (now - then >= interval) {
      status = true;
      then = now;
    } else {
      ;
    }
    return status;
  }
};

int main(void) {
  const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(ZEPHYR_USER_NODE, led_gpios);
  __ASSERT(gpio_is_ready_dt(&led), "LED) GPIO port is not ready!");
  __ASSERT(0 == gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE),
           "LED) Failed to configure the gpio pin");

  Metro metro{500};
  Metro metro2{1000};
  while (1) {
    if (metro.check()) {
      (void)gpio_pin_set(led.port, led.pin, (!gpio_pin_get_dt(&led)));
    } else if (metro2.check()) {
      printk("Hello World.\n");
    } else {
      ;
    }
  }

  return 0;
}