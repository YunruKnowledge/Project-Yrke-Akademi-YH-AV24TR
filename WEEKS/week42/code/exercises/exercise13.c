#include <stdio.h>
// #include <ctype.h>

int main(void){

int theNum = 0;
printf("Check for seven in the range of 0 and x, what is x?: ");
scanf(" %i", &theNum);

for (int i = 0; i<=theNum; i++){
    if (i % 10 == 7){
        printf("%i\n", i);
    }
}

return 0;
}

// if (isdigit(theNum)){
//     printf(" %i", theNum);
// }
// else{
//     printf("Wrong!");
// }