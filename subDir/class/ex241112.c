#include <stdio.h>
#define FILENAME "test.txt"
#define READ_BUFFER 1024
#define INPUT_BUFFER 1024

int checkStringLength(const char *_string);

int main(void) {
  (void)printf("Please enter your full name. (Max 128)\n");
  int _inputIndex = 0, _age = 0;
  char _input, _name[INPUT_BUFFER];
  while ((_input = getchar()) && _input != '\n' && _input != EOF) {
    _name[_inputIndex] = _input;
    _inputIndex++;
  }
  (void)printf("Please enter your age.\n");
  if (!scanf("%i", &_age)) {
  (void)printf("Invalid. Exiting...b\n");
    return 1;
  }

  FILE *fptr = fopen(FILENAME, "r");
  if (!fptr) {
    (void)printf("Failed to open the file!\n");
    return 1;
  }

  char buff[READ_BUFFER];
  int _charCount = 0, _index = 0;
  while (1) {
    if (!fgets(buff, READ_BUFFER, fptr)) {
      fclose(fptr);
      break;
    }
    (void)printf("%s", buff);
    // printf("%i", checkStringLength(buff));
    _charCount += checkStringLength(buff);
    _index++;
  }
  (void)printf("\nLines: %i | Characters: %i\n", _index, _charCount);

  fptr = fopen(FILENAME, "r+");
  if (!fptr) {
    (void)printf("Failed to open the file!\n");
    return 1;
  }
  for (int i; i < _index - 2; i++) {
    if (!fgets(buff, READ_BUFFER, fptr)) {
      fclose(fptr);
      (void)printf("Failed to read the file!\n");
      return 1;
    }
  }
  fseek(fptr, 3, SEEK_CUR);
  fprintf(fptr, ",\n  {\n    name: \"%s\",\n    age: %i\n  }\n}", _name, _age);

  if (0 != fclose(fptr)) {
    (void)printf("Failed to close the file!\n");
    return 1;
  }

  printf("%s\n", buff);
  printf("%i\n", checkStringLength(buff));

  return 0;
}

int checkStringLength(const char *_string) {
  int _index = 0;
  while (_string[_index]) {
    if (_string[_index] == '\0' || _string[_index] == '\n' ||
        _string[_index] == EOF) {
      break;
    } else {
      _index++;
    }
  }

  return _index;
}