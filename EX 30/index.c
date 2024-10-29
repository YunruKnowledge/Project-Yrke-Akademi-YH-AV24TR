#include <stdio.h>

int val(int addAmount, int path)
{
    path += addAmount;
    return path;
}

void say_value(int a) { printf("Value of a is %d\n", a); }

int main()
{
    int a = 5;
    char b = 's';

    void (*funcptr)(int a);
    funcptr = &say_value;

    int *pa = &a;
    char *pb = &b;

    *pa = 6;
    *pb = 'l';

    *pa = val(5, *pa);
    funcptr(a);
}