#include <stdio.h>
#include <string.h>

struct fakeObject {
    int age;
    char name[100];
    char slogan[100];
};

int main(void) {
    
    struct fakeObject nobject;
    
    strcpy(nobject.name, "PykeFumosson");
    nobject.age = 40;
    
    // Uncomment this line to assign the slogan
    strcpy(nobject.slogan, "Captains told me to catch the fumonsters, but the fumonsters told me to hunt Captains");

    // Print the slogan only if it's initialized
    printf("Your age is: %d,\nYour name is: %s,\nYour favourite line is: %s\n", nobject.age, nobject.name, nobject.slogan);
    
    return 0;
}

