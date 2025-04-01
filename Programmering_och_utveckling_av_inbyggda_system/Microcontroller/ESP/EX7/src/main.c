#include <driver/ledc.h>
#include <driver/gpio.h>

#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>
#include <bootloader_random.h>
#include <stdio.h>

#include <esp_task_wdt.h>
#include <esp_log.h>
#include <esp_random.h>
#include <sys/unistd.h>

#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_MODE LEDC_LOW_SPEED_MODE
#define LEDC_DUTY_RES LEDC_TIMER_13_BIT
#define LEDC_FREQUENCY (4000)
#define LEDC_DUTY_PERCENT_TO_VALUE(p) (uint32_t)(((p) / 100.0f) * (1 << LEDC_DUTY_RES))

#define R_LEDC_CHANNEL LEDC_CHANNEL_0
#define G_LEDC_CHANNEL LEDC_CHANNEL_1
#define B_LEDC_CHANNEL LEDC_CHANNEL_2

static const char *R_TAG = "Red Diode";
static const char *G_TAG = "Green Diode";
static const char *B_TAG = "Blue Diode";

static const char *RANDOM_TAG = "Random";

static const gpio_num_t R_LED_PIN = GPIO_NUM_4;
static const gpio_num_t G_LED_PIN = GPIO_NUM_5;
static const gpio_num_t B_LED_PIN = GPIO_NUM_6;

static mbedtls_ctr_drbg_context ctx;

void led_setup(const char *TAG, gpio_num_t output, ledc_channel_t channel);

static void random_init(void);

static void random_get(uint8_t *buf, size_t len);

static int random_get_in_range(void);

void app_main(void) {
    led_setup(R_TAG, R_LED_PIN, R_LEDC_CHANNEL);
    led_setup(G_TAG, G_LED_PIN, G_LEDC_CHANNEL);
    led_setup(B_TAG, B_LED_PIN, B_LEDC_CHANNEL);

    random_init();
    uint32_t random;

    while (1) {
        random = random_get_in_range();
        ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, R_LEDC_CHANNEL, LEDC_DUTY_PERCENT_TO_VALUE(random)));
        ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, R_LEDC_CHANNEL));

        random = random_get_in_range();
        ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, G_LEDC_CHANNEL, LEDC_DUTY_PERCENT_TO_VALUE(random)));
        ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, G_LEDC_CHANNEL));

        random = random_get_in_range();
        ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, B_LEDC_CHANNEL, LEDC_DUTY_PERCENT_TO_VALUE(random)));
        ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, B_LEDC_CHANNEL));

        sleep(1);
    }
}

void led_setup(const char *TAG, gpio_num_t output, ledc_channel_t channel) {
    ESP_LOGI(TAG, "Initializing Timer Config");
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_MODE,
        .timer_num = LEDC_TIMER,
        .duty_resolution = LEDC_DUTY_RES,
        .freq_hz = LEDC_FREQUENCY,
        .clk_cfg = LEDC_AUTO_CLK,
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    ESP_LOGI(TAG, "Initializing Channel Config");
    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_MODE,
        .channel = channel,
        .timer_sel = LEDC_TIMER,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = output,
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
}

static void random_init(void) {
    ESP_LOGI(RANDOM_TAG, "Initializing Random Config");
    uint32_t seed[8];
    static mbedtls_entropy_context entropy;

    mbedtls_entropy_init(&entropy);
    mbedtls_ctr_drbg_init(&ctx);

    ESP_LOGI(RANDOM_TAG, "Initializing Random Seed");
    bootloader_random_enable();
    for (int i = 0; i < (sizeof(seed) / sizeof(seed[0])); i++) {
        seed[i] = esp_random();
    }
    bootloader_random_disable();

    assert(0 == mbedtls_ctr_drbg_seed(&ctx, mbedtls_entropy_func, &entropy, (const uint8_t *)seed, sizeof(seed)));
}

static void random_get(uint8_t *buf, size_t len) {
    assert(0 == mbedtls_ctr_drbg_random(&ctx, buf, len));
}

static int random_get_in_range(void) {
    uint8_t random_byte;
    random_get(&random_byte, sizeof(random_byte));

    return random_byte % 101;
}
