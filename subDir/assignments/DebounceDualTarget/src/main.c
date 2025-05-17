#include <stdio.h>
#include "button.h"
#include <driver/gpio.h>
#include <esp_task_wdt.h>
#include <driver/gptimer.h>

void app_main(void)
{
    assert(button_init(GPIO_NUM_4));

    // Exclude the Idle Task from the Task WDT
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

    // Config and start a gptimer to run button_update_state every 10ms

    while (1)
    {
        if (BUTTON_FALLING_EDGE == button_get_state())
        {
            printf("Falling Edge\n");
        }
    }
}
