//bool
//length strlen()
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DAYS 12


int dateChecker(int year, int months,int day);
int theLuhn(const char *number);

int main(void){




    return 0;
}


//To check for date if its real or not, takes 3 arguments and will return 0 if its wrong/fake.
//Will return 1 if its correct/real.
int dateChecker(int year, int months,int day){
    //All the days in every month, starting from January, last one is december.
    int lastDayInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //if month is less than 1 ORR more than 12 its worng.
    if (months <= 0 || months >= 13){
        return 0;
        printf("Wrong details!");
    }
    //check for yeap year
    else if(year % 4 == 0 && (year % 100 != 0 || year% 400 == 0)){
        day[1] = 29;
        return (day > 0 && day <= lastDayInMonth[months - 1]);
    }
}

int theLuhn(const char *number){
    int sum = 0;
    int length = strlen(number);
    int num = 1;
}