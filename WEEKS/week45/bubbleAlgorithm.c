// sort an array in ascending order
// use bubble sort algorithm.
#include <stdio.h>

#define SIZE 6

int bblAlg(int *arr);

int main(void)
{
    int numArr[SIZE] = {5, 4, 6, 7, 3, 8};
    // move biggest to last pos

    bblAlg(numArr);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%i-", numArr[i]);
    }

    return 0;
}

int bblAlg(int *arr)
{
    int temp = 0;

    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            // (j - SIZE)
            if (arr[j] > arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}