#include <stdio.h>
#include <stdint.h>

int var = NULL;

int main () {
    int var2 = NULL;

    if (var == NULL) printf("VAR_ONE:%c | VAR_TWO:%i\n", var, var2);

    printf("%ld\n", sizeof(int));
    printf("%i - %i - %i - %i\n", sizeof(int8_t),sizeof(int16_t),sizeof(int32_t),sizeof(int64_t));
}