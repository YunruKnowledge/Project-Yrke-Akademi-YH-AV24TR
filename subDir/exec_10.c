#include <stdio.h>

int main(void)
{
    unsigned char binary[8];
    unsigned int userNumber;

    scanf("%i", &userNumber);

    if (userNumber < 0 && userNumber > 255) return -1;

    for (int i = 0; i <= 8; i++)
    {
        binary[i] = userNumber % 2;
        userNumber = (userNumber / 2);
    }
    

    for (int a = sizeof(binary) -1; a >= 0; a--)
    {
        printf("%i", binary[a]);
    }

    return 0;
}