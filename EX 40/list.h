/**
 * @file list.h
 * @version 0.1
 * @date 25-11-2024
 *
 * @copyright Copyright (c) 2024
 */

#ifndef LIST
#define LIST

#include <stddef.h>
#include <stdbool.h>

bool listInsert(int val);
bool listGetData(size_t n, int *intPtr);
bool listRemove(size_t n);
bool listUpdate(size_t n, int val);

size_t listAvalble(void);
size_t listFind(int val);

void listDelete(void);

#endif // !LIST