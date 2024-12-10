#include "ex241120.h"
#include <stdio.h>

void intSorterASC(int *_int_array, const int _size) {
  int _index = 0, _sortCount = 0;
  if (_int_array != NULL) {
    while (1) {
      if (_int_array[_index] > _int_array[_index + 1] && _index < (_size - 1)) {

        int _temp = _int_array[_index];
        _int_array[_index] = _int_array[_index + 1];
        _int_array[_index + 1] = _temp;
        _sortCount++;

      } else if (_index >= _size) {
        if (!_sortCount) {
          break; // <------------------------ break if has not sorted any
                 // intergers.
        } else {
          _index = 0;
          _sortCount = 0;
        }
      } else {
        _index++;
      }
    }
  }
}

int intArrayCheck(const int *_int_array, const int _size) {
  int _index = 0, _isValid = 1;
  if (_int_array != NULL) {
    while (1) {
      if (_int_array[_index] > _int_array[_index + 1] && _index < (_size - 1)) {
        _isValid = 0;
        break;
      } else if (_index >= _size) {
        break;
      } else {
        _index++;
      }
    }
  }
  return _isValid;
}