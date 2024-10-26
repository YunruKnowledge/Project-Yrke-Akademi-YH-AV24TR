#include <stdio.h>

int main(void){

    /*int variable = 8;
    int *pointer = &variable;

    printf("The variable: %i\nThe address: %p\nThe Value the pointer points to: %i\n", variable, pointer, *pointer);
    */

   int numberE = 8;
   int *ptr = &numberE;//ampersand for the address, without it we would be putting th e 8 next to it.
   int **PtoP = &ptr;

   printf("The values are: %i & %i\nThe addresses are: %p & %p\n", *ptr,**PtoP,ptr,PtoP);

    return  0;
}