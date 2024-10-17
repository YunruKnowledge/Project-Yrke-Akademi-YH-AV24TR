
#include <stdio.h>

void main(void)
{
    char redef[5];
    printf("VAR: %s\n", redef);

    char addString[] = "str";
    for (size_t i = 0; i < sizeof(redef); i++)
    {
        printf("CHAR: %c - %i\n", redef[i],i);
        redef[i] = addString[i];
    }
    for (size_t i = 0; i < sizeof(redef); i++)
    {
        printf("CHAR: %c - %i\n", redef[i],i);
    }
    printf("STRING: %s\n", redef);
    return;
}