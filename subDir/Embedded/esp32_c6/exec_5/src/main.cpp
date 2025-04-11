
// #include <driver/gpio.h>
#include <driver/ledc.h>
// #include <esp_timer.h>
#include <stdio.h>
#include <unistd.h>

static constexpr int FADE{5};

static constexpr auto LEDC_TIMER{LEDC_TIMER_0};
static constexpr auto LEDC_MODE{LEDC_LOW_SPEED_MODE};
static constexpr auto LEDC_CHANNEL{LEDC_CHANNEL_0};
static constexpr auto LEDC_DUTY_RES{LEDC_TIMER_13_BIT}; // Duty resolution
static constexpr auto LEDC_FREQUENCY{(4000)}; // PWM frequency in Hertz
#define LEDC_DUTY_PERCENT_TO_VALUE(p)                                          \
  (uint32_t)(((p) / 100.0f) * (1 << LEDC_DUTY_RES))

extern "C" void app_main() {
  // Prepare and then apply the LEDC PWM timer configuration
  ledc_timer_config_t ledc_timer = {
      .speed_mode = LEDC_MODE,
      .duty_resolution = LEDC_DUTY_RES,
      .timer_num = LEDC_TIMER,
      .freq_hz = LEDC_FREQUENCY, // Set output frequency at 4 kHz
      .clk_cfg = LEDC_AUTO_CLK};
  ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

  // Prepare and then apply the LEDC PWM channel configuration
  ledc_channel_config_t ledc_channel = {.gpio_num = GPIO_NUM_4,
                                        .speed_mode = LEDC_MODE,
                                        .channel = LEDC_CHANNEL,
                                        .intr_type = LEDC_INTR_DISABLE,
                                        .timer_sel = LEDC_TIMER};
  ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));

  int brightness{0};
  bool increment{true};
  while (1) {
    if (increment) {
      brightness += FADE;
      if (brightness > 100) {
        brightness -= FADE * 2;
        increment = false;
      }
    } else {
      brightness -= FADE;
      if (brightness < 0) {
        brightness += FADE * 2;
        increment = true;
      }
    }
    ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_CHANNEL,
                                  LEDC_DUTY_PERCENT_TO_VALUE(brightness)));
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_CHANNEL));
    usleep(50000);
  }
}