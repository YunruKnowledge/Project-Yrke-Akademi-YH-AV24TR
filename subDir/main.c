#include <stdio.h>
#include <limits.h>
#include <float.h>

#define FULL_NAME "Yunru Knowledge"
#ifndef FULL_NAME
#error "Error while quering full name"
#endif

#ifndef NUMBER_INPUT
#error "Error while quering for number."
#elif NUMBER_INPUT != 8 && NUMBER_INPUT != 16
#error "Must be 8 or 16"
#endif

enum color { RED, GREEN, BLUE, YELLOW, WHITE, BLACK };

int main (void) {
    printf("e1: Hewo world, absolute baller!\n");
    printf("pixiv is better than deviantart\n");
    printf("-r is for directories\n");
    printf("e2: %s\n", FULL_NAME);
    printf("e4: %d\n", NUMBER_INPUT);

    printf("e5: vvv (size in bytes)\n");
    printf("CHAR size: %zu | CHAR min: %d | CHAR max: %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("signed CHAR size: %zu | min: %d | max: %d\n", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    printf("unsigned CHAR size: %zu | min: %d | max: %d\n", sizeof(unsigned char), 0, UCHAR_MAX);
    printf("INT size: %zu | min: %d | max: %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("unsigned INT size: %zu | min: %d | max: %d\n", sizeof(unsigned int), 0, UINT_MAX);
    printf("short INT size: %zu | min: %d | max: %d\n", sizeof(short int), SHRT_MIN, SHRT_MAX);
    printf("unsigned short INT size: %zu | min: %d | max: %u\n", sizeof(unsigned short int), 0, USHRT_MAX);
    printf("signed long INT size: %zu | min: %ld | max: %ld\n", sizeof(long int), LONG_MIN, LONG_MAX);
    printf("unsigned long INT size: %zu | min: %d | max: %lu\n", sizeof(unsigned long int), 0, ULONG_MAX);
    printf("signed long long INT size: %zu | min: %lld | max: %lld\n", sizeof(long long int), LLONG_MIN, LLONG_MAX);
    printf("unsigned long long INT size: %zu | min: %d | max: %llu\n", sizeof(unsigned long long int), 0, ULLONG_MAX);
    printf("FLOAT size: %zu | min: %e | max: %e\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("DOUBLE size: %zu | min: %e | max: %e\n", sizeof(double), DBL_MIN, DBL_MAX);
    printf("long DOUBLE size: %zu | min: %Le | max: %Le\n", sizeof(long double), LDBL_MIN, LDBL_MAX);
    printf("enum color size: %zu\n", sizeof(enum color));

    printf("new to test reverting.");

    return 0;
}
