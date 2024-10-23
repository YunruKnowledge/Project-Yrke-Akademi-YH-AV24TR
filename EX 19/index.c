#include <stdio.h>
#include <string.h>

int main(){
    char *string = "I am a C programmer!";
    
    for (int i = 0; i < strlen(string); i++){
        if (string[i] == ' ')
            printf("\n");
        else
            printf("%c", string[i]);
    }
    printf("\n");
}