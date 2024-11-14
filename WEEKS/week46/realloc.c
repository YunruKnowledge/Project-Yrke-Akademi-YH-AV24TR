/*
a program that dynamically allocates memory for an array of ints using malloc
and then resizes the memory using realllox.
the program should:
ask user for the initial siize of the array
alloc mem for the array using malloc.
initialize the array with some values -
print array.
ask the useer for the new  size of array.
realloc mem for the array using realloc
print the resized array free the allocated memory using free.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int size;
    printf("Select size for array size:\n");
    scanf(" %i", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Mem alloc failed!");
        return 1;
    }

    for (int i = 1; i <= size; i++)
    {
        *(arr + i) = i;
        printf("Pos %i has %i\n", i, *(arr + i));
    }

    printf("\nSelect NEW size for same array:\n");
    scanf(" %i", &size);

    arr = (int *)realloc(arr, size * sizeof(int)); // (int*) soo realoc will return an int because the arr is of type int,resize to new user input.

    printf("Resized below:\n");

    for (int j = 1; j <= size; j++)
    {

        *(arr + j) = j;
        printf("Pos %i has %i\n", j, *(arr + j));
    }

    free(arr);

    return 0;
}