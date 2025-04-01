/**
 * @file main.cpp
 * @author Lazar Roksandic (roksandiclazar@gmail.com)
 * @brief EX 4 To make a Function Metro to toggle a led and to print to terminal
 * @version 0.1
 * @date 2025-03-27
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>
#include <esp_task_wdt.h>
#include <esp_timer.h>
#include <driver/ledc.h>

#define DELAY_LED 500 // ms
#define DELAY_PRINT 1000 // ms

class Metro {
    int64_t interval;
    int64_t previous_time;

public:
    Metro(int64_t _interval) : interval(_interval * 1000) {
        previous_time = esp_timer_get_time();
    }

public:
    void toggle_led(bool state) {
        ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_4, state));
    }

    void print_to_terminal(void) {
        std::cout << "Hello World!" << std::endl;
    }

    bool check_interval(void) {
        bool status{false};
        int64_t current_time{esp_timer_get_time()};

        if ((current_time - previous_time) > interval) {
            previous_time = current_time;
            status = true;
        }

        return status;
    }
};

extern "C" void app_main(void) {
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));
    ESP_ERROR_CHECK(gpio_reset_pin(GPIO_NUM_4));
    ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT));

    Metro print(DELAY_PRINT);
    Metro led(DELAY_LED);

    bool status{false};

    while (true) {
        if (led.check_interval()) {
            status = !status;
            led.toggle_led(status);
        }

        if (print.check_interval()) {
            print.print_to_terminal();
        }
    }
}
