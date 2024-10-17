#include <stdio.h>

typedef struct {
    int day; int month; int year;
} date_t;

int main (void) {
    date_t newDate = {10, 10, 2024};
    printf("%i-%i-%i\n", newDate.year, newDate.month, newDate.day);
}