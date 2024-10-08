#include <stdio.h>
#include <stdint.h>

#define NUM 8
#define BIGN 9

int main(void){

//testing macro if
#if NUM == 8

    char home[5] = "shit";

    printf("%s\n", home);
#endif


//testing while with macro
int n=0;
while (n != BIGN)
{
    n++;
    printf("%d", n);
}

//const to be changed trough a var?
printf("Write a number");
int var = scanf("%d", &var);
const int testCon = var;
printf("Your const num is: %d\n", testCon);

enum Sweeden {year, month};

for (int i = year; i <= month; i++)
{
    printf("%d", i);
}


// printf("My fav topping is: %d\n", year2);

return 0;
}