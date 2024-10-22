#include <stdio.h>
#include <string.h>

int main(void){
    char name[90];

    printf("Write a name:\n");
    scanf(" %s", name);

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
    printf("The name is %s", name);
}