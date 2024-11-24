#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int length;

    printf("Enter the size of array: ");
    if (scanf("%d", &length) == 0)
        return 1;

    int *array = (int *)malloc(length * sizeof(int));

    for (int i = 1; i < length; i++)
    {
        array[i] = array[i - 1] != 2 ? 2 : 1;
        printf("[%d] ", array[i]);
    }

    printf("\nEnter the new size of array: ");
    if (scanf("%d", &length) == 0)
        return 1;

    array = (int *)realloc(array, sizeof(int));

    for (int i = 1; i < length; i++)
    {
        array[i] = array[i - 1] != 2 ? 2 : 1;
        printf("[%d] ", array[i]);
    }

    free(array);
    array = NULL;

    return 0;
}