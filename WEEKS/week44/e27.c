/*
Description
Make a function to find the largest value in an array of type int.
Make a function to get the average of values in an array of type int.
Make a function to find a specific value in an array of type int.
If the value exists in the array, index of the element containing the value in the array shall be returned; otherwise -1.
*/
#include <stdio.h>

#define SIZE 10

// func to find largest value in an array of int.
int largeFind(int *arr, int size);
int averageFinder(int *arr, int size);
int specificFind(int *arr, int size);

int main(void)
{
    int arrOfNums[SIZE] = {84, 91, 12, 99, 43, 22, 11};

    printf("\nThe largest num is: %i\n", largeFind(arrOfNums, SIZE));
    printf("\nThe average among the numbers: %i\n", averageFinder(arrOfNums, SIZE));
    specificFind(arrOfNums, SIZE);

    return 0;
}

int largeFind(int *arr, int size)
{
    int holder = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (holder < arr[i])
        {
            holder = arr[i];
        }
    }
    return holder;
}

int averageFinder(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        temp += arr[i];
    }
    int sum = temp / size;
    return sum;
}

int specificFind(int *arr, int size)
{
    int temp;
    printf("\nInput a number to find:\n");
    scanf(" %i", &temp);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != temp)
        {
            continue;
        }
        else if (arr[i] == temp)
        {
            printf("\nThe number %i was found in the list!", temp);
        }
        else
        {
            printf("\nThe number %i was NOT found in the list.", temp);
        }
    }
}

// function da pointer parameter, ama argument olarak pass in yaptigimda... Pass in yaptigim argument'i fonksiyonun icinde normal */pointer olmadan refer yapabiliyorum.
