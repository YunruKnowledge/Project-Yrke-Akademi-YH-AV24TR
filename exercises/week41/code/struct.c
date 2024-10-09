#include <stdio.h>
#include <string.h>

    struct fakeObject {
        int age;
        enum Skill { Hook, Punch, Belittle} skill;
        char name[20];
        char slogan[87];
    };

int main(void){
    struct fakeObject nobject;
    strcpy(nobject.name, "Pyke Fumosson");
    nobject.age = 40;
    strcpy(nobject.slogan, "Captains told me to catch the fumonsters, but the fumonsters told me to hunt Captains");

    printf("Your age is: %d,\n Your name is: %s.\nYour favourite line is: %s.", nobject.age, nobject.name, nobject.slogan);
}