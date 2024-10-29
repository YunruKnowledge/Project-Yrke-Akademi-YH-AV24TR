#include <stdio.h>

int digits(int k);
int power(int x, int y);

int main(void)
{
    int number = digits(33333);
    int poweredNum = power(number, 4);

    printf("Number of digits: %d \n", number);
    printf("Powered number: %d \n", poweredNum);
}

int digits(int k)
{
    if (k == 0)
        return 0;
    return 1 + digits(k / 10);
}

int power(int x, int y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;

    return x * power(x, y - 1);
}