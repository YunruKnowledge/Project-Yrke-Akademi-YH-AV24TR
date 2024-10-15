#include <stdio.h>
#define NUMBER 1000

int main(void)
{
    printf("Finding numbers ending with 7, between 0 and %i\n", NUMBER);

    for (size_t i = 0; i < NUMBER; i++)
    {
        const size_t lastDigit = i % 10;
        if (lastDigit == 7)
        {
            printf("[%lu]\n", i);
        }
    }
}