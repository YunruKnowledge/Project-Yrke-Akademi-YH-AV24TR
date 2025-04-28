
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/kernel.h>
#include <zephyr/sys_clock.h>
// #include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>

#include <ctype.h>
#include <zephyr/console/console.h>
#include <zephyr/drivers/rtc.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#define FORMAT "YYYY-MM-DD hh:mm:ss"

#define MSG_SIZE 20
#define I2C_NODE DT_PROP(DT_PATH(zephyr_user), i2c)
#define SLAVE_ADDRESS DT_PROP(DT_PATH(zephyr_user), slave_address)

LOG_MODULE_REGISTER(echo, LOG_LEVEL_ERR);
K_MSGQ_DEFINE(msgq, MSG_SIZE, 4, 2);

int main(void) {
  //
  const struct device *i2c_dev = DEVICE_DT_GET(I2C_NODE);

  if (!device_is_ready(i2c_dev)) {
    printk("I2C device not found!");
    exit(EXIT_FAILURE);
  }

  if (0 != i2c_configure(i2c_dev,
                         I2C_SPEED_SET(I2C_SPEED_FAST) | I2C_MODE_CONTROLLER)) {
    printk("I2C device config failed\n");
    exit(EXIT_FAILURE);
  }

  printk("\n============= I2C Devices =============\n");
  for (int addr = 0; addr < 128; addr++) {
    uint8_t value = 0;
    if (0 == i2c_write(i2c_dev, &value, 0, addr)) {
      printk("I2C device found at address 0x%02X\n", addr);
    }
  }
  printk("=======================================\n\n");

  srand((unsigned)k_uptime_ticks());

  struct rtc_time rtc_block;
  console_init();
  static const struct device *rtc_dev = DEVICE_DT_GET(DT_ALIAS(rtc));
  if (!device_is_ready(rtc_dev)) {
    printk("RTC is not ready.");
    exit(EXIT_FAILURE);
  }

  uint8_t buffer[MSG_SIZE + 1] = {0};

  while (1) {
    int input_char = 0;

    printk("\n"
           "S) Set date and time\n"
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

      strncpy(buffer, FORMAT, (strlen(FORMAT) + 1));
      if (0 == i2c_write(i2c_dev, buffer, MSG_SIZE, SLAVE_ADDRESS)) {
        printk("Sending %s...\nWaiting for response...\n", buffer);
        if (0 == i2c_read(i2c_dev, buffer, MSG_SIZE, SLAVE_ADDRESS)) {
          printk("OK. Setting RTC... %s", buffer);

          int year, month, day, hour, minute, second;
          (void)sscanf(buffer, "%4d-%2d-%2d %2d:%2d:%2d", &year, &month, &day,
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
        } else {
          printk("No response...\n");
        }
      } else {
        printk("Could not initialize I2C Communication...\n");
      }

      break;
    case 'G':

      if (0 != rtc_get_time(rtc_dev, &rtc_block)) {
        printk("RTC get failure.\n");
        exit(EXIT_FAILURE);
      } else {
        printk("%04d-%02d-%02d %02d:%02d:%02d\n", rtc_block.tm_year + 1900,
               rtc_block.tm_mon + 1, rtc_block.tm_mday, rtc_block.tm_hour,
               rtc_block.tm_min, rtc_block.tm_sec);
      }

      break;
    default:;
    }
  }

  return EXIT_SUCCESS;
}
