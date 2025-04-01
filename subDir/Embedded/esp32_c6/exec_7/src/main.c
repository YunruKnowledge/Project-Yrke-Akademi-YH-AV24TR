
#include <driver/ledc.h>
#include <stdio.h>
#include <unistd.h>

#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_MODE LEDC_LOW_SPEED_MODE

#define RED_CHANNEL LEDC_CHANNEL_0
#define GREEN_CHANNEL LEDC_CHANNEL_1
#define BLUE_CHANNEL LEDC_CHANNEL_2

#define LEDC_DUTY_RES LEDC_TIMER_13_BIT
#define LEDC_FREQUENCY (4000) // PWM frequency in Hertz
#define LEDC_DUTY_PERCENT_TO_VALUE(p)                                          \
  (uint32_t)(((p) / 100.0f) * (1 << LEDC_DUTY_RES))

void app_main(void) {
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

  ledc_channel_config_t green_channel = {.speed_mode = LEDC_MODE,
                                         .channel = GREEN_CHANNEL,
                                         .timer_sel = LEDC_TIMER,
                                         .intr_type = LEDC_INTR_DISABLE,
                                         .gpio_num = GPIO_NUM_5};

  ledc_channel_config_t blue_channel = {.speed_mode = LEDC_MODE,
                                        .channel = BLUE_CHANNEL,
                                        .timer_sel = LEDC_TIMER,
                                        .intr_type = LEDC_INTR_DISABLE,
                                        .gpio_num = GPIO_NUM_6};

  ESP_ERROR_CHECK(ledc_channel_config(&red_channel));
  ESP_ERROR_CHECK(
      ledc_set_duty(LEDC_MODE, RED_CHANNEL, LEDC_DUTY_PERCENT_TO_VALUE(33)));
  ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, RED_CHANNEL));
  printf("red\n");
  usleep(1000000);

  ESP_ERROR_CHECK(
      ledc_set_duty(LEDC_MODE, RED_CHANNEL, LEDC_DUTY_PERCENT_TO_VALUE(0)));
  ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, RED_CHANNEL));

  ESP_ERROR_CHECK(ledc_channel_config(&green_channel));
  ESP_ERROR_CHECK(
      ledc_set_duty(LEDC_MODE, GREEN_CHANNEL, LEDC_DUTY_PERCENT_TO_VALUE(33)));
  ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, GREEN_CHANNEL));
  printf("green\n");
  usleep(1000000);

  ESP_ERROR_CHECK(
      ledc_set_duty(LEDC_MODE, GREEN_CHANNEL, LEDC_DUTY_PERCENT_TO_VALUE(0)));
  ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, GREEN_CHANNEL));

  ESP_ERROR_CHECK(ledc_channel_config(&blue_channel));
  ESP_ERROR_CHECK(
      ledc_set_duty(LEDC_MODE, BLUE_CHANNEL, LEDC_DUTY_PERCENT_TO_VALUE(33)));
  ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, BLUE_CHANNEL));
  printf("blue\n");

  while (1) {
    ;
  }
}
