/**
 * @file main.c
 * @author Lazar Roksandic (roksandiclazar@gmail.com)
 * @brief EX 2 to make a menu to show and change RTC time
 * @version 0.1
 * @date 2025-03-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <esp_task_wdt.h>

#define MIN_VAL 2
#define MAX_VAL 1000

void app_main(void) {
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

    while (true) {
        volatile int chosen_num[1] = {0};

        (void) printf("\nEnter a number in the range [%d - %d]: ", MIN_VAL, MAX_VAL);
        while (true) {
            char input = getchar();
            if ((input - '0') >= 0 && (input - '0') <= 9) {
                putchar(input);
                chosen_num[0] = chosen_num[0] * 10 + (input - '0');
            } else if (input == '\n') {
                break;
            } else {
                ;
            }
        }

        if (chosen_num[0] >= MIN_VAL && chosen_num[0] <= MAX_VAL) {
            if (chosen_num[0] >= 1) {
                volatile int count = {0};

                for (int i = 1; i < chosen_num[0]; i++) {
                    if (chosen_num[0] % i == 0) {
                        count++;
                    }
                }

                if (count > 2) {
                    (void) printf("\n%d is not a Prime number!", chosen_num[0]);
                } else {
                    (void) printf("\n%d is a Prime number!", chosen_num[0]);
                }
            } else {
                (void) printf("\nNumber [%d] is not in range!", chosen_num[0]);
            }
        }
    }
}
