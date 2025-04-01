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
#include <driver/ledc.h>
#include <unistd.h>
#include <esp_task_wdt.h>

#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_MODE LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEL LEDC_CHANNEL_0
#define LEDC_DUTY_RES LEDC_TIMER_13_BIT
#define LEDC_FREQUENCY (4000)
#define LEDC_DUTY_PERCENT_TO_VALUE(p) (uint32_t)(((p) / 100.0f) * (1 << LEDC_DUTY_RES))

#define DELAY_LED 50 // ms
#define PERCENT_FADE 5
#define MAX_FADE 100
#define MIN_FADE 0

void app_main(void) {
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_MODE,
        .timer_num = LEDC_TIMER,
        .duty_resolution = LEDC_DUTY_RES,
        .freq_hz = LEDC_FREQUENCY,
        .clk_cfg = LEDC_AUTO_CLK
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_MODE,
        .channel = LEDC_CHANNEL,
        .timer_sel = LEDC_TIMER,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = GPIO_NUM_4
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));

    int percent = 0;
    bool fade_in = true;
    while (true) {
        if (percent == MAX_FADE) {
            fade_in = false;
        } else if (percent == MIN_FADE) {
            fade_in = true;
        } else {
            ;
        }

        if (fade_in) {
            percent += PERCENT_FADE;
        } else {
            percent -= PERCENT_FADE;
        }

        ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, LEDC_DUTY_PERCENT_TO_VALUE(percent)));
        ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_CHANNEL));

        usleep(DELAY_LED * 1000);
    }
}
