#include <stdio.h>
int toBin(int decimal_num) {
    int binary_num = 0, i = 1, remainder;
    while (decimal_num != 0) {
        remainder = decimal_num % 2;
        decimal_num /= 2;
        binary_num += remainder * i;
        i *= 10;
    }
    return binary_num;
}

int main () {
    int a = 45;
    int b = -13;
    int c = 0;
    int d = 8;

    printf("a:%d     | b:%d   | c:%d | d:%d\n", a, b, c, d);
    printf("a:%d | b:%d | c:%d | d:%d\n", toBin(a), toBin(b), toBin(c), toBin(d));
    printf("a+b=%d                             | %i\n", (a+b), toBin((a+b)));
    printf("a-b=%d                             | %i\n", (a-b), toBin((a-b)));
    printf("c-a=%d                            | %i\n", (c-a), toBin((c-a)));
    printf("b-a=%d                            | %i\n", (b-a), toBin((b-a)));
    printf("\n");
    printf("a[OR]b=%d                          | %i\n", (a|b), toBin((a|b)));
    printf("a[AND]b=%d                         | %i\n", (a&b), toBin((a&b)));
    printf("a[XOR]b=%d                        | %i\n", (a^b), toBin((a^b)));
    printf("a[<<3]=%d                         | %i (WARNING: BYTE8 - 01101000)\n", (a<<3), toBin((a<<3)));
    printf("b[>>2]=%d                          | %i\n", (b>>2), toBin((b>>2)));
    printf("c[>>5]=%d                           | %i\n", (c>>5), toBin((c>>5)));
    printf("(a[<<3])[>>3]=%d                   | %i (WARNING: BYTE8 - 00001101)\n", ((a<<3) >>3), toBin(((a<<3)>>3)));
    printf("([NOT]a[AND]b)^([NOT]c[OR]a)=%d    | %i\n", (~a&b)^(~c|a), toBin((~a&b)^(~c|a)));
    printf("\n");
    printf("a[AND]129                          | %i\n", toBin((a&0b10000001)));
    printf("b[XOR]4                            | %i\n", toBin((b^0b00000100)));
    printf("c[AND]12                           | %i\n", toBin((d&0b00001100)));
    printf("(c[AND]243)[OR]8                   | %i\n", toBin((d&0b11110011)|0b00001000));
}

