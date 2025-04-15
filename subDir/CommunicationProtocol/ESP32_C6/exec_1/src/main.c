
#include "esp_event.h"
#include "esp_log.h"
#include "esp_sntp.h"
#include "esp_wifi.h"
#include "nvs_flash.h"

#include <driver/gpio.h>
#include <driver/uart.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#define UART_NUM UART_NUM_1
#define PIN_TX GPIO_NUM_5
#define PIN_RX GPIO_NUM_4
#define BUF_SIZE (2 * SOC_UART_FIFO_LEN)
#define STACK_SIZE (2048)
#define MSGLEN 20
#define FORMAT "YYYY-MM-DD hh:mm:ss"

static const char *TAG = "Clock";

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

  // UART init
  QueueHandle_t queue;
  uart_config_t config = {
      .baud_rate = 115200,
      .data_bits = UART_DATA_8_BITS,
      .parity = UART_PARITY_DISABLE,
      .stop_bits = UART_STOP_BITS_1,
      .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
      .source_clk = UART_SCLK_DEFAULT,
  };

  ESP_ERROR_CHECK(
      uart_driver_install(UART_NUM, BUF_SIZE, BUF_SIZE, 8, &queue, 0));
  ESP_ERROR_CHECK(uart_param_config(UART_NUM, &config));
  ESP_ERROR_CHECK(uart_set_pin(UART_NUM, PIN_TX, PIN_RX, UART_PIN_NO_CHANGE,
                               UART_PIN_NO_CHANGE));

  ESP_LOGI(TAG, "UART initialized");

  uart_event_t event;
  uint8_t buffer[BUF_SIZE];

  while (1) {
    if (pdTRUE == xQueueReceive(queue, (void *)&event, portMAX_DELAY)) {
      bzero(buffer, BUF_SIZE);

      switch (event.type) {
      case UART_DATA:
        if (MSGLEN ==
            uart_read_bytes(UART_NUM, buffer, MSGLEN, portMAX_DELAY)) {

          if (!strcmp(buffer, FORMAT)) {

            time_t now = time(NULL);
            char datetime[32] = {0};
            struct tm *timeinfo = localtime(&now);

            strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", timeinfo);

            strcpy(buffer, datetime);

            if (MSGLEN != uart_write_bytes(UART_NUM, buffer, MSGLEN)) {
              ESP_LOGE(TAG, "Failed to write");
            }
          };
        } else {
          ESP_LOGE(TAG, "Failed to read");
        }
        break;

      case UART_FIFO_OVF: /* Event of HW FIFO overflow detected */
        ESP_LOGI(TAG, "Hardware FIFO overflow");
        // If fifo overflow happened, you should consider adding flow control
        // for your application.
        uart_flush_input(UART_NUM);
        xQueueReset(queue);
        break;

      case UART_BUFFER_FULL: /* Event of UART ring buffer full */
        ESP_LOGI(TAG, "Ring buffer full");
        // If buffer full happened, you should consider increasing your buffer
        // size
        uart_flush_input(UART_NUM);
        xQueueReset(queue);
        break;

      case UART_BREAK: /* Event of UART RX break detected */
        ESP_LOGI(TAG, "UART rx break");
        break;

      case UART_PARITY_ERR: /* Event of UART parity check error */
        ESP_LOGI(TAG, "UART parity error");
        break;

      case UART_FRAME_ERR: /* Event of UART frame error */
        ESP_LOGI(TAG, "UART frame error");
        break;

      default: /* Others */
        ESP_LOGI(TAG, "UART event type: %d", event.type);
        break;
      }
    }
  }
}
