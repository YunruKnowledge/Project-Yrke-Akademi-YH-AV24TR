/*
Description
1) Create two pointers, pa and pb to point to a and b; int a = 5; char b = ’s’;

2) Change values of a and b using the pointers.

3) Create a function that takes address of an int and adds 5 to the integer.

4) Create a function pointer, funcptr, to the following function and call it.

                      void say_value(int a) { printf("Value of a is %d\n", a); }
*/
#include <stdio.h>

void add5(int *x);
void say_value(int a);

int main(void)
{

    int a = 5;
    char b = 's';

    int *pa = &a;
    char *pb = &b;

    *pa = 8;
    *pb = 'b';

    printf("Pointer A is: %i || Pointer B is: %c", *pa, *pb);

    void (*funcPtr[])(int a) = {say_value};
    
    funcPtr[0](a);

    return 0;
}

void add5(int *x)
{
    x += 5;
}
void say_value(int a)
{
    printf("\nValue of a is %d\n", a);
}
