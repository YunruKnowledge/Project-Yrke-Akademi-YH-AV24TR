#include <stdio.h>

#define RANGE 1000

int main(){
    int i = 0;

    while (i <= RANGE){
        int lastDigit = i % 10;
        if(lastDigit == 7){
            printf("%i \n", i);
            continue;
        }
        i++;
    }

    return 0;
}