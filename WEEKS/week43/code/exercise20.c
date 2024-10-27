/*
Description
Make a program to read date and time from a terminal and then
check if the entered date and time is in the format of YYYY-MM-DD HH:mm:ss or not.
*/

//if char 4&7 is -, print the date. else continue the while loop.
#include <stdio.h>

int main(){
    startGame:
    const int lengthOfChars = 20;
    char amountOfChars[lengthOfChars];

    printf("Enter date in format=> |YYYY-MM-DD HH:mm:ss|\n");
    fgets(amountOfChars, sizeof(amountOfChars), stdin);

        if ( (amountOfChars[4] != '-' || amountOfChars[7] != '-' || amountOfChars[10] != ' ' || amountOfChars[13] != ':' || amountOfChars[16] != ':') && amountOfChars[20] == '\0'){
            printf("Wrong format, try again!\n");
            goto startGame;
        }else{
            printf("Your input was correct, so you can follow simple instructions!\nHeres what you wrote %s\n", amountOfChars);

        }



return 0;
}