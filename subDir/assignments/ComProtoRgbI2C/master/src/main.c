
#include <driver/gpio.h>
#include <driver/i2c_master.h>
#include <esp_log.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MASTER I2C_NUM_0
#define PIN_SDA GPIO_NUM_6
#define PIN_SCL GPIO_NUM_7
#define CLOCK_RATE 400000
#define SLAVE_ADDRESS 0x01
#define I2C_MSG_SIZE 1 // ALWAYS 1
#define INPUT_MAX_LENGTH 8

#define INPUT_TEXT "Enter the LED state: "
#define SUCCESS_TEXT " => done"
#define RED_TEXT "red"
#define GREEN_TEXT "green"
#define BLUE_TEXT "blue"
#define OFF_TEXT "off"
#define LENGTH(x) (sizeof(x) - 1)

static const char *TAG = "MASTER";
static const enum LED_STATE_CODES { LED_OFF = 0, LED_RED, LED_GREEN, LED_BLUE };
static i2c_master_dev_handle_t DEV_HANDLE;

static char INPUT_BUFFER[INPUT_MAX_LENGTH + 1] = {0};
static uint8_t MSG_BUFFER[I2C_MSG_SIZE] = {0};

static uint8_t i2c_send_receive(uint8_t _code) {
  uint8_t status = 0;
  MSG_BUFFER[0] = _code;

  if (ESP_OK == i2c_master_transmit(DEV_HANDLE, MSG_BUFFER, I2C_MSG_SIZE, -1)) {
    if (ESP_OK ==
        i2c_master_receive(DEV_HANDLE, MSG_BUFFER, I2C_MSG_SIZE, -1)) {
      status = MSG_BUFFER[0];
    } else {
      ;
    }
  } else {
    ;
  }
  return status;
}

static void ask_input(void) {
  int it = 0;
  while (it < INPUT_MAX_LENGTH) {
    int ch = getchar();
    if (ch == '\n' || ch == '\r') {
      break;
    } else if (ch >= 'a' && ch <= 'z') {
      (void)putchar(ch);
      INPUT_BUFFER[it] = ch;
      it++;
    } else {
      ;
    }
  }
  INPUT_BUFFER[it] = '\0';
}

void app_main(void) {
  i2c_master_bus_handle_t bus_handle;
  i2c_master_bus_config_t bus_config = {
      .i2c_port = MASTER,
      .sda_io_num = PIN_SDA,
      .scl_io_num = PIN_SCL,
      .clk_source = I2C_CLK_SRC_DEFAULT,
      .glitch_ignore_cnt = 7,
      .flags.enable_internal_pullup = true,
  };
  ESP_ERROR_CHECK(i2c_new_master_bus(&bus_config, &bus_handle));

  i2c_device_config_t dev_config = {
      .dev_addr_length = I2C_ADDR_BIT_LEN_7,
      .device_address = SLAVE_ADDRESS,
      .scl_speed_hz = CLOCK_RATE,
  };
  ESP_ERROR_CHECK(
      i2c_master_bus_add_device(bus_handle, &dev_config, &DEV_HANDLE));
  ESP_LOGI(TAG, "I2C initialized successfully");

  while (1) {
    uint8_t status = 0;

    (void)printf(INPUT_TEXT);
    ask_input();

    if (strlen(INPUT_BUFFER) > 0) {
      if (0 == strncmp(INPUT_BUFFER, RED_TEXT, LENGTH(RED_TEXT))) {
        status = i2c_send_receive(LED_RED);

      } else if (0 == strncmp(INPUT_BUFFER, GREEN_TEXT, LENGTH(GREEN_TEXT))) {
        status = i2c_send_receive(LED_GREEN);

      } else if (0 == strncmp(INPUT_BUFFER, BLUE_TEXT, LENGTH(BLUE_TEXT))) {
        status = i2c_send_receive(LED_BLUE);

      } else if (0 == strncmp(INPUT_BUFFER, OFF_TEXT, LENGTH(OFF_TEXT))) {
        status = i2c_send_receive(LED_OFF);
      } else {
        ;
      }

      if (status == 1) {
        (void)printf(SUCCESS_TEXT);
      } else {
        ;
      }
    } else {
      ;
    }

    (void)putchar('\n');
  }
}