
#include <stdio.h>

int main(void) {
  int number = 3;
  (void)printf("NUMBERS! :3 [%d]\n", number++);
  (void)printf("NUMBERS! :3 [%d]\n", number);
  (void)printf("NUMBERS! :3 [%d]\n", ++number);
  (void)printf("NUMBERS! :3 [%d]\n", number);

  int x = 3;
  (void)printf("NUMBERS! :3 [%d %d %d]\n", (x++), (++x), (x++));

  
  return 0;
}
