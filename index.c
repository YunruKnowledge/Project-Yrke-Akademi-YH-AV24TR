#include <stdio.h>

void main(){
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num == 80085){
        printf("\033[0;37m (\033[0;31m.\033[0;37m)(\033[0;31m.\033[0;37m) \n");
        return;
    }
    
    printf("You are gay \n");
}