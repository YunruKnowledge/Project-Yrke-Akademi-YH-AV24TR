// Create a function to calculate the length of the string.

#include <stdio.h>

int strLength(char *pArr);

int main(void)
{
    char arr[] = "name";

    printf("Write a name:\n");
    scanf(" %s", arr);

    int holderN = strLength(arr);
        printf("%i\n", holderN);

    return 0;
}
int strLength(char *pArr)
{
    int sizeArr = 0;
    int i = 0;

    while ( pArr[i] != '\0')
    {
        sizeArr++;
        i++;
    } 
    printf("The i: %i\nThe sizeArr: %i\n", i, sizeArr);

    return sizeArr;
}