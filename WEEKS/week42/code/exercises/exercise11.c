#include <stdio.h>
#include <ctype.h>//for char manipulation

int main(){

    //getchar to read chars
    //go through, capitalize, print to console.
    //only 1 space between names.
    //save each  character in a different var.
    //the char storing.

    int ch, previousChar = ' ';
    int isANewWord = 1;

    printf("enter full name:\n");

    while((ch = getchar()) !='\n'){
        //while ch is getchar NOT a end of the sentence
        if (isalpha(ch)){

            if(isANewWord){
            putchar(toupper(ch));
            isANewWord = 0;
            
        } else {
            putchar(tolower(ch));
        }
        previousChar = ch;
    } else if (isspace(ch) && !isspace(previousChar)){
        putchar(' ');
        isANewWord = 1;
        previousChar = ch;
    }
    }
    putchar('\n');
    return 0;
}