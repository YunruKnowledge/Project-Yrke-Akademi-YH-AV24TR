#include <stdio.h>

int main(void){
    //a for loop to loop through all the chars of an array.
    //if space printf \n

    char name[20];
    printf("Input a name: ");
    scanf(" %s", &name);

    printf(" %s", name);

}