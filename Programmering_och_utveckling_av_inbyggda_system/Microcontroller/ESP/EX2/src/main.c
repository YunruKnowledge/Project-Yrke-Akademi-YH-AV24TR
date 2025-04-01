/**
 * @file main.c
 * @author Lazar Roksandic (roksandiclazar@gmail.com)
 * @brief EX 2 to make a menu to show and change RTC time
 * @version 0.1
 * @date 2025-03-27
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <esp_task_wdt.h>
#include <sys/time.h>

struct tm timeinfo = {
    .tm_sec = 10,
    .tm_min = 10,
    .tm_hour = 10,
    .tm_mday = 21,
    .tm_mon = 3 - 1,
    .tm_year = 2025 - 1900,
};

void get_rtc_time(char date_time[32]);

struct tm *set_rtc_time(void);

void app_main(void) {
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

    struct timeval now = {0};
    now.tv_sec = mktime(&timeinfo);
    settimeofday(&now, NULL);

    while (true) {
        time_t now = time(NULL);
        char datetime[32] = {0};
        struct tm *local_time = localtime(&now);

        strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", local_time);

        (void) printf("---------Menu--------- \n");
        (void) printf("G. Get date and time \n");
        (void) printf("S. Set date and time \n");
        (void) printf("---------------------- \n");

        while (1) {
            char ch = getchar();
            if (toupper(ch) == 'G') {
                (void) printf("%c \n", ch);
                get_rtc_time(datetime);
                break;
            } else if (toupper(ch) == 'S') {
                (void) printf("%c \n", ch);
                struct tm *temp = set_rtc_time();
                if (temp != NULL) {
                    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", temp);
                    (void) printf("\nDate is successfully set to: %s\n", datetime);
                }
                break;
            }
        }
    }
}

void get_rtc_time(char date_time[32]) {
    (void) printf("Current date is: %s\n", date_time);
}

struct tm *set_rtc_time(void) {
    int date[6] = {0, 0, 0, 0, 0, 0};
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int _bool = 0;
    volatile int it = {0};

    (void) printf("Enter time in format of [YYYY-MM-DD hh:mm:ss]: ");
    char user_input = getchar();

    while (1) {
        user_input = getchar();
        if (user_input >= '0' && user_input <= '9') {
            putchar(user_input);
            date[it] = date[it] * 10 + (user_input - '0');
        } else if ((user_input == '-' && it < 3) ||
                   (user_input == ':' && it >= 3 && it <= 5) ||
                   (user_input == ' ' && it == 2)) {
            putchar(user_input);
            it++;
        } else if (user_input == '\n' || it > 5) {
            break;
        }
    }


    date[0] -= 1900;
    if (date[0] > 0) {
        if ((date[0] % 4 == 0 && date[0] % 100 != 0) || date[0] % 400 == 0) {
            days[date[1] - 1] = 29;
        }

        date[1] -= 1;
        if (date[1] > 0 && date[1] <= 12) {
            if (date[2] > 0 && date[2] < days[date[1]]) {
                if (date[3] < 25 && date[3] > 0 && date[4] < 60 && date[4] > 0 && date[5] < 60 && date[5] > 0) {
                    timeinfo.tm_year = date[0];
                    timeinfo.tm_mon = date[1];
                    timeinfo.tm_mday = date[2];
                    timeinfo.tm_hour = date[3];
                    timeinfo.tm_min = date[4];
                    timeinfo.tm_sec = date[5];

                    struct timeval now = {0};
                    now.tv_sec = mktime(&timeinfo);
                    settimeofday(&now, NULL);

                    _bool = 1;
                } else {
                    (void) printf("\nTime is out of scope! \n");
                }
            } else {
                (void) printf("\nDay is out of scope! \n");
            }
        } else {
            (void) printf("\nMonth is out of scope! \n");
        }
    } else {
        (void) printf("\nYear is out of scope! \n");
    }

    return _bool == 1 ? &timeinfo : NULL;
}
