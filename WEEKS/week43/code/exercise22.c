#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    int ch = 0;
    int *pName = &ch;

    while ((*pName = getchar()) != '\n')
    {
        if (*pName >= 'a' && *pName <= 'z')
        {
            *pName -= 32;
        }
        else if(*pName >= 'A' && *pName <= 'Z')
        {
            *pName += 32;
        }
        putchar(*pName);
    }

    return 0;
    /*
    printf("Enter a text:\n");
    char testIn[50];
    char (*p)[50] = &testIn;//We created 50 p, that p to testin[50]? :Mirror of testin.
    scanf(" %s", testIn);

    for (int i = 0; i <= ( strlen(testIn) -1); i++){
        if (isupper( (*p)[i] )) {
            (*p)[i] = tolower((*p)[i]);
        } else {
            (*p)[i] = toupper((*p)[i]);
        }
        printf(" %c", (*p)[i]);
    }
        printf(" %c", (*p)[0]);

    */
}