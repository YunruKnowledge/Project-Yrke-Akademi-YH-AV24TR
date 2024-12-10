#include <stdio.h>

#define BUFFER 1024
#define FILE_NAME "text.txt"

int stringCompare(const char *_string_first, const unsigned int _length,
                  const char *_string_second);
int checkStringLength(const char *_string);

int main(void) {
  char _input[BUFFER] = {0};
  FILE *_fptr = fopen(FILE_NAME, "r");

  if (!_fptr) {
    (void)printf("No file.\n");
  } else {

    (void)printf("Word: ");
    (void)scanf("%s", _input);

    int _index = 0;
    while (_index < BUFFER) {

      char _lineBuffer[BUFFER] = {0};
      int _lineIndex = 0;

      if (!fgets(_lineBuffer, BUFFER, _fptr)) {
        (void)fclose(_fptr);
        (void)printf("\nEnd. (file read)\n");
        break;
      }

      while (_lineIndex < checkStringLength(_lineBuffer)) {
        if (stringCompare(_input, checkStringLength(_input),
                          &_lineBuffer[_lineIndex])) {
          (void)printf("LINE:%3i|CHAR:%3i|%s", _index, _lineIndex, _lineBuffer);
          break;
        }
        _lineIndex++;
      }

      _index++;
    }
  }

  return 0;
}

int stringCompare(const char *_string_first, const unsigned int _length,
                  const char *_string_second) {
  int _isValid = 1;
  for (unsigned int i = 0; i < _length; i++) {
    if (_string_first[i] != _string_second[i]) {
      _isValid = 0;
      //   (void)printf("[%u] '%c' / '%c'\n", i, _string_first[i],
      //                _string_second[i]);
      break;
    }
  }

  return _isValid;
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