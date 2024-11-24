#include "demo.h"

static size_t str_len(const char *str)
{
    size_t len = 0;

    if (str == NULL)
        len = 0;

    while (str[len] != '\0')
        len++;

    return len;
}

int getStringLen(const char* string){
    return str_len(string);
}