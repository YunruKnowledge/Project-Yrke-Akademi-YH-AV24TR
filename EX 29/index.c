#include <stdio.h>

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

int main(void)
{
    unsigned int n, m;

    printf("Input minimum number: ");
    scanf("%d", &n);
    printf("Input maximum number: ");
    scanf("%d", &m);

    printf("All prime number in range [%d-%d] are: { ", n, m);
    for (n; n <= m; n++)
    {
        if (checkPrime(n))
        {
            printf("%d ", n);
        }
    }
    printf("} \n");
}