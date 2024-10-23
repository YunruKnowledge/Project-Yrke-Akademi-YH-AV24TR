#include <stdio.h>
#include <stdbool.h>

bool isAPrimeNumber(int num);

int main(void){
    startAgain:
    int theNum = 0;
    printf("Input a number between 2 and 10k:\n");
    scanf("%i", &theNum);

    if (theNum <= 1){
        printf("I said above 2!\n");
        goto startAgain;
    }else if(theNum >= 10001){
        printf("I said max 10k!\n");
        goto startAgain;
    }else{
        if (isAPrimeNumber(theNum)){
            printf("The number %d is a prime number!", theNum);
        }else{
            printf("The number %d was NOT a prime numer.", theNum);
        }
    }
    return 0;
}

bool isAPrimeNumber(int num){
    //check for numbers that are less than 2
    if (num <= 2){
        return false;
    }
    //check divisability from 2 upto num-1
    for (int i = 2; i < num; i++){
        if (num % i == 0){
            return false;// if divisible by any number other than 1 and itself
        }
    }
    return true;
}