#include <stdio.h>
#include <ctype.h>

int main(void){

int theNum = 0;
scanf(" %i", &theNum);

if (isdigit(theNum)){
    printf(" %i", theNum);
}
else{
    printf("Wrong!");
}

return 0;
}