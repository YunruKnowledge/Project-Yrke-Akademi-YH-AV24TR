// Create a function to calculate the length of the string.

#include <stdio.h>

int strLength(char *pArr);

int main(void)
{
    char arr[70];

    printf("Write a name:\n");
    scanf(" %s", arr);

    int holderN = strLength(arr);
        printf("%i\n", holderN);

    return 0;
}

int strLength(char *pArr)
{
    int sizeArr = 0;

    while ( pArr[sizeArr] != '\0')
    {
        sizeArr++;
    } 
    printf("The sizeArr: %i\n", sizeArr);

    return sizeArr;
}