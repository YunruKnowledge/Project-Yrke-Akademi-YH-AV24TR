#include <stdio.h>

void swpValues(int *, int *);

int main(void)
{
    int a, b;
    printf("Give value to A\n");
    scanf(" %i", &a);

    printf("Give value to B:\n");
    scanf(" %i", &b);

    swpValues(&a, &b);
    printf("A is: %i, B is: %i", a, b);

    return 0;
}
void swpValues(int *f, int *s)
{
    int temp;

    temp = *f;
    *f = *s;
    *s = temp;
}