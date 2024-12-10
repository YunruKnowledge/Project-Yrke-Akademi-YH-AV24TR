#include <stdio.h>

struct
{
    unsigned int evenTotal;
    unsigned int oddTotal;
    unsigned int evenCount;
    unsigned int oddCount;
    unsigned int total;
} count;

int main(void)
{
    struct count;
    int input;
    int input2;
    int verbal = 0;

    printf("Enter a number.\n");
    scanf("%i", &input);

    if (input < 0)
        return -1;

    count.total += input;
    for (int i = 0; i < input; i++)
    {
        if (i & 0b1)
        {
            printf("TOTAL: %u | ORDER: %u | NUM: %i\n", count.oddTotal, count.oddCount, i);
            count.oddTotal += i;
            count.oddCount++;
            count.total += i;
        }
        else
        {
            printf("TOTAL: %u | ORDER: %u | NUM: %i\n", count.evenTotal, count.evenCount, i);
            count.evenTotal += i;
            count.evenCount++;
            count.total += i;
        }
    }
    printf("Final total w/ even numbers: %4u | COUNT: %3u (incl. zero.)\n", count.evenTotal, count.evenCount);
    printf("Final total w/  odd numbers: %4u | COUNT: %3u\n", count.oddTotal, count.oddCount);
    printf("Final total w/ both numbers: %4u | COUNT: %3u\n", count.total, (count.oddCount+count.evenCount));
}