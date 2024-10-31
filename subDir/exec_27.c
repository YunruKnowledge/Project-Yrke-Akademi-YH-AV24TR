#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER 5
#define MAX 5
#define MIN -5

int findLargest(const int *_array, const int _size) {
  int _tempLargest, _tempIndex, _index = 0;
  _tempLargest = _array[_index];
  while (_index < _size) {
    if (_tempLargest < _array[_index]) {
      _tempIndex = _index;
      _tempLargest = _array[_index];
    }
    _index++;
  }
  printf("*** Largest %i ***\n", _array[_tempIndex]);
  return _array[_tempIndex];
}

int findAvarage(const int *_array, const int _size) {
  int _index = 0, _tempValue;
  while (_index < _size) {
    _tempValue += _array[_index];
    _index++;
  }
  printf("*** Avarage %i ***\n", (_tempValue / _size));
  return (_tempValue / _size);
}

int findValue(const int *_array, const int _size, const int _targetVal) {
  int _index = 0, _matchFound = -1;
  while (_index < _size) {
    if (_array[_index] == _targetVal) {
      _matchFound = _index;
      break;
    }
    _index++;
  }
  if (_matchFound == -1)
    printf("*** NO MATCH %i | INDEX | INTAKE %i***\n", _array[_index], _index,
           _targetVal);
  else
    printf("*** MATCH %i | INDEX %i | INTAKE %i***\n", _array[_index],
           _matchFound, _targetVal);
  return _matchFound;
}

int main(void) {
  int arr[BUFFER] = {0};
  srand(time(NULL));
  for (int i = 0; i < BUFFER; i++) {
    arr[i] = rand() % (MAX * 2) + MIN;
    printf("%i ", arr[i]);
  }
  printf("\n");

  int arrSize = (sizeof(arr) / sizeof(arr[0]));
  findLargest(arr, arrSize);
  findAvarage(arr, arrSize);
  findValue(arr, arrSize, 3);

  return 0;
}