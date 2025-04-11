
#include <driver/gpio.h>
#include <esp_task_wdt.h>
#include <esp_timer.h>
#include <stdio.h>

#define GAP 250

class Metro {
  volatile int64_t currentTime{esp_timer_get_time()};
  volatile int64_t previousTime{currentTime};
  volatile int64_t gap{1000};

public:
  Metro(int64_t _interval_ms) : gap{_interval_ms * 1000} {}

  bool check(void) volatile {
    ESP_ERROR_CHECK(gpio_intr_disable(GPIO_NUM_4));
    currentTime = esp_timer_get_time();
    bool status{false};
    if (currentTime - previousTime >= gap) {
      previousTime = currentTime;
      status = true;
    }
    ESP_ERROR_CHECK(gpio_intr_enable(GPIO_NUM_4));
    return status;
  }
};

static volatile uint32_t count = 0;
static volatile Metro countTimer{GAP};

static void gpio_isr_handler(void *arg) {
  (void)arg;
  if (countTimer.check()) {
    ESP_ERROR_CHECK(gpio_intr_disable(GPIO_NUM_4));
    count += 1;
    ESP_ERROR_CHECK(gpio_intr_enable(GPIO_NUM_4));
  } else {
    ;
  }
}

extern "C" void app_main(void) {
  ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

  ESP_ERROR_CHECK(gpio_reset_pin(GPIO_NUM_4));
  ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_4, GPIO_MODE_INPUT));
  ESP_ERROR_CHECK(gpio_set_pull_mode(GPIO_NUM_4, GPIO_PULLUP_ONLY));
  ESP_ERROR_CHECK(gpio_set_intr_type(GPIO_NUM_4, GPIO_INTR_NEGEDGE));

  ESP_ERROR_CHECK(gpio_install_isr_service(0));

  ESP_ERROR_CHECK(gpio_isr_handler_add(GPIO_NUM_4, gpio_isr_handler, NULL));

  uint32_t prev_count = count;

  while (1) {
    if (prev_count != count) {

      printf("[%ld]:Fallin' Edge\n", count);
      prev_count = count;
    }
  }

  ESP_ERROR_CHECK(gpio_isr_handler_remove(GPIO_NUM_4));
  gpio_uninstall_isr_service();
}
