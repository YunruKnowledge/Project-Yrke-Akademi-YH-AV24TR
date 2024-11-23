/*
Create a function to sort an array of integers in ascending order.
Create another function to check if the array is sorted.
Implement these functions in a modular format using .c, .h, and main.c files.

Use assert to test the functions, with at least two test cases for each function.
*/
#include <stdio.h>
#include <assert.h>
#include "myLib.h"

#define MAX 6

int main(void)
{
    int theArr[MAX] = {2, 4, 9, 1, 8, 6};

    // Sort the array
    sortArr(theArr, MAX);

    // Print the sorted array
    printf("\nSorted Array: ");
    for (size_t i = 0; i < MAX; i++)
    {
        printf("%i, ", theArr[i]);
    }

    // Check if the array is sorted
    assert(true == checkArrIsSorted(theArr, MAX));
    printf("The array is %s", ( checkArrIsSorted(theArr, MAX) == true ) ? "sorted" : "NOT sorted");

    return 0;
}