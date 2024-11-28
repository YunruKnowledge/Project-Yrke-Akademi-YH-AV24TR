#include <stdio.h>
#include <stdlib.h>
#include "module.h"

#define MAX_BUFFER_SIZE 8

int main(void)
{
    person_t *lordFumo;
    if (lordFumo != NULL)
    {
        lordFumo = {40, 1.87};
    }

    int y = MAX_BUFFER_SIZE;

    const char *stringBob = "BobsStr";
    module_print_int(y);
    module_print_string(stringBob, y);

    personDestroy(lordFumo);

    return 0;
}
