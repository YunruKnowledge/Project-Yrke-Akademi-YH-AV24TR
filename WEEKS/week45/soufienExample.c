#include <stdio.h>
#include <stdint.h>

int decToBin(int num);

int main(void)
{
    int NumberToCnvrt;
    scanf("%i", &NumberToCnvrt);

    decToBin(NumberToCnvrt);

    return 0;
}

int decToBin(int num)
{
    uint8_t mask = 0b10000000;// 0b binary demek icin, gerisi sifirlar.

    for (uint8_t i = 0; i < 8; i++)
    {
        uint8_t x = num & mask >> i;
        printf("%d", (x) ? 1 : 0);
    }
}
