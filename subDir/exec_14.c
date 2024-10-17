#include <stdio.h>

#define MIN 2
#define MAX 10000

int main(void)
{
    unsigned int input;
    int isPrime = 1; // yes by default

    do
    {
        printf("Enter number between %i and %i.\n", MIN, MAX);
        printf("User: ");
        scanf("%u", &input);
    } while (input < MIN || input > MAX);

    for (unsigned int i = MIN; i <= input - 1; i++)
    {
        if (input % i == 0)
        {
            isPrime = 0;
        }
    }

    if (isPrime)
    {
        printf("Number has prime energy.\n");
    }
    else
    {
        printf("Was infact... not prime.\n");
    }
}