#include <stdio.h>
#include <stdlib.h>

#define NUMBER 8

int main()
{

    if (NUMBER < 0 || NUMBER > 999)
    {
        printf("The number macro is not defined!");
        exit(1);
    }
    else if (NUMBER == 8 || NUMBER == 16)
    {
        // printf("The defined macro did not match!");
        printf("The defined NUMBER %i matched the macro!", NUMBER);
    }

        return 0;

}