
#include <driver/gpio.h>
#include <esp_task_wdt.h>
#include <stdio.h>
#include <stdlib.h>

void app_main() {
  ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));
  ESP_ERROR_CHECK(gpio_reset_pin(GPIO_NUM_8));
  ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_8, GPIO_MODE_OUTPUT));

  ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_8, 0));
  uint8_t isPowered = 1;
  while (1) {
    if (isPowered) {
      ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_8, 1));
      isPowered = 0;
    }else {
      ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_8, 0));
      isPowered = 1;
    }
    vTaskDelay(pdMS_TO_TICKS(50));
  }
}