#include <stdio.h>

#define NUM 2

int square(int num);
int averageOfThreeNum(int a, int b, int c);
char getString(char *string, int length);

int main(void){
    printf("%d \n", square(NUM));
    printf("%d \n", averageOfThreeNum(3, 5 ,9));
    getString("Hello", 5);
}

int square(int num){
    return num * num;
}

int averageOfThreeNum(int a, int b, int c){
    return (a + b + c) / 3;
}

char getString(char string[], int length){
    for (int i = 0; i < length; i++)
    {
        printf("%c \n", string[i]);
    }
    return 0;
}