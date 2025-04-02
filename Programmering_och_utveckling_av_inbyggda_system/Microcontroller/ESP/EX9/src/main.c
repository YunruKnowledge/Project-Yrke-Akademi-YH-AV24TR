#include <stdio.h>
#include <unistd.h>

#include <driver/gpio.h>

#include <esp_log.h>
#include <esp_task_wdt.h>

#define DEBOUNCE_TIME_MS 250

static const char *TAG = "Button";
static const gpio_num_t PIN = GPIO_NUM_4;

static int interrupt = 0;

static void gpio_isr_handler(void *arg) {
    (void) arg;

    ESP_ERROR_CHECK(gpio_intr_disable(PIN));

    sleep(DEBOUNCE_TIME_MS / 1000);
    interrupt = 1;

    ESP_ERROR_CHECK(gpio_intr_enable(PIN));
}

void app_main(void) {
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

    ESP_LOGI(TAG, "Initializing GPIO");
    ESP_ERROR_CHECK(gpio_reset_pin(PIN));
    ESP_ERROR_CHECK(gpio_set_direction(PIN, GPIO_MODE_INPUT));
    ESP_ERROR_CHECK(gpio_set_pull_mode(PIN, GPIO_PULLUP_ONLY));
    ESP_ERROR_CHECK(gpio_set_intr_type(PIN, GPIO_INTR_NEGEDGE));

    ESP_ERROR_CHECK(gpio_install_isr_service(0));
    ESP_ERROR_CHECK(gpio_isr_handler_add(PIN, gpio_isr_handler, NULL));

    while (1) {
        ESP_ERROR_CHECK(gpio_intr_enable(PIN));
        if (interrupt == 1) {
            (void) printf("Falling edge\n");
            interrupt = 0;
        }
    }

    ESP_ERROR_CHECK(gpio_isr_handler_remove(PIN));
    gpio_uninstall_isr_service();
}
