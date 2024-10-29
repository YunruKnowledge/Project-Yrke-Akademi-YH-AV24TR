#include <stdio.h>

int checkPrime(int num);

int main(void)
{
    int n;

    printf("Input a number: ");
    scanf("%d", &n);

    if (n < 0)
        n *= -1;

    if (checkPrime(n))
    {
        printf("Your number [%d] is a Prime number \n", n);
    }
    else
        printf("Your number [%d] is not a Prime number \n", n);
}

int checkPrime(int num)
{
    if (num < 2)
        return 0;
    else
    {
        int x = num / 2;
        for (int i = 2; i <= x; i++)
        {
            if (num % i == 0)
                return 0;
        }
    }

    return 1;
}