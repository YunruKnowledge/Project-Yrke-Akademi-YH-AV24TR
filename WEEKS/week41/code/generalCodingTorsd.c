#include <stdio.h>
#include <ctype.h>//for upper&lowercase letters differentiation.
#include <time.h>
#include <stdlib.h>//for randomizing func

struct date_t {
    int day; int month; int year;
};

int main(void){

//lowercase to upper converter, Library and ASCII methods.

    /*char letter = 'a';

    printf("enter a lowercase letter!:___");
    scanf("%c", &letter);

    printf("%c", letter - 32);//ASCII hacking.

    letter = toupper(letter);//With library ctype.h
    printf("Heres the uppercase version: %c", letter);
    */

//Random num generator.

/*
    srand(time(0));//the random func needs to be seeded with a initial value.

    int randomNum = rand() %10;
    printf("the RANDOM NUM: %i", randomNum);
*/

    //EXERCISE 7, use struct to take in date values and print them back to consol.
   /* struct date_t dateByUser;
    printf("What year?: \n");
    scanf("%i", &dateByUser.year);
    
    printf("What month is it?: ");
    scanf("%i", &dateByUser.month);

    printf("What day is it?: ");
    scanf("%i", &dateByUser.day);

    printf("The date is: %i-%i-%i", dateByUser.year, dateByUser.month, dateByUser.day); 
*/

    //SINGLE LINE IF ELSE
int b = 2;
    int a = 1; 
    a = (a<b) ? (a*b) : (a+1);
//  a = (condi) if (doThis) else (this);
    printf("%i\n", a);
    int c = 3;
    c *= 2;
    printf("%i", c);
    return 0;
}