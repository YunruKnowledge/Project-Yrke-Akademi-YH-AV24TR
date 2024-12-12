#include <stdio.h>
#include <stdint.h>

#define EXPRESSION (3 * j / k - 2)
#define SET_VARIABLES { \
    i = 3; \
    j = 2; \
    k = 0; \
}

int main(void)
{
    int i = 0, j = 7, k = 6;
    char a = 'A', b = '3';
    int32_t x, y = 3;
    uint32_t z = 32;
    double d;

    // A)
    x = EXPRESSION;
    printf("A) %d\n", x);

    // B)
    y -= ((j << 1) & (k >> 1));
    printf("B) %d\n", y);

    // C)
    x = (!(i && k) || !k) ? k + b : j + b;
    printf("C) %d\n", x);

    // D)
    a += (b + k--) % 10;
    printf("D) %d\n", a);

    // E)
    d = (double) j * 100 / --k / 3;
    printf("E) %f\n", d);

    // F)
    x = -1;
    y = (x < z) ? (k < j < 0) : (b >= a < i);
    printf("F) %d\n", y);

    // G)
    d = x / z;
    printf("G) %f\n", d);

    // H)
    i = 4;
    j = -1;
    k = 0;

    x = i && j && k;
    y = i || j && k;
    printf("H) %d, %d\n", x, y);

    // I)
    x = i && j || k;
    y = i || j || k;
    printf("I) %d, %d\n", x, y);

    // J)
    SET_VARIABLES;
    y = ++i || ++j && k++;
    printf("J) %d, %d, %d, %d\n", i, j, k, y);

    // K)
    SET_VARIABLES;
    y = (123 && --i) ? k++ : ++k;
    printf("K) %d, %d, %d, %d\n", i, j, k, y);

    // L)
    SET_VARIABLES;
    y = ++i && ++j && k++;
    printf("L) %d, %d, %d, %d\n", i, j, k, y);

    // M)
    i = 4;
    j = --i;
    k = i--;
    printf("M) %d, %d, %d\n", i, j, k);

    // N)
    i = -1;
    j = 1;

    i && printf("N) Hello World!\n") && --j;

    // O)
    ++i && j && printf("O) Hello World!\n");

    // P)
    i || printf("P) Hello World!\n") || j++;

    // Q)
    j-- || !printf("Q) Hello World!\n") || i++;

    // R)
    printf("R) %d, %d\n", i, j);

    return 0;
}

// A) 1
// B) 1
// C) 57
// D) 72
// E) 58.333333
// F) 0
// G) 134217727.000000
// H) 0, 1
// I) 1, 1
// J) 4, 2, 0, 1
// K) 2, 2, 1, 0
// L) 4, 3, 1, 0
// M) 2, 3, 3
// N) Hello World!
// P) Hello World!
// Q) Hello World!
// R) 1, -1