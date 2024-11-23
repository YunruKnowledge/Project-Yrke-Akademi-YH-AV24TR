/*
Create a function to sort an array of integers in ascending order.
Create another function to check if the array is sorted.
Implement these functions in a modular format using .c, .h, and main.c files.

Use assert to test the functions, with at least two test cases for each function.
*/
#include <stdio.h>
#include "myLib.h"
// ascending -> 1,2,3

void sortArr(int *arr, int len)
{
    int temp = 0;

    for (int i = 0; i < len - 1; i++)
    {

        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool checkArrIsSorted(int *arr, int len)
{
    bool status = true;

    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("You messed up!\n");

            status = false;
            break;
        }
    }

    return status;
}