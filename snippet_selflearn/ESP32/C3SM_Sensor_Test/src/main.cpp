#include <iostream>
#include "driver/gpio.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "IR_TRACKER.h"
#include "IR_08H.h"

#define PROGRAM_OPTION 1

#define IR_SENSOR_PIN GPIO_NUM_4
#define IR_SENSOR_INTERVAL (24 / portTICK_PERIOD_MS)

static const char *TAG = "Main";

namespace tasks
{
    void ir_tracker(void *pvParameters)
    {
        IR_SENSOR_TRACKER::init(IR_SENSOR_PIN);
        while (true)
        {
            int sensor_value = IR_SENSOR_TRACKER::get();

            if (sensor_value == 0)
            {
                ESP_LOGI(TAG, "Obstacle Detected! (Sensor State: LOW)");
            }
            else
            {
                ESP_LOGI(TAG, "No Obstacle. (Sensor State: HIGH)");
            }

            vTaskDelay(IR_SENSOR_INTERVAL);
        }
    }

    void ir_08h(void *pvParameters)
    {
        IR_SENSOR_08H::init(IR_SENSOR_PIN);
        while (true)
        {
            int level = IR_SENSOR_08H::get();

            if (level == 0)
            {
                ESP_LOGI(TAG, "Obstacle Detected! (Sensor State: LOW)");
            }
            else
            {
                ESP_LOGI(TAG, "No Obstacle. (Sensor State: HIGH)");
            }

            vTaskDelay(IR_SENSOR_INTERVAL);
        }
    }
} // namespace tasks

// The main application entry point for ESP-IDF
extern "C" void app_main()
{
#if PROGRAM_OPTION == 1
    xTaskCreate(tasks::ir_tracker, "IR_Tacker", 2048, NULL, 5, NULL);
#elif PROGRAM_OPTION == 2
    xTaskCreate(tasks::ir_08h, "IR_Trigger", 2048, NULL, 5, NULL);
#endif
    ESP_LOGI(TAG, "Application started. Monitoring IR sensor on GPIO %d.", IR_SENSOR_PIN);
}
