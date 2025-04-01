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
// Drivers
#include <driver/ledc.h>
#include <driver/gptimer.h>
#include <driver/gpio.h>

// Libraries
#include <unistd.h>

// ESP Includes
#include <esp_task_wdt.h>
#include <esp_log.h>

#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_MODE LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEL LEDC_CHANNEL_0
#define LEDC_DUTY_RES LEDC_TIMER_13_BIT
#define LEDC_FREQUENCY (4000)
#define LEDC_DUTY_PERCENT_TO_VALUE(p) (uint32_t)(((p) / 100.0f) * (1 << LEDC_DUTY_RES))

#define DELAY_LED 50 // ms
#define INTERVAL 50000 // 50ms interval

#define PERCENT_FADE 5
#define MAX_FADE 100
#define MIN_FADE 0

static const char *TIMER_TAG = "Timer";
static int percent = MIN_FADE;

static bool fade_in = true;

void ledc_set_up(void);

void timer_set_up(void);

static bool timer_on_alarm(gptimer_handle_t timer, const gptimer_alarm_event_data_t *data, void *user_data);

void app_main(void) {
    timer_set_up();
    ledc_set_up();
}

void ledc_set_up(void) {
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
}

void timer_set_up(void) {
    ESP_LOGI(TIMER_TAG, "Initializing timer");
    gptimer_handle_t gptimer = NULL;
    gptimer_config_t timer_config = {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT,
        .direction = GPTIMER_COUNT_UP,
        .resolution_hz = 1000000
    };
    ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &gptimer));

    ESP_LOGI(TIMER_TAG, "Register the event handler for timer");
    gptimer_event_callbacks_t cbs = {
        .on_alarm = timer_on_alarm,
    };
    ESP_ERROR_CHECK(gptimer_register_event_callbacks(gptimer ,&cbs, NULL));

    ESP_LOGI(TIMER_TAG, "Enable timer");
    ESP_ERROR_CHECK(gptimer_enable(gptimer));

    ESP_LOGI(TIMER_TAG, "Start timer at alarm event");
    gptimer_alarm_config_t alarm_config = {
        .reload_count = 0,
        .alarm_count = INTERVAL,
        .flags.auto_reload_on_alarm = true,
    };
    ESP_ERROR_CHECK(gptimer_set_alarm_action(gptimer, &alarm_config));
    ESP_ERROR_CHECK(gptimer_start(gptimer));

    ESP_LOGI(TIMER_TAG, "Configer PIN 4 as a digital IO");
    ESP_ERROR_CHECK(gpio_reset_pin(GPIO_NUM_4));
    ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_4 , GPIO_MODE_INPUT_OUTPUT));
}

static bool timer_on_alarm(gptimer_handle_t timer, const gptimer_alarm_event_data_t *data, void *user_data) {
    (void) data;
    (void) timer;
    (void) user_data;

    // ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_4, !gpio_get_level(GPIO_NUM_4)));
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

    return true;
}
