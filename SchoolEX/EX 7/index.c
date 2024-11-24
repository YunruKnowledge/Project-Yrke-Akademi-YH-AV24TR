#include <stdio.h>
#include "../../LibTesting/demo.h"

int main(void)
{
    char *string = "Hello";
    (void)printf("%d \n", getStringLen(string));
    return 0;
}