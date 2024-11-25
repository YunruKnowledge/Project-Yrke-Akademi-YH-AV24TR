#ifndef SORTARRAY_H
#define SORTARRAY_H

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

typedef bool (*compare_t)(int, int);

bool ascending(int a, int b) {  return a <= b; }
bool descending(int a, int b) { return a >= b; }

void sortArray(int *array, int length, compare_t compare);

bool checkArrayAscending(int *array, int length);
bool checkArrayDescending(int *array, int length);

void swapNum(int *a, int *b);
void shuffleNum(int *array, int length);

void swapChar(char *a, char *b);
void shuffleChar(char *array, char length);

void *sortStringAlphabeticby(char *string, const unsigned int length);

#include "sortArray.c"
#endif