
#include <driver/gptimer.h>
#include <driver/ledc.h>
#include <stdio.h>
#include <unistd.h>

static constexpr int FADE{5};
static constexpr int INTERVAL{50000};

static constexpr auto LEDC_TIMER{LEDC_TIMER_0};
static constexpr auto LEDC_MODE{LEDC_LOW_SPEED_MODE};
static constexpr auto LEDC_CHANNEL{LEDC_CHANNEL_0};
static constexpr auto LEDC_DUTY_RES{LEDC_TIMER_13_BIT}; // Duty resolution
static constexpr auto LEDC_FREQUENCY{(4000)}; // PWM frequency in Hertz
#define LEDC_DUTY_PERCENT_TO_VALUE(p)                                          \
  (uint32_t)(((p) / 100.0f) * (1 << LEDC_DUTY_RES))

static int BRIGHTNESS{0};
static bool INCREMENT{true};
static bool fade_led(gptimer_handle_t timer,
                     const gptimer_alarm_event_data_t *edata, void *user_data) {
  (void)edata;
  (void)timer;
  (void)user_data;

  if (INCREMENT) {
    BRIGHTNESS += FADE;
    if (BRIGHTNESS > 100) {
      BRIGHTNESS -= FADE * 2;
      INCREMENT = false;
    }
  } else {
    BRIGHTNESS -= FADE;
    if (BRIGHTNESS < 0) {
      BRIGHTNESS += FADE * 2;
      INCREMENT = true;
    }
  }
  ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_CHANNEL,
                                LEDC_DUTY_PERCENT_TO_VALUE(BRIGHTNESS)));
  ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_CHANNEL));

  return true;
}

extern "C" void app_main() {
  ledc_timer_config_t ledc_timer = {.speed_mode = LEDC_MODE,
                                    .duty_resolution = LEDC_DUTY_RES,
                                    .timer_num = LEDC_TIMER,
                                    .freq_hz = LEDC_FREQUENCY,
                                    .clk_cfg = LEDC_AUTO_CLK};
  ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

  ledc_channel_config_t ledc_channel = {.gpio_num = GPIO_NUM_4,
                                        .speed_mode = LEDC_MODE,
                                        .channel = LEDC_CHANNEL,
                                        .intr_type = LEDC_INTR_DISABLE,
                                        .timer_sel = LEDC_TIMER};
  ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));

  gptimer_handle_t gptimer = NULL;
  gptimer_config_t timer_config = {
      .clk_src = GPTIMER_CLK_SRC_DEFAULT,
      .direction = GPTIMER_COUNT_UP,
      .resolution_hz = 1000000, // 1MHz, 1 tick = 1us
  };
  ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &gptimer));

  gptimer_event_callbacks_t cbs = {.on_alarm = fade_led};
  ESP_ERROR_CHECK(gptimer_register_event_callbacks(gptimer, &cbs, NULL));
  ESP_ERROR_CHECK(gptimer_enable(gptimer));

  gptimer_alarm_config_t alarm_config = {
      .alarm_count = INTERVAL,
      .reload_count = 0,
      .flags = {1},
  };
  ESP_ERROR_CHECK(gptimer_set_alarm_action(gptimer, &alarm_config));
  ESP_ERROR_CHECK(gptimer_start(gptimer));

  while (1) {
    usleep(500000);
    printf("500ms passed. (Not interval time)\n");
  }
}