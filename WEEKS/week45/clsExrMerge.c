// Make a function to sort an array in accending order.
// then make another function to merge two sorted arrays.
//  so that the resultant array is in sorted order using pointers.
#include <stdio.h>

#define SIZE 10

void sortAscending(int *arr);
void mergeArr(int *arr1, int *arr2);
void addArr(int *arr1, int *arr2);

int main(void)
{
    int numArr[SIZE] = {20, 50, 30, 40, 80, 10, 70, 100, 60, 90};
    int numArr2[SIZE] = {20, 50, 30, 40, 80, 10, 70, 100, 60, 90};

    sortAscending(numArr);
    // sortAscending(numArr2);

    // mergeArr(numArr, numArr2);
    addArr(numArr,numArr2);

    for (int i = 0; i < SIZE; i++)
    {
        printf(" %i", numArr[i]);
    }

    return 0;
}

void addArr(int *arr1, int *arr2)
{

    for (int i = 0; i < SIZE; i++)
    {
        arr1[(SIZE * 2) + i] = arr2[i];
    }
}

void mergeArr(int *arr1, int *arr2)
{
    // memcmp() if they are same, use mem cpy to numArr[SIZE].
    if (memcmp(arr1, arr2, SIZE * sizeof(int)) == 0)
    {
        printf("They are the same.\n");
        printf("Merging them now!");
        memcpy(arr2, arr1, (2 * SIZE) * sizeof(int));
    }
    else
    {
        printf("They are NOT the same!");
    }
}

void sortAscending(int *arr)
{
    int temp;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Func sortAscending done!\n");
}
