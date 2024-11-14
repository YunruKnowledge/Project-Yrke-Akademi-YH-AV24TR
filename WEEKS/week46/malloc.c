/*
program that dyynamically allocates memory
for an array of integers using malloc.
1. ask the user for the size of the array.
2. allocate memory for the array using alloc.
3. initialize the array with some values.
4.print the array.
5. Freethe alllocated memory using free();
*/
#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h>

int main(void)
{
    int size;
    printf("What size will the array be?:\n");
    scanf(" %i", &size);
    // so im creating an array, without the use of arr[size].
    int *arr = calloc(size, sizeof(int));

    // malloc size of 2 int that are pointers in the memory.
    if (arr == NULL)
    {
        printf("Mem alloc failed!");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        *(arr + i) = i;
        printf("In Position of %i is: %i\n", i, *(arr + i));
    }

    // memset(*(arr), '8', 4);

    printf("\nThe position 1 of array holds: %i, %i, %i, %i\n", *(arr + 1), *(arr + 2), *(arr + 3), *(arr + 4));

    free(arr);
    arr = NULL; // so noone else uses it again.

    return 0;
}