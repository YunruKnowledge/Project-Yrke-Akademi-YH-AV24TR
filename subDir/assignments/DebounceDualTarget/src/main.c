#include "button.h"
#include <driver/gpio.h>
#include <driver/gptimer.h>
#include <esp_task_wdt.h>
#include <stdio.h>

#define INTERVAL 10000

static uint32_t temp = 0;

static bool timer_on_alarm(gptimer_handle_t timer,
                           const gptimer_alarm_event_data_t *edata,
                           void *user_data) {
  (void)edata;
  (void)timer;
  (void)user_data;

  temp++;
  button_update_state();

  return true;
}

void app_main(void) {
  assert(button_init(GPIO_NUM_4));

  // Exclude the Idle Task from the Task WDT
  ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

  // Config and start a gptimer to run button_update_state every 10ms
  gptimer_handle_t gptimer = NULL;
  gptimer_config_t timer_config = {
      .clk_src = GPTIMER_CLK_SRC_DEFAULT,
      .direction = GPTIMER_COUNT_UP,
      .resolution_hz = 1000000,
  };
  ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &gptimer));

  gptimer_event_callbacks_t cbs = {
      .on_alarm = timer_on_alarm,
  };
  ESP_ERROR_CHECK(gptimer_register_event_callbacks(gptimer, &cbs, NULL));
  ESP_ERROR_CHECK(gptimer_enable(gptimer));

  gptimer_alarm_config_t alarm_config = {
      .reload_count = 0,
      .alarm_count = INTERVAL,
      .flags.auto_reload_on_alarm = true,
  };
  ESP_ERROR_CHECK(gptimer_set_alarm_action(gptimer, &alarm_config));
  ESP_ERROR_CHECK(gptimer_start(gptimer));

  while (1) {
    if (BUTTON_FALLING_EDGE == button_get_state()) {
      printf("Falling Edge\n");
    }
  }
}
