#include <stdio.h>

int main(void) {
  // 1st
  int var = 1;
  int *ptr = &var;
  printf("varVal:%i - varAdress:%p\nptrVal:%i - ptrAdress:%p", var, &var, *ptr,
         &ptr);

  printf("\n\n");

  // 2nd
  int arr[5] = {1, 2, 3, 4, 5}; // 5 el, 6 slots
  int *arr_ptr = &arr;

  for (size_t i = 0; i < 5; i++) {
    printf("%2lu ", *arr_ptr + i);
  }

  printf("\n");

  for (size_t i = 0; i < 5; i++) {
    *(arr_ptr + i) = *(arr_ptr + i) + 10;
    printf("%lu ", *arr_ptr + i);
  }

  printf("\n\n");

  // 3rd
  int _int = 21;
  int *_ptr = &_int;
  int **_dptr = &_ptr;
  printf(" Pointer Value:[%i] - Adress:[%p]\n", *_ptr, &_ptr);
  printf("Double P Value:[%i] - Adress:[%p]\n", **_dptr, &_dptr);

  return 0;
}