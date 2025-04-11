
#include <driver/gpio.h>
#include <esp_task_wdt.h>
#include <esp_timer.h>
#include <stdio.h>

class Metro {
  int64_t currentTime{esp_timer_get_time()};
  int64_t previousTime{currentTime};
  volatile int64_t gap{1000000};

public:
  Metro(int64_t _interval_ms) : gap{_interval_ms * 1000} {}

  bool check(void) {
    currentTime = esp_timer_get_time();
    bool status{false};
    if (currentTime - previousTime >= gap) {
      previousTime = currentTime;
      status = true;
    }
    return status;
  }
};

extern "C" void app_main() {
  ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));
  ESP_ERROR_CHECK(gpio_reset_pin(GPIO_NUM_4));
  ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_4, GPIO_MODE_INPUT_OUTPUT));
  Metro metro1{500};
  Metro metro2{1000};
  while (1) {
    if (metro1.check()) {
      ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_4, !gpio_get_level(GPIO_NUM_4)));
    } else if (metro2.check()) {
      printf("Hello World.\n");
    } else {
      ;
    }
  }
}