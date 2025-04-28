
#include "esp_event.h"
#include "esp_log.h"
#include "esp_sntp.h"
#include "esp_wifi.h"
#include "nvs_flash.h"

#include <driver/gpio.h>
#include <driver/i2c_slave.h>
// #include <driver/uart.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#define SLAVE I2C_NUM_0
#define PIN_SDA GPIO_NUM_6
#define PIN_SCL GPIO_NUM_7
#define ADDRESS 0x55

#define BUF_SIZE (2 * SOC_UART_FIFO_LEN)
#define STACK_SIZE (2048)
#define MSGLEN 20
#define FORMAT "YYYY-MM-DD hh:mm:ss"

static const char *TAG = "Clock";
static uint8_t buffer[BUF_SIZE];

void time_sync_notification_cb(struct timeval *tv) {
  (void)tv;
  ESP_LOGI(TAG, "Notification of a time synchronization event");
}

void initialize_sntp(void) {
  ESP_LOGI(TAG, "Initializing SNTP");
  esp_sntp_setoperatingmode(SNTP_OPMODE_POLL);
  esp_sntp_setservername(0, "pool.ntp.org");
  esp_sntp_set_time_sync_notification_cb(time_sync_notification_cb);
  esp_sntp_init();
}

void obtain_time(void) {
  initialize_sntp();
  setenv("TZ", "CET-1CEST,M3.5.0/02:00:00,M10.5.0/03:00:00", 1);
  tzset();

  time_t now = 0;
  struct tm timeinfo = {0};
  const int this_year = atoi(__DATE__ + 7) - 1900;

  while (timeinfo.tm_year < this_year) {
    (void)time(&now);
    (void)localtime_r(&now, &timeinfo);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    ESP_LOGI(TAG, "Waiting for system time to be set ...");

    // AMSDKA
    printf("pap:%s//%s\n", WIFI_PASS, WIFI_SSID);
    printf("ball:%d//%d\n", timeinfo.tm_year, this_year);
  }

  ESP_LOGI(TAG, "Time is set: %s", asctime(&timeinfo));
}

static void event_handler(void *arg, esp_event_base_t event_base,
                          int32_t event_id, void *event_data) {
  if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
    esp_wifi_connect();
  } else if (event_base == WIFI_EVENT &&
             event_id == WIFI_EVENT_STA_DISCONNECTED) {
    esp_wifi_connect();
    ESP_LOGI(TAG, "Retrying to connect to the AP");
  } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
    ESP_LOGI(TAG, "Connected to AP, start SNTP");
    obtain_time();
  }
}

void wifi_init_sta(void) {
  ESP_ERROR_CHECK(esp_netif_init());
  ESP_ERROR_CHECK(esp_event_loop_create_default());

  esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
  assert(sta_netif != NULL);

  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  ESP_ERROR_CHECK(esp_wifi_init(&cfg));

  ESP_ERROR_CHECK(esp_event_handler_instance_register(
      WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL, NULL));
  ESP_ERROR_CHECK(esp_event_handler_instance_register(
      IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL, NULL));

  wifi_config_t wifi_config = {
      .sta =
          {
              .ssid = WIFI_SSID,
              .password = WIFI_PASS,
          },
  };
  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));
  ESP_ERROR_CHECK(esp_wifi_start());

  ESP_LOGI(TAG, "wifi_init_sta finished.");
}

static bool on_request(i2c_slave_dev_handle_t i2c_slave,
                       const i2c_slave_request_event_data_t *, void *) {

  if (!strcmp((char *)buffer, FORMAT)) {
    uint32_t length;

    time_t now = time(NULL);
    char datetime[32] = {0};
    struct tm *timeinfo = localtime(&now);

    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", timeinfo);

    strcpy((char *)buffer, datetime);

    ESP_ERROR_CHECK(
        i2c_slave_write(i2c_slave, buffer, MSGLEN, (uint32_t *)&length, -1));
  };

  return true;
}

static bool on_receive(i2c_slave_dev_handle_t i2c_slave,
                       const i2c_slave_rx_done_event_data_t *evt_data, void *) {
  memcpy(buffer, evt_data->buffer,
         evt_data->length > MSGLEN ? MSGLEN : evt_data->length);

  return true;
}

void app_main(void) {
  // Time init
  esp_err_t ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES ||
      ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);

  ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
  wifi_init_sta();

  i2c_slave_config_t config = {
      .i2c_port = SLAVE,
      .sda_io_num = PIN_SDA,
      .scl_io_num = PIN_SCL,
      .clk_source = I2C_CLK_SRC_DEFAULT,
      .send_buf_depth = MSGLEN,
      .receive_buf_depth = MSGLEN,
      .slave_addr = ADDRESS,
      .addr_bit_len = I2C_ADDR_BIT_LEN_7,
  };

  i2c_slave_dev_handle_t handle;
  ESP_ERROR_CHECK(i2c_new_slave_device(&config, &handle));

  i2c_slave_event_callbacks_t callbacks = {.on_receive = on_receive,
                                           .on_request = on_request};
  i2c_slave_register_event_callbacks(handle, &callbacks, NULL);

  ESP_LOGI(TAG, "I2C Slave Initialized at address 0x%X", ADDRESS);

  while (1) {
    sleep(1);
  }
}
