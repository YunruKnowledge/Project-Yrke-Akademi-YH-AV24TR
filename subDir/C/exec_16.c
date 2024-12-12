#include <stdio.h>
#include <stdlib.h>

int sort(const void *value_1, const void *value_2)
{
    return (*(const int *)value_1 - *(const int *)value_2);
}

void printArray(const int *array, const int count)
{
    for (int i = 0; i < count; i++)
    {
        if (i < count - 1)
        {
            (void)printf("%i, ", array[i]);
        }
        else
        {
            (void)printf("%i", array[i]);
        }
    }
}

int main(void)
{
    int instArray[10] = {9, 3, 8, 0, 5, 2, 6, 7, 1, 4};
    int arrayCount = sizeof(instArray) / sizeof(instArray[0]);

    printf("[");
    printArray(instArray, arrayCount);
    printf("]\n");

    qsort(instArray, arrayCount, sizeof(int), sort);

    printf("[");
    printArray(instArray, arrayCount);
    printf("]\n");
}