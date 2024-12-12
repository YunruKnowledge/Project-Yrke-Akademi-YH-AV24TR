#include <stdio.h>

int main(void)
{
    unsigned char binary[8];
    unsigned int userNumber = 0;
    int exit = 0;

    printf("Enter a number to convert into Byte.\n");
    while (exit == 0)
    {
        scanf("%i", &userNumber);
        if (userNumber > 255u)
        {
            printf("Try again, enter a number below 255.\n");
            continue;
        }

        for (int i = 0; i <= 8; i++)
        {
            binary[i] = userNumber % 2;
            userNumber = (userNumber / 2);
        }

        for (int a = sizeof(binary) - 1; a >= 0; a--)
        {
            printf("%i", binary[a]);
        }
        printf("\n");
        exit = 1;
    }
    return 0;
}