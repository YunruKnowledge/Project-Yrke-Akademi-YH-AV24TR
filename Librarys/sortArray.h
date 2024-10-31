#ifndef SORT_ARRAY
#define SORT_ARRAY

typedef bool (*compare_t)(int, int);

bool ascending(int a, int b) {  return a <= b; }
bool descending(int a, int b) { return a >= b; }

void sortArray(int *array, int length, compare_t compare);

void swapNum(int *a, int *b);
void shuffleNum(int *array, int length);

void swapChar(char *a, char *b);
void shuffleChar(char *array, char length);

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortArray.c"
#endif