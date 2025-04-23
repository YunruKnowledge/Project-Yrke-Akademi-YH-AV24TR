
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <esp_log.h>
#include <driver/gpio.h>
#include <driver/i2c_slave.h>
#include <freertos/FreeRTOS.h>

#define SLAVE I2C_NUM_0
#define PIN_SDA GPIO_NUM_8 // GPIO for SDA
#define PIN_SCL GPIO_NUM_9 // GPIO for SCL
#define ADDRESS 0x57       // Slave Address
#define MSG_SIZE 8         // Buffer Length

static const char *TAG = "I2C_SLAVE";
static uint8_t buffer[MSG_SIZE];

static bool on_request(i2c_slave_dev_handle_t i2c_slave, const i2c_slave_request_event_data_t *, void *)
{
    uint32_t length;

    for (int i = 0; i < MSG_SIZE; i++)
    {
        buffer[i] = toupper(buffer[i]);
    }

    ESP_ERROR_CHECK(i2c_slave_write(i2c_slave, buffer, MSG_SIZE, (uint32_t *)&length, -1));

    return true;
}

static bool on_receive(i2c_slave_dev_handle_t i2c_slave, const i2c_slave_rx_done_event_data_t *evt_data, void *)
{
    memcpy(buffer, evt_data->buffer, evt_data->length > MSG_SIZE ? MSG_SIZE : evt_data->length);

    return true;
}

void app_main(void)
{
    i2c_slave_config_t config = {
        .i2c_port = SLAVE,
        .sda_io_num = PIN_SDA,
        .scl_io_num = PIN_SCL,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .send_buf_depth = MSG_SIZE,
        .receive_buf_depth = MSG_SIZE,
        .slave_addr = ADDRESS,
        .addr_bit_len = I2C_ADDR_BIT_LEN_7,
    };

    i2c_slave_dev_handle_t handle;
    ESP_ERROR_CHECK(i2c_new_slave_device(&config, &handle));

    i2c_slave_event_callbacks_t callbacks = {.on_receive = on_receive, .on_request = on_request};
    i2c_slave_register_event_callbacks(handle, &callbacks, NULL);

    ESP_LOGI(TAG, "I2C Slave Initialized at address 0x%X", ADDRESS);

    while (1)
    {
        sleep(1);
    }
}
