/**
 * @file main.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of UART using interrupts.
 *        Look at: https://docs.espressif.com/projects/esp-idf/en/stable/esp32c6/api-reference/peripherals/uart.html
 *
 * @version 0.1
 * @date 2025-04-01
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>
#include <driver/uart.h>
#include <driver/gpio.h>
#include <esp_log.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define UART_NUM UART_NUM_1              // Using UART1
#define PIN_TX GPIO_NUM_21               // Define TX pin
#define PIN_RX GPIO_NUM_20               // Define RX pin
#define BUF_SIZE (2 * SOC_UART_FIFO_LEN) // Buffer size shall be greater than SOC_UART_FIFO_LEN
#define STACK_SZIE (2048)                // The UART event task stack size
#define MSGLEN 8                         // Message length

static const char *TAG = "Example";

void app_main()
{
    QueueHandle_t queue;

    uart_config_t config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };

    // Install driver and configure UART
    ESP_ERROR_CHECK(uart_driver_install(UART_NUM, BUF_SIZE, BUF_SIZE, 8, &queue, 0));
    ESP_ERROR_CHECK(uart_param_config(UART_NUM, &config));
    ESP_ERROR_CHECK(uart_set_pin(UART_NUM, PIN_TX, PIN_RX, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));

    ESP_LOGI(TAG, "UART initialized");

    uart_event_t event;
    uint8_t buffer[BUF_SIZE];

    while (1)
    {
        // Waiting for UART event.
        if (pdTRUE == xQueueReceive(queue, (void *)&event, portMAX_DELAY))
        {
            bzero(buffer, BUF_SIZE);

            switch (event.type)
            {
            case UART_DATA: /* Event of UART receiving data */
                if (MSGLEN == uart_read_bytes(UART_NUM, buffer, MSGLEN, portMAX_DELAY))
                {
                    for (size_t i = 0; i < MSGLEN; i++)
                    {
                        buffer[i] = toupper(buffer[i]);
                    }

                    if (MSGLEN != uart_write_bytes(UART_NUM, buffer, MSGLEN))
                    {
                        ESP_LOGE(TAG, "Failed to write");
                    }
                }
                else
                {
                    ESP_LOGE(TAG, "Failed to read");
                }
                break;

            case UART_FIFO_OVF: /* Event of HW FIFO overflow detected */
                ESP_LOGI(TAG, "Hardware FIFO overflow");
                // If fifo overflow happened, you should consider adding flow control for your application.
                uart_flush_input(UART_NUM);
                xQueueReset(queue);
                break;

            case UART_BUFFER_FULL: /* Event of UART ring buffer full */
                ESP_LOGI(TAG, "Ring buffer full");
                // If buffer full happened, you should consider increasing your buffer size
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
