/*
Description
Make a function to compare two strings.

If they are equal, the function shall return 1; otherwise 0.
*/
#include <stdio.h>
#include <string.h>

#define MAX 30

int strCmprer(char *str1, char *str2);

int main(void)
{
    char firstLetter[MAX];
    char secondLetter[MAX];
    
    printf("To compare 2 strings, input letter 1:\n");
    scanf(" %s", firstLetter);
    
    printf("Input letter 2:\n");
    scanf(" %s", secondLetter);

    strCmprer(firstLetter, secondLetter);

    return 0;
}

int strCmprer(char *str1, char *str2)
{

    if (strcmp(str1, str2) == 0)
    {

        printf("FAILED, same strings!");
        return 1;
    }
    else
    {
        printf("Strings are not equal, you're good to go!");
        return 0;
    }
}