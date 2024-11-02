/*
Description
Make a program to fill a 2D array (2x3) of type int with random numbers in the range of 0 and 99 and then print the array to the terminal.

To fill and print the array, use only pointers.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM1 2
#define NUM2 3

int main(void)
{
    int twoDarr[NUM1][NUM2]; // 2darray 111111111*111111111*1111111111
    int *p = &twoDarr[0][0];//int pointer to two dimensional arrays address.
    srand(time(NULL)); // seed random of time(0)
/*
    for (int i = 0; i <= 6; i++)
    {
        // printf("for int i nmr %i started.\n", i);

        *(p + i) = rand() % 100;
        printf(" %i\n", *(p + i));
        // for (int j = 0; j <= NUM2; j++)
        // {
        //     printf("for int j nmr %i started.\n", j);
        //
        //     printf("for int j nmr %i exit.\n", j);
        // }

        printf("for int i nmr %i exit.\n", i);
    }
*/
    for (int i = 0; i < (NUM1*NUM2); i++)
    {
        printf("%i:", i+1);
         *(p + i) = (rand() % 100);
        printf(" %i\n", *(p + i));
    }

    return 0;
}