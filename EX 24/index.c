#include <stdio.h>
#include <stdbool.h>

struct date
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
};
typedef struct date newDate;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(void)
{
    newDate userDateCheck;
    bool goodYear = false;

    printf("Enter a YEAR in format of : [YYYY]-[MM]-[DD] [HH]:[mm] \n");
    scanf("%d-%d-%d %d:%d", &userDateCheck.year, &userDateCheck.month, &userDateCheck.day, &userDateCheck.hour, &userDateCheck.minute);

    if (isLeapYear(userDateCheck.year))
        printf("The year: [%d] is a leap year! \n", userDateCheck.year);
    else
        printf("The year: [%d] is not a leap year! \n", userDateCheck.year);

    return 0;
}
