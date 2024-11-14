// Study the behaviour of the strtok function in string.h;
// http://www.cplusplus.com/reference/cstring/strtok/

// Make a stand-alone and self-contained function like strtok to split a string
// using a delimiter which is one character.
#include <stdio.h>
#define BUFFER 32

static char *split_string(const char *str, const char delim);

int main(void) {
  char _string[BUFFER] = "balls to the walls!", *_temp;
  _temp = split_string(_string, ' ');

  while (_temp != NULL) {
    printf("%s", _temp);
    _temp = split_string(NULL, ' ');
  }

  return 0;
}

static char *split_string(const char *str, const char delim) {
  static const char *_index;
  static char _token[BUFFER];
  int _tokenIndex = 0;

  if (str != NULL) {
    _index = str;
  }

  while (*_index == delim) {
    _index++;
  }

  while (*_index != delim && *_index != '\0' && *_index != EOF) {
    _token[_tokenIndex] = *_index;
    _index++;
    _tokenIndex++;
  }
  _token[_tokenIndex] = '\0';

  return _tokenIndex == 0 ? NULL : _token;
}