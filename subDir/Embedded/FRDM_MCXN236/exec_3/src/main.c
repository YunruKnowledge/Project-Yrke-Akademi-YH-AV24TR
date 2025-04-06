
#include <zephyr/drivers/pwm.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(led_pwm);

#define PWM_LED_NODE DT_NODELABEL(pwm_led)
#define PWM_LED_PERIOD DT_PWMS_PERIOD(PWM_LED_NODE)
#define INTERVAL 30
static int32_t pulse_width = 0;
static int pulse_up = 1;
static const struct pwm_dt_spec pwm_led = PWM_DT_SPEC_GET(PWM_LED_NODE);

void fade(struct k_timer *dummy) {
  if (0 != pwm_set_pulse_dt(&pwm_led, pulse_width)) {
    LOG_ERR("Failed to set pulse width");
  }

  if (pulse_up) {
    pulse_width += (PWM_LED_PERIOD / 100);
    if (pulse_width > PWM_LED_PERIOD) {
      pulse_up = 0;
      pulse_width -= (PWM_LED_PERIOD / 100);
    }
  } else {
    pulse_width -= (PWM_LED_PERIOD / 100);
    if (pulse_width < 0) {
      pulse_up = 1;
      pulse_width += (PWM_LED_PERIOD / 100);
    }
  }
}

int main(void) {
  if (!pwm_is_ready_dt(&pwm_led)) {
    LOG_ERR("Error: didn't find %s device", DT_NODE_FULL_NAME(PWM_LED_NODE));
    exit(1);
  }
  struct k_timer timer;
  k_timer_init(&timer, fade, NULL);
  k_timer_start(&timer, K_MSEC(0), K_MSEC(INTERVAL));

  while (1) {
    k_sleep(K_FOREVER);
  }

  return EXIT_SUCCESS;
}
