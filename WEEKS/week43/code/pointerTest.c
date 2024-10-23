#include <stdio.h>

char name[50] = "noWay";
char *ptrToName = name;
int main(void){
//Faroch example below
/*
    const char *name1 = "Okhmet";//pointer
    char myName[8] = "Ehmet";//array with Name
    char *firstLetterOfName1 = (char *)name1;// point to the first char of Akhmet
    char **pp = &firstLetterOfName1;

    *pp = myName;
    *firstLetterOfName1 = 'F';
    **pp = 'A';
    *(*pp+5) = 'S';
    printf("%s\n", firstLetterOfName1);
*/
//different test below
    char **ptr = &ptrToName;//double asterisk,bcz im pointing to a pointer
    printf("ptr: %c\n", **ptr);

}
