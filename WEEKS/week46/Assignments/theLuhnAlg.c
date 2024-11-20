// bool
// length strlen()
//
#include <stdio.h>
#include <stdlib.h> //maybe use atoi(); for string to int conversion
#include <string.h> // Fgets(); to not get spaces
#include <ctype.h>

#define DAYS 12

int dateChecker(int year, int months, int day);
int validatePersonnummer(const char *personnummer);
int theLuhn(const char *number);

int main() {
    char personnummer[11];
    printf("Enter personnummer (YYMMDDNNNN): ");
    scanf("%10s", personnummer);

    if (validatePersonnummer(personnummer))
        printf("Valid personnummer.\n");
    else
        printf("Invalid personnummer.\n");

    return 0;
}

// To check for date if its real or not, takes 3 arguments and will return 0 if its wrong/fake.
// Will return 1 if its correct/real.
int dateChecker(int year, int months, int day)
{
    // All the days in every month, starting from January, last one is december.
    int lastDayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // if month is less than 1 ORR more than 12 its worng.
    if (months <= 0 || months >= 13)
    {
        return 1;
    }
    // check for leap year because of february
    else if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        lastDayInMonth[1] = 29;
        return (day > 0 && day <= lastDayInMonth[months - 1]);
    }
}

int theLuhn(const char *number)
{
    int sum = 0;
    int length = strlen(number);
    int num = 1;

    for (int i = length - 1; i >= 0; i--)
    {
        if (!isdigit(number[i]))
        {
            return 0;
        }
        int digit = number[i] - '0'; //
        if (num)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
            sum += digit;
            num = !num;
        }
        return (sum % 10 == 0);
    }
}

int validatePersonnummer(const char *personnummer)
{
    if (strlen(personnummer) != 11)
        return 0;

    char dateStr[7];
    strncpy(dateStr, personnummer, 6);
    dateStr[6] = '\0';

    int year = atoi(dateStr) / 10000;
    int month = (atoi(dateStr) % 10000) / 100;
    int day = atoi(dateStr) % 100;

    if (!dateChecker(year, month, day))
        return 0;
    return theLuhn(personnummer);
}
