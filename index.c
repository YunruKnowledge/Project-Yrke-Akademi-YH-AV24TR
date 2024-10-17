#include <stdio.h>

#define RANGE 1000

int main(){
    int i = 0;
    while (i <= RANGE){
        if(i % 10 == 7){
            printf("%i \n", i);
        }
        i++;
    }

    return 0;
}