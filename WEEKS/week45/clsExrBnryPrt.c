//take a decimal, 0-255
//use function to return binary value.
//use bitwise operations.

/*
int calcN(int n);

int main(void){

    int d;
    printf("Convert a number to Binary:\n");
    scanf(" %i", &d);

    printf("%0b\n",d);
    printf("After bitwise operation: %i\n",calcN(d));

    return 0;
}

int calcN(int n){

    int temp;
    temp = n << 1;

    return n;
}

*/


#include <stdio.h>
#define txBinary sizeof(int) * 2 //binary value of int, 2x.

int main()
{
    int num, nmStep, i;
    int bin[txBinary];

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);

    nmStep = txBinary - 1;

    while(nmStep >= 0)
    {
        /* Store LSB of num to bin */
        bin[nmStep] = num & 1;

        /* Decrement index */
        nmStep--;

        /* Right Shift num by 1 */
        num >>= 1;
    }

    /* Print converted binary */
    printf("Converted binary: ");
    for(i=0; i<txBinary; i++)
    {
        printf("%d", bin[i]);
    }

    return 0;
}


