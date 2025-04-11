#include <esp_task_wdt.h>
#include <stdio.h>
#include <unistd.h>

#define MIN_RANGE 2
#define MAX_RANGE 1000
#define DIGITS 4

int isPrime(int _num);

void app_main() {
  ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

  while (1) {
    (void)printf("Enter a number in the range of [%d, %d]: ", 2, 1000);

    int result = 0;
    int it = 0;
    int c = '\0';

    while (1) {
      c = getchar();
      if (c == '\n' || it >= (DIGITS + 1)) {
        (void)putchar('\n');
        break;
      } else if ((c >= '0' && c <= '9') && it < DIGITS) {
        (void)putchar(c);
        int num = (c - '0');
        result = result * 10;
        result += num;
        it++;
      } else {
        ;
      }
    }

    (void)printf("%d is ", result);
    isPrime(result) ? (void)printf(" ") : (void)printf("not ");
    (void)printf("a prime number!\n");
  }
}

int isPrime(int _num) {
  int notPrime = 0;
  if (_num < 2) {
    notPrime = 1;
  } else {
    for (int i = 2; i < _num; ++i) {
      if (_num % i == 0) {
        notPrime = 1;
        break;
      }
    }
  }
  return (!notPrime);
}