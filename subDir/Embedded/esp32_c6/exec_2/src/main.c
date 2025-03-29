
#include <esp_sntp.h>
#include <esp_task_wdt.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define INPUT_BUFFER_SIZE 20
#define DATE_BUFFER_SIZE 20

void app_main() {
  ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));
  struct tm _time = {
      .tm_sec = 0,
      .tm_min = 0,
      .tm_hour = 0,
      .tm_mday = 1,
      .tm_mon = 1 - 1,
      .tm_year = 2000 - 1900,
  };
  struct timeval _now = {0};
  _now.tv_sec = mktime(&_time);
  settimeofday(&_now, NULL);

  int settingTime = 0;
  char input[INPUT_BUFFER_SIZE] = {0};
  while (1) {
    int it = 0;
    if (settingTime == 0) {
      (void)printf("\n");
      (void)printf("S) Set date and time\n");
      (void)printf("G) Get date and time\n");
      (void)printf("Enter a command: ");
    } else {
      (void)printf("Enter a date and time.\n(YYYY-MM-DD hh:mm:ss):\n ");
    }
    while (1) {
      char c = getchar();
      if (settingTime == 0) {

        if (c == 'G' || c == 'g') {
          (void)putchar(c);
          (void)putchar('\n');

          char date[DATE_BUFFER_SIZE] = {0};
          time_t now = time(NULL);
          struct tm *time = localtime(&now);

          strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", time);
          (void)printf("%s\n", date);
          break;
        } else if (c == 'S' || c == 's') {
          (void)putchar(c);
          (void)putchar('\n');
          settingTime = 1;
          break;
        }
      } else {
        if (c == '\n' && it >= 19) {
          (void)putchar('\n');
          input[it] = '\0';
          if (6 == sscanf(input, "%d-%d-%d %d:%d:%d", &_time.tm_year,
                          &_time.tm_mon, &_time.tm_mday, &_time.tm_hour,
                          &_time.tm_min, &_time.tm_sec)) {

            if ((_time.tm_mon <= 12 && _time.tm_mon >= 1) &&
                (_time.tm_mday <= 31 && _time.tm_mday >= 1) &&
                (_time.tm_hour <= 23 && _time.tm_hour >= 0) &&
                (_time.tm_min <= 59 && _time.tm_min >= 0) &&
                (_time.tm_sec <= 59 && _time.tm_sec >= 0)) {
              _time.tm_year = _time.tm_year - 1900;
              _time.tm_mon = _time.tm_mon - 1;

              _now.tv_sec = mktime(&_time);
              settimeofday(&_now, NULL);
            } else {
              (void)printf("Failed to set time. (Invalid range.)\n");
            }
          } else {
            (void)printf("Failed to set time. (Invalid format.)\n");
          }
          settingTime = 0;
          break;
        } else if ((it < 19) && ((c >= '0' && c <= '9') || c == '-' ||
                                 c == ':' || c == ' ')) {
          (void)putchar(c);
          input[it] = c;
          it++;
        } else if (c == '\b') {
          putchar('\n');
          it--;
          input[it] = '\0';
          (void)printf(" %s", input);
        }
      }
    }
  }
}