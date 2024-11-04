// Description
// Make a function to print all prime numbers in the range of m and n to the ouput.
// m and n are two unsigned integers.
#include <stdio.h>

void drinkPrime(unsigned int min, unsigned int max);

int main(void)
{

    unsigned int m, n;
    printf("In range of num1:\n");
    scanf(" %u", &n);
    printf("In range of num2:\n");
    scanf(" %u", &m);

    drinkPrime(n, m);

    return 0;
}

void drinkPrime(unsigned int min, unsigned int max)
{
    int mistake = 0;

    // Numaranin yarisi, kendisine modulus yapildiginda, ve sonuc 0 degil ise [not a prime]
    for (unsigned int i = min; i <= max; i++)
    {
        // Logic asagida
        int prime = 1;

        if (i <= 1)
        {
            prime = 0;
        }
        else
        {
        for (unsigned int j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                prime = 0;
                break;
            }
            
        }
        }

        if (prime)
        {
            printf("The num %u is a PRIME NUMBER\n", i);
        }
        else
        {
            mistake++;
        }
    }
    printf("\nThere was %i numbers that was not a prime!", mistake);
    
}
