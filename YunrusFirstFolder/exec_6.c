#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int capitalCase() {
    char input[32];
    printf("Input a string. [32c]\n");
    scanf("%s", &input);

    for (int i = 0; i < input[i]; i++)
    {
        printf("%c", toupper(input[i]));
    }
    printf("\n");
}

int rant() {
    printf("%d\n", rand());
    printf("%d\n", rand());
}

int main()
{
    capitalCase();
    rant();
}