#include <stdio.h>
#include <string.h>
#include <ctype.h>


void reverse(char* nameCmpr);

int main(void){
    char name[20] = "way";
    char name2[20];
    printf("Write a name to ccheck:\n");
    scanf(" %s", name);
printf(" You chose: %s\n", name);
    strcpy(name2, name);
    /* char name2[] = " ";
     int halfOfName = sizeof(name)/2;
     int sizeOfName = sizeof(name);
     char firstHalfName = 'f';*/

    reverse(name);

    if (strcmp(name,name2) ==  0){
        printf("This is a Palindrome, meaning it will be read the same in reverse.\nYou had entered %s.", name);
        return  0;
    }else{
        printf("The word %s is NOT a Palindrome.", name);
        return 0;
    }

    //iterate and add += the half of name
    //iterate through rest of half of the name and add it to name2
    //compare the 2.
   /* for(int i = 0; i<=halfOfName; i++){
        firstHalfName += name[i];
    for (int i = sizeOfName; i>=sizeOfName; i--){
        name[i] = name2[i];
    }
    }*/
    /*for (int i = 0; i <= name[i]; i++){
        printf("%c",name[i]);

    if (name[halfOfName] == name[(halfOfName+1)]){

    printf("its a Palindrome and half of name is %i",halfOfName);
    }
    }*/
return 1;     

}

void reverse(char* name){

    int first = 0;
    int last = strlen(name) - 1;
    char temp;

    while (first < last) {

        temp = name[first];
        name[first] = name[last];
        name[last] = temp;

        first++;
        last--;
    }
}