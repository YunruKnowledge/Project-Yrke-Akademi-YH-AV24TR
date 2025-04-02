
#include <driver/ledc.h>

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <esp_task_wdt.h>

#include <esp_adc/adc_cali.h>
#include <esp_adc/adc_cali_scheme.h>
#include <esp_adc/adc_oneshot.h>
#include <esp_check.h>
#include <esp_log.h>

#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_MODE LEDC_LOW_SPEED_MODE

#define RED_CHANNEL LEDC_CHANNEL_0

#define LEDC_DUTY_RES LEDC_TIMER_13_BIT
#define LEDC_FREQUENCY (4000) // PWM frequency in Hertz
#define LEDC_DUTY_PERCENT_TO_VALUE(p)                                          \
  (uint32_t)(((p) / 100.0f) * (1 << LEDC_DUTY_RES))

float floatMap(float x, float in_min, float in_max, float out_min,
               float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void app_main(void) {
  ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

  // LED
  ledc_timer_config_t ledc_timer = {.speed_mode = LEDC_MODE,
                                    .timer_num = LEDC_TIMER,
                                    .duty_resolution = LEDC_DUTY_RES,
                                    .freq_hz = LEDC_FREQUENCY,
                                    .clk_cfg = LEDC_AUTO_CLK};
  ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

  ledc_channel_config_t red_channel = {.speed_mode = LEDC_MODE,
                                       .channel = RED_CHANNEL,
                                       .timer_sel = LEDC_TIMER,
                                       .intr_type = LEDC_INTR_DISABLE,
                                       .gpio_num = GPIO_NUM_4};

  ESP_ERROR_CHECK(ledc_channel_config(&red_channel));

  adc_oneshot_unit_handle_t adc_handle;
  adc_oneshot_unit_init_cfg_t adc_config = {
      .unit_id = ADC_UNIT_1,
  };
  ESP_ERROR_CHECK(adc_oneshot_new_unit(&adc_config, &adc_handle));

  adc_oneshot_chan_cfg_t channel_config = {
      .bitwidth = ADC_BITWIDTH_12,
      .atten = ADC_ATTEN_DB_12,
  };
  ESP_ERROR_CHECK(
      adc_oneshot_config_channel(adc_handle, ADC_CHANNEL_0, &channel_config));

  adc_cali_handle_t cali_handle = NULL;
  adc_cali_curve_fitting_config_t cali_config = {
      .unit_id = ADC_UNIT_1,
      .chan = ADC_CHANNEL_0,
      .atten = ADC_ATTEN_DB_12,
      .bitwidth = ADC_BITWIDTH_12,
  };
  ESP_ERROR_CHECK(
      adc_cali_create_scheme_curve_fitting(&cali_config, &cali_handle));

  int adc_raw, voltage;
  float prev_result = 0.0f;

  while (1) {

    ESP_ERROR_CHECK(adc_oneshot_read(adc_handle, ADC_CHANNEL_0, &adc_raw));
    ESP_ERROR_CHECK(adc_cali_raw_to_voltage(cali_handle, adc_raw, &voltage));

    float result = (floatMap(adc_raw, 0, 3810, 0, 100) +
                    floatMap(voltage, 0, 3726, 0, 100)) /
                   2;
    result = roundf(result * 10.0f) / 10.0f;
    // printf("R:%4d:%5.1f|", adc_raw, floatMap(adc_raw, 0, 3810, 0, 100));
    // printf("V:%4d:%9.3f|", voltage, floatMap(voltage, 0, 3726, 0, 100));
    // printf("F:%3f\n", result);

    if ((int)result != (int)prev_result) {

      ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, RED_CHANNEL,
                                    LEDC_DUTY_PERCENT_TO_VALUE((int)result)));
      ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, RED_CHANNEL));
      printf("R:%3d\n", (int)result);

      // usleep(100000);
      prev_result = result;
    } else {
      ;
    }
  }
}
