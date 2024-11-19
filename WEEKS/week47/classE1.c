/*
Create a file that that has 2 funcs.

1. Check length of the string.
2. compares 2 strings and returns true if its a match.

3. now include the .h of this file(make it a local library) and call it to-
file 2 and compile file 2 and run.

must run and work.


linux'un ne oldugunu nasil biliryor?
*/
#include <stdio.h>
#include "firstHeaderIMade.h"

#define MAX 8

int main(void)
{
    char name1[MAX] = "Ahmet";
    char name2[MAX] = "Ahmet";

    printf("Pick name 1:\n");
    scanf(" %s", name1);

    printf("Pick name 2:\n");
    scanf(" %s", name2);

    if (cmpr2str(name1, name2) == true)
    {
        printf("\nThe strings ARE the same\n\n");
    }
    else if (cmpr2str(name1, name2) == false)
    {
        printf("\nThe strings are NOT the same\n\n");
    }

    printf("Name 1 has %i letters!\n",fakeFunc(name1));
    printf("Name 2 has %i letters!\n",fakeFunc(name2));

    return 0;
}