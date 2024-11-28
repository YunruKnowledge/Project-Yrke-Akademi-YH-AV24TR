#include <stdio.h>
#include "module.h"

// struct named human, of type person_t(type).
typedef struct human
{
    int age;
    float height;
} person_t;

void module_print_int(int x)
{

    printf("\nThe num is %i\n\n", x);
}

void module_print_string(const char *str, int x)
{

    for (int i = 0; i < x; i++)
    {
        printf("\n\n\nLetter %i is %c\n", i + 1, str[i]);
    }
}

void personCreate(void)
{
    
}

void personDestroy(person_t *prsn)
{
    free(prsn);
}