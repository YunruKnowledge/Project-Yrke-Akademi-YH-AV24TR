#include <stdio.h>

int getVal(int x, int y);

int main(void)
{
    int length;

    for (int i = 0; i < getVal(1,3); i++)
    {
        (void)printf("[%d] \n", i);
    }

    return 0;
}

int getVal(int x, int y)
{
    (void)printf("Called");
    return x + y;
}