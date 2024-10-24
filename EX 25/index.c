#include <stdio.h>
#include "../Librarys/GRN.h"

#define MIN_RANGE 1
#define MAX_RANGE 99
#define NUM_OF_RANDOM_NUM 5

char showNumbersFromArray(int *arr)
{
    printf("{");
    for (int i = 0; i < NUM_OF_RANDOM_NUM; i++)
    {
        printf("%d", arr[i]);
        if (i < (NUM_OF_RANDOM_NUM - 1)){
            printf(", ");
        }
    }
    printf("}");
}

int main(void)
{
    int *arr = getArrayOfRandomNumbers(MIN_RANGE, MAX_RANGE, NUM_OF_RANDOM_NUM);

    showNumbersFromArray(arr);

    return 0;
}