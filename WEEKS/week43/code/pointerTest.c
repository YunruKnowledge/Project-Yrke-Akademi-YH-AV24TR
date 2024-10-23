#include <stdio.h>

char name[9] = "Go Home";
char *p = name;

int main(void){
//Faroch example below
/*
    char myName[8] = "Ehmet";//array with Name
    const char *name1 = "Okhmet";//pointer, out of the Okhmet that it points to, due to the variables type, it can only hold the O of this variable.
    char *firstLetterOfName1 = (char *)name1;//point to the first char of Akhmet
    char **pp = &firstLetterOfName1;

    *pp = myName;
    *firstLetterOfName1 = 'F';
    **pp = 'A';
    *(*pp+5) = 'S';
    printf("%s\n", firstLetterOfName1);
*/
//different test below
    char **pp = &p;//double asterisk,bcz im pointing to a pointer
    char ***ppp = &pp;

    *(**ppp+2) = 'j';
    *(**ppp+3) = 'o';
    *(**ppp+4) = ' ';
    *(**ppp+5) = ' ';
    *(**ppp+6) = 'O';
    *(**ppp+7) = 'P';
    // *(**ppp+8) = '\0';

    printf("ptrAddress: %p\nThe manipulatedName: %s\n", pp, **ppp);//The value that the pointer is pointing to.
return 0;
}