#include <ctype.h>
#include <stdio.h>
#include <esp_task_wdt.h>
#include <string.h>

#define MAX_STR_LEN 20

void app_main(void)
{
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

    do
    {
        (void)printf("Enter a string: ");

        char str[MAX_STR_LEN];
        volatile unsigned int len = 0;

        while (1) {
            char ch = getchar();

            if (ch == '\n') {
                break;
            }
            else if (isalpha(ch)){
                if (ch >= 'a' && ch <= 'z' && strlen(str) < MAX_STR_LEN) {
                    str[len++] = ch;
                    putchar(ch);
                }
            }
        }

        char temp[len];

        for (int i = 0; i < len; i++) {
            temp[i] = toupper(str[len - i - 1]);
        }

        printf("\nReverse string in all upper case: %s \n", temp);
    } while (true);
}
