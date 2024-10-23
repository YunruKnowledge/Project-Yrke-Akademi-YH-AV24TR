#include <ctype.h>
#include <stdio.h>

char printf(char deez){
    while ((deez = getchar()) != EOF) {
        if (deez == '\n')
            break;  
    
        if (tolower(deez) == 'a' || tolower(deez) == 'e' || tolower(deez) == 'i' || tolower(deez) == 'o' || tolower(deez) == 'u'){
            return printf("%c", deez);
        }
    }
}

int main() {
    char deez;
    printf(deez);
    printf("\n");
    return 0;
}
