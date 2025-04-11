#include <math.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(Poten_LED);

#define PWM_LED_NODE DT_NODELABEL(pwm_led)
#define PWM_LED_PERIOD DT_PWMS_PERIOD(PWM_LED_NODE)

float floatMap(float x, float in_min, float in_max, float out_min,
               float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main(void) {
  const struct adc_dt_spec adc_dev = ADC_DT_SPEC_GET(DT_PATH(zephyr_user));
  const struct pwm_dt_spec pwm_led = PWM_DT_SPEC_GET(PWM_LED_NODE);

  if (!adc_is_ready_dt(&adc_dev) || (0 > adc_channel_setup_dt(&adc_dev))) {
    LOG_ERR("TMP device is not ready");
    exit(EXIT_FAILURE);
  }
  if (!pwm_is_ready_dt(&pwm_led)) {
    LOG_ERR("Error: didn't find %s device", DT_NODE_FULL_NAME(PWM_LED_NODE));
    exit(EXIT_FAILURE);
  }

  int16_t value;
  int32_t millivolts;
  float percent;

  struct adc_sequence sequence = {
      .buffer = &value,
      .buffer_size = sizeof(value),
      .calibrate = true,
  };

  while (1) {
    if ((0 != adc_sequence_init_dt(&adc_dev, &sequence)) ||
        (0 != adc_read_dt(&adc_dev, &sequence))) {
      LOG_ERR("TMP ADC failed to read\n");
      exit(EXIT_FAILURE);
    }

    millivolts = value;
    if (0 > adc_raw_to_millivolts_dt(&adc_dev, &millivolts)) {
      LOG_ERR("TMP ADC failed to convert the raw value to millivolts\n");
      exit(EXIT_FAILURE);
    }

    percent = floatMap(millivolts, 0, 3300, 0, 100);
    percent = roundf(percent * 10.0f) / 10.0f;
    millivolts = (int)percent;
    int output = (PWM_LED_PERIOD / 100) * (int)percent;

    if (0 != pwm_set_pulse_dt(&pwm_led, output)) {
      LOG_ERR("Failed to set pulse width");
    }

    printf("%3d%%|PULSE:%8d\n", millivolts, output);
    k_sleep(K_MSEC(50));
  }

  return EXIT_SUCCESS;
}
