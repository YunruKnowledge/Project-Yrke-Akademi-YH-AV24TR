/**
 * @file main.c
 * @author Khanh Tran
 * @brief Make a program to read a string of max. 20 lowercase letters.
 * Then reverse and convert the string to uppercase and print it.
 * The read string from terminal shall only contain a to z.
 * @version 0.1
 * @date 2025-03-25
 *
 * @copyright Copyright (c) 2025
 *
 */
// #include <esp_task_wdt.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 20

uint8_t getLength(char _string[BUFFER_SIZE]);
char *toUpper(uint8_t _length, char _string[_length]);
char *reverse_string(uint8_t _length, char _string[_length]);

void app_main(void) {
  // ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

  int c;
  uint8_t it = 0, length = 0, exit = 0;
  char _temp[BUFFER_SIZE];
  while (!exit) {
    (void)printf("Enter a string. (Max. 20ch, Lower case only.)\n");

    it = 0;
    c = '\0';

    while (1) {
      c = getchar();
      if (c == '\n' || it >= BUFFER_SIZE) {
        (void)putchar('\n');
        break;
      } else if (c >= 'a' && c <= 'z') {
        (void)putchar(c);
        _temp[it] = c;
        it++;
      } else {
        ;
      }
    }
    _temp[it] = '\0';

    length = getLength(_temp);
    (void)toUpper(length, _temp);
    (void)reverse_string(length, _temp);
    (void)printf("Your reversed & uppercased string: %s\n\n", _temp);
    (void)printf("Would you like to enter another string? (y/n)\n");

    while (1) {
      c = getchar();
      if (c == '\n') {
        (void)putchar('\n');
        (void)printf("Enter pressed... Defaulting to (n).");
        c = 'n';
        break;
      } else if ((c == 'y' || c == 'Y') || (c == 'n' || c == 'N')) {
        (void)printf("Option (%c) chosen.\n", c);
        break;
      }
    }

    if ((c == 'y' || c == 'Y')) {
      ;
    } else {
      break;
    }
  }

  while (1) {
    (void)printf("Awaiting reset...\n");
    usleep(1000000);
  }
}

uint8_t getLength(char _string[BUFFER_SIZE]) {
  uint8_t _length = 0;
  while (_string[_length] != '\n' && _string[_length] != '\0' &&
         _length < BUFFER_SIZE) {
    _length++;
  }
  return _length;
}

char *toUpper(uint8_t _length, char _string[_length]) {
  for (size_t i = 0; i < _length; i++) {
    _string[i] = ('A' + (_string[i] - 'a'));
  }
  return _string;
}

char *reverse_string(uint8_t _length, char _string[_length]) {
  for (size_t i = 0; i < _length / 2; i++) {
    char temp = _string[(_length - 1) - i];
    _string[(_length - 1) - i] = _string[i];
    _string[i] = temp;
  }

  return _string;
}
