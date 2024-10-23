#include <stdio.h>
#include <time.h>

int main(void) {
  time_t now;
  struct tm *info;
  char buffer[64];

  time(&now);
  info = localtime(&now);
  strftime(buffer, sizeof(buffer), "%Y-%m-%d, %H:%M:%S", info);
  printf("%s\n", buffer);

  return 0;
}