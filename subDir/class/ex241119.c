#include "ex241119.h"

static unsigned int checkStringLength(const char *_string) {
  unsigned int _index = 0;
  while (_string[_index] && _string != NULL) {
    if (_string[_index] == '\0' || _string[_index] == EOF) {
      break;
    } else {
      _index++;
    }
  }
  return _index;
}

unsigned int giveLength(const char *_string) {
  return checkStringLength(_string);
}

unsigned int stringCompare(const char *_string_first,
                           const char *_string_second) {
  unsigned int _isValid = 1;
  if ((checkStringLength(_string_first) <= checkStringLength(_string_second)) &&
      (_string_first != NULL && _string_second != NULL)) {
    for (unsigned int i = 0; i < checkStringLength(_string_first); i++) {
      if (_string_first[i] != _string_second[i]) {
        _isValid = 0;
        break;
      }
    }
  } else {
    _isValid = 0;
  }
  return _isValid;
}

// MULTI file thingys...
// typedef struct {
//   FILE *fptr;
// } file_t;

// file_t createFIle(const char *_filename) {
//   file_t *_fptr = fopen(_filename, "w");
//   if (_fptr != NULL) {
//     fclose(_fptr);
//   } else {
//     printf("No write access.");
//   }
//   return _fptr;
// }

// void writeFile(file_t *_filename, const char *_string) {
//   FILE *_fptr = fopen(_filename, "w");
//   if (_fptr != NULL) {
//     fprintf(_fptr, "%s", _string);
//     fclose(_fptr);
//   } else {
//     printf("No write access.");
//   }
// }

// void writeFile(const char *_filename, const char *_string) {
//   FILE *_fptr = fopen(_filename, "r");
//   if (_fptr != NULL) {

//     fclose(_fptr);
//   } else {
//     printf("No read access.");
//   }
// }
