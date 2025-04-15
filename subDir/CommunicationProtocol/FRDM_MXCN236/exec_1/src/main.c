
#include <ctype.h>
#include <string.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>

#include <ctype.h>
#include <zephyr/console/console.h>
#include <zephyr/drivers/rtc.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#define MSG_SIZE 20
#define FORMAT "YYYY-MM-DD hh:mm:ss"

#define UART_NODE DT_ALIAS(uart)

LOG_MODULE_REGISTER(echo, LOG_LEVEL_ERR);
K_MSGQ_DEFINE(msgq, MSG_SIZE, 4, 2);

static void on_receive(const struct device *udev, void *) {
  if ((1 == uart_irq_update(udev)) && (1 == uart_irq_rx_ready(udev))) {
    char chr;
    static int pos = 0;
    static char buffer[MSG_SIZE];

    while (sizeof(chr) == uart_fifo_read(udev, &chr, sizeof(chr))) {
      buffer[pos++] = chr;

      if (pos == MSG_SIZE) {
        pos = 0;

        (void)k_msgq_put(&msgq, buffer, K_FOREVER);
      }
    }
  }
}

int main(void) {
  const struct device *const uart_dev = DEVICE_DT_GET(UART_NODE);

  if (!device_is_ready(uart_dev)) {
    printk("UART device not found!");

    exit(EXIT_FAILURE);
  }

  if (0 != uart_irq_callback_user_data_set(uart_dev, on_receive, NULL)) {
    printk("Failed to configure interrupt and callback to receive data \n");

    exit(EXIT_FAILURE);
  }

  uart_irq_rx_enable(uart_dev);

  srand((unsigned)k_uptime_ticks());

  struct rtc_time rtc_block;
  console_init();
  static const struct device *rtc_dev = DEVICE_DT_GET(DT_ALIAS(rtc));
  if (!device_is_ready(rtc_dev)) {
    printk("RTC is not ready.");
    exit(EXIT_FAILURE);
  }

  char string[MSG_SIZE] = FORMAT;
  char buffer[MSG_SIZE];

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

      printk("\nSending UART...\n");
      strcpy(string, FORMAT);
      for (int i = 0; i < MSG_SIZE; i++) {
        uart_poll_out(uart_dev, string[i]);
      }

      printk("Waiting for response...\n");
      if (0 == k_msgq_get(&msgq, buffer, K_FOREVER)) {
        printk("OK. Setting RTC...\n");
        for (int i = 0; i < MSG_SIZE; i++) {
          string[i] = buffer[i];
        }

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
      } else {
        printk("No reponse. Skipping...\n");
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
