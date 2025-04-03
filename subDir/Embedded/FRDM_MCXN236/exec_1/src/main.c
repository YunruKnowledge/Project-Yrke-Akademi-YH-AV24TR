
#include <ctype.h>
#include <zephyr/console/console.h>
#include <zephyr/drivers/rtc.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#define FORMAT "YYYY-MM-DD hh:mm:ss"

LOG_MODULE_REGISTER(echo, LOG_LEVEL_ERR);

static bool isLeap(int _year) {
  return (_year % 400 == 0) || ((_year % 4 == 0) && (_year % 100 != 0));
}

static void getString(char _string[sizeof(FORMAT)]) {
  int it = 0, input_char;
  printk("Input: ");
  while (1) {
    input_char = console_getchar();
    if (input_char < 0) {
      LOG_ERR("Char error.");
    } else if (input_char == '\r') {
      _string[it] = '\0';
      console_putchar('\n');
      break;
    } else if (input_char == '\b') { // notworking
      console_putchar('\n');
      it--;
      _string[it] = '\0';
      printk("Input: %s", _string);
    } else if ((it < sizeof(FORMAT) - 1) &&
               (isdigit(input_char) || input_char == '-' || input_char == ':' ||
                input_char == ' ')) {
      console_putchar(input_char);
      _string[it] = (char)input_char;
      it++;
    } else {
      ;
    }
  }
}

static bool validateDateTime(char _string[sizeof(FORMAT)]) {
  bool valid = false;

  unsigned int length = 0;
  for (length = 0; length < sizeof(FORMAT); length++) {
    if (_string[length] == '\0') {
      break;
    } else {
      ;
    }
  }

  if (length < (sizeof(FORMAT) - 1)) {
    printk("Failed to set, incorrect length.\n");
  } else {
    int year, month, day, hour, minute, second;
    (void)sscanf(_string, "%4d-%2d-%2d %2d:%2d:%2d", &year, &month, &day, &hour,
                 &minute, &second);

    if ((year <= (atoi(__DATE__ + 7) + 5)) && (month >= 1 && month <= 12) &&
        (day >= 1 && day <= 31) && (hour >= 0 && hour <= 23) &&
        (minute >= 0 && minute <= 59) && (second >= 0 && second <= 59)) {
      int days_from_max[12] = {0, -3, 0, -1, 0, -1, 0, 0, -1, 0, -1, 0};
      if (month == 2 && isLeap(year)) {
        if (day < (31 - days_from_max[month - 1] + 1)) {
          valid = true;
        } else {
          printk("Failed to set, invalid leap day.\n");
        }
      } else if (day < (31 - days_from_max[month - 1])) {
        valid = true;
      } else {
        printk("Failed to set, invalid day.\n");
      }
    } else {
      printk("Failed to set, invalid dates/times.\n");
    }
  }

  return valid;
}

int main(void) {

  struct rtc_time rtc_block;
  console_init();
  static const struct device *rtc_dev = DEVICE_DT_GET(DT_ALIAS(rtc));
  if (!device_is_ready(rtc_dev)) {
    printk("RTC is not ready.");
    exit(1);
  }

  while (1) {
    int input_char = 0;

    printk("S) Set date and time\n"
           "G) Get date and time\n"
           "Enter a command: ");

    while (1) {
      input_char = console_getchar();
      if (input_char < 0) {
        LOG_ERR("Getchar error.\n");
      } else if (toupper(input_char) == 'S' || toupper(input_char) == 'G') {
        console_putchar(input_char);
        console_putchar('\n');
        input_char = toupper(input_char);
        break;
      } else {
        ;
      }
    }

    switch (input_char) {
    case 'S':

      char string[sizeof(FORMAT)] = {0};
      getString(string);

      if (validateDateTime(string)) {
        int year, month, day, hour, minute, second;
        (void)sscanf(string, "%4d-%2d-%2d %2d:%2d:%2d", &year, &month, &day,
                     &hour, &minute, &second);

        rtc_block.tm_sec = second;
        rtc_block.tm_min = minute;
        rtc_block.tm_hour = hour;
        rtc_block.tm_mday = day;
        rtc_block.tm_mon = month - 1;
        rtc_block.tm_year = year - 1900;

        if (0 != rtc_set_time(rtc_dev, &rtc_block)) {
          printk("RTC set failure.\n");
          exit(1);
        } else {
          printk("Time successfully set.\n");
        }
      }

    case 'G':

      if (0 != rtc_get_time(rtc_dev, &rtc_block)) {
        printk("RTC get failure.\n");
        exit(1);
      } else {
        printk("%04d-%02d-%02d %02d:%02d:%02d\n", rtc_block.tm_year + 1900,
               rtc_block.tm_mon + 1, rtc_block.tm_mday, rtc_block.tm_hour,
               rtc_block.tm_min, rtc_block.tm_sec);
      }

    default:;
    }
  }

  return EXIT_SUCCESS;
}
