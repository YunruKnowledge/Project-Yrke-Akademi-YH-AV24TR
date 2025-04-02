#include <stdio.h>
#include <unistd.h>

#include <driver/gpio.h>
#include <driver/ledc.h>

#include <esp_log.h>
#include <esp_check.h>
#include <esp_task_wdt.h>
#include <esp_adc/adc_cali.h>
#include <esp_adc/adc_oneshot.h>
#include <esp_adc/adc_cali_scheme.h>

#define V_IN_MAX 4095
#define V_OUT_MAX 3.3
#define V_IN_OUT_MIN 0

#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_MODE LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEL LEDC_CHANNEL_0
#define LEDC_DUTY_RES LEDC_TIMER_13_BIT
#define LEDC_FREQUENCY (4000)
#define LEDC_DUTY_PERCENT_TO_VALUE(p) (uint32_t)(((p) / 100.0f) * (1 << LEDC_DUTY_RES))

static const char *P_TAG = "Potentiometer";
static const char *L_TAG = "LED";

static const gpio_num_t POTENTIOMETER = ADC_ATTEN_DB_0;
static const gpio_num_t LED = GPIO_NUM_4;

float maped(const float x, const float in_min, const float in_max, const float out_min, const float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void app_main(void) {
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

    ESP_LOGI(P_TAG, "ADC1 Init");
    adc_oneshot_unit_handle_t adc_handler;
    adc_oneshot_unit_init_cfg_t adc_config = {
        .unit_id = ADC_UNIT_1,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&adc_config, &adc_handler));

    ESP_LOGI(P_TAG, "ADC1 Configuration");
    adc_oneshot_chan_cfg_t channel_config = {
        .bitwidth = ADC_BITWIDTH_DEFAULT,
        .atten = POTENTIOMETER,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(adc_handler, ADC_CHANNEL_0, &channel_config));

    ESP_LOGI(P_TAG, "ADC1 Calibration");
    adc_cali_handle_t calibration_handle = NULL;
    adc_cali_curve_fitting_config_t calibration_config = {
        .unit_id = ADC_UNIT_1,
        .chan = ADC_CHANNEL_0,
        .atten = POTENTIOMETER,
        .bitwidth = ADC_BITWIDTH_DEFAULT,
    };
    ESP_ERROR_CHECK(adc_cali_create_scheme_curve_fitting(&calibration_config, &calibration_handle));

    ESP_LOGI(L_TAG, "Timer Init");
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_MODE,
        .timer_num = LEDC_TIMER,
        .duty_resolution = LEDC_DUTY_RES,
        .freq_hz = LEDC_FREQUENCY,
        .clk_cfg = LEDC_AUTO_CLK,
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    ESP_LOGI(L_TAG, "Channel Config");
    ledc_channel_config_t led_channel_config = {
        .speed_mode = LEDC_MODE,
        .channel = LEDC_CHANNEL,
        .timer_sel = LEDC_TIMER,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = LED,
    };
    ESP_ERROR_CHECK(ledc_channel_config(&led_channel_config));

    int adc_raw, voltage;
    while (true) {
        ESP_ERROR_CHECK(adc_oneshot_read(adc_handler, ADC_CHANNEL_0, &adc_raw));
        ESP_ERROR_CHECK(adc_cali_raw_to_voltage(calibration_handle, adc_raw, &voltage));

        (void) printf("DEBUG: ADC RAW: %d \n", adc_raw);

        const float map = maped((float) adc_raw, V_IN_OUT_MIN, V_IN_MAX, V_IN_OUT_MIN, V_OUT_MAX);
        (void) printf("DEBUG: Mapped Voltage: %.02f \n", map);

        const int percent = ((map - V_IN_OUT_MIN) / (V_OUT_MAX - V_IN_OUT_MIN)) * 100;
        (void) printf("DEBUG: Mapped Voltage: %d \n\n", percent);

        ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, LEDC_DUTY_PERCENT_TO_VALUE(percent)));
        ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_CHANNEL));
    }
}
