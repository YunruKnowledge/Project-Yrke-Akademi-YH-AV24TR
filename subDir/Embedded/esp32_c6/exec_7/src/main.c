
#include <driver/ledc.h>
#include <stdio.h>
#include <unistd.h>

#include <bootloader_random.h>
#include <esp_random.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>

#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_MODE LEDC_LOW_SPEED_MODE

#define RED_CHANNEL LEDC_CHANNEL_0
#define GREEN_CHANNEL LEDC_CHANNEL_1
#define BLUE_CHANNEL LEDC_CHANNEL_2

#define LEDC_DUTY_RES LEDC_TIMER_13_BIT
#define LEDC_FREQUENCY (4000) // PWM frequency in Hertz
#define LEDC_DUTY_PERCENT_TO_VALUE(p)                                          \
  (uint32_t)(((p) / 100.0f) * (1 << LEDC_DUTY_RES))

static mbedtls_ctr_drbg_context ctr_drbg;
static void random_init(void) {
  uint32_t seed[8];
  static mbedtls_entropy_context entropy;

  mbedtls_entropy_init(&entropy);
  mbedtls_ctr_drbg_init(&ctr_drbg);

  bootloader_random_enable();
  for (size_t i = 0; i < sizeof(seed) / sizeof(seed[0]); i++) {
    seed[i] = esp_random();
  }
  bootloader_random_disable();

  assert(0 == mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy,
                                    (const uint8_t *)seed, sizeof(seed)));
}
static void random_get(uint8_t *buf, size_t len) {
  assert(0 == mbedtls_ctr_drbg_random(&ctr_drbg, buf, len));
}

void app_main(void) {

  // RAND
  random_init();
  uint32_t rand_value;

  // LED
  ledc_timer_config_t ledc_timer = {.speed_mode = LEDC_MODE,
                                    .timer_num = LEDC_TIMER,
                                    .duty_resolution = LEDC_DUTY_RES,
                                    .freq_hz = LEDC_FREQUENCY,
                                    .clk_cfg = LEDC_AUTO_CLK};
  ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

  ledc_channel_config_t red_channel = {.speed_mode = LEDC_MODE,
                                       .channel = RED_CHANNEL,
                                       .timer_sel = LEDC_TIMER,
                                       .intr_type = LEDC_INTR_DISABLE,
                                       .gpio_num = GPIO_NUM_4};

  ledc_channel_config_t green_channel = {.speed_mode = LEDC_MODE,
                                         .channel = GREEN_CHANNEL,
                                         .timer_sel = LEDC_TIMER,
                                         .intr_type = LEDC_INTR_DISABLE,
                                         .gpio_num = GPIO_NUM_5};

  ledc_channel_config_t blue_channel = {.speed_mode = LEDC_MODE,
                                        .channel = BLUE_CHANNEL,
                                        .timer_sel = LEDC_TIMER,
                                        .intr_type = LEDC_INTR_DISABLE,
                                        .gpio_num = GPIO_NUM_6};

  ESP_ERROR_CHECK(ledc_channel_config(&red_channel));
  ESP_ERROR_CHECK(ledc_channel_config(&green_channel));
  ESP_ERROR_CHECK(ledc_channel_config(&blue_channel));

  while (1) {
    random_get((uint8_t *)&rand_value, sizeof(rand_value));
    ESP_ERROR_CHECK(ledc_set_duty(
        LEDC_MODE, RED_CHANNEL, LEDC_DUTY_PERCENT_TO_VALUE(rand_value % 100)));
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, RED_CHANNEL));
    printf("R:%3ld|", rand_value % 100);

    random_get((uint8_t *)&rand_value, sizeof(rand_value));
    ESP_ERROR_CHECK(
        ledc_set_duty(LEDC_MODE, GREEN_CHANNEL,
                      LEDC_DUTY_PERCENT_TO_VALUE(rand_value % 100)));
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, GREEN_CHANNEL));
    printf("G:%3ld|", rand_value % 100);

    random_get((uint8_t *)&rand_value, sizeof(rand_value));
    ESP_ERROR_CHECK(ledc_set_duty(
        LEDC_MODE, BLUE_CHANNEL, LEDC_DUTY_PERCENT_TO_VALUE(rand_value % 100)));
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, BLUE_CHANNEL));
    printf("B:%3ld\n", rand_value % 100);

    usleep(1000000);
  }
}
