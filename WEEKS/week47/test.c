#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER 8

int main()
{
    char strStore[BUFFER];
    char cmprStr[BUFFER] = "You";

  
        printf("Type something:\n");
        fgets(strStore, BUFFER, stdin);

            if (strstr(strStore, cmprStr))
        {
            printf("Easter egg!");
        }

        printf("You wrote:\n %s", strStore);

      

    return 0;
}
