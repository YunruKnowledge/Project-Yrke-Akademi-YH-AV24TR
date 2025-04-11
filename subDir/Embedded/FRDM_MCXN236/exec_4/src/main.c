
#include <zephyr/drivers/pwm.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys_clock.h>

LOG_MODULE_REGISTER(led_pwm);

#define PWM_RED_NODE DT_NODELABEL(pwm_red)
#define PWM_RED_PERIOD DT_PWMS_PERIOD(PWM_RED_NODE)
#define PWM_GREEN_NODE DT_NODELABEL(pwm_green)
#define PWM_GREEN_PERIOD DT_PWMS_PERIOD(PWM_GREEN_NODE)
#define PWM_BLUE_NODE DT_NODELABEL(pwm_blue)
#define PWM_bLUE_PERIOD DT_PWMS_PERIOD(PWM_BLUE_NODE)

#define INTERVAL 30

int main(void) {
  const struct pwm_dt_spec pwm_red = PWM_DT_SPEC_GET(PWM_RED_NODE);
  const struct pwm_dt_spec pwm_green = PWM_DT_SPEC_GET(PWM_GREEN_NODE);
  const struct pwm_dt_spec pwm_blue = PWM_DT_SPEC_GET(PWM_BLUE_NODE);
  int32_t pulse_red = 0, pulse_green = 0, pulse_blue = 0;

  if (!pwm_is_ready_dt(&pwm_red) || !pwm_is_ready_dt(&pwm_green) ||
      !pwm_is_ready_dt(&pwm_blue)) {
    LOG_ERR("Error: didn't find one the the RGB device(s)");
    exit(1);
  }
  srand((uint32_t)k_uptime_ticks());

  while (1) {
    pulse_red = (rand() % 100) * (PWM_RED_PERIOD / 100);
    pulse_green = (rand() % 100) * (PWM_RED_PERIOD / 100);
    pulse_blue = (rand() % 100) * (PWM_RED_PERIOD / 100);

    if (0 != pwm_set_pulse_dt(&pwm_red, pulse_red) ||
        0 != pwm_set_pulse_dt(&pwm_green, pulse_green) ||
        0 != pwm_set_pulse_dt(&pwm_blue, pulse_blue)) {
      LOG_ERR("Failed to set pulse width");
    }

    k_sleep(K_MSEC(250));
  }

  return EXIT_SUCCESS;
}
