#include <stdio.h>

int main(void){

    unsigned int uintNumber = 0;
    printf("Write a num:\n");
    scanf(" %i", &uintNumber);

    int n = 0;
    for (int i = 0; i<=uintNumber; i+=2){
        n += i;
    }
        printf(" %i", n);

    return 0;
}
