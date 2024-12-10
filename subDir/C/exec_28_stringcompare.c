#include <stdio.h>
#define BUFFER ((unsigned int)(sizeof(int) * 8))

int stringCompare(const char *_string_first, const char *_string_second);

int main(void) {
  char input1[BUFFER] = {0}, input2[BUFFER] = {0};
  printf("Enter two strings. (Max %u characters)\n", BUFFER);
  scanf("%s", input1);
  scanf("%s", input2);
  printf("result: %i\n", stringCompare(input1, input2));

  return 0;
}

int stringCompare(const char *_string_first, const char *_string_second) {
  int _isValid = 1;
  for (unsigned int i = 0; i < BUFFER; i++) { // <------------------ buffer
    if (_string_first[i] != _string_second[i]) {
      _isValid = 0;
      printf("[%u] '%c' / '%c'\n", i, _string_first[i], _string_second[i]);
      break;
    }
  }

  return _isValid ? 1 : 0;
}