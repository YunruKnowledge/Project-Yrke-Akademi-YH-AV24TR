#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(){
    char *name, *aftername;

    system("clear");

    printf("Enter your name: ");
    scanf("%s", &*name);

    printf("Enter your name: ");
    scanf("%s", &*aftername);

    for (int i = 0; i < sizeof(name); i++)
    {
        if (name[i] >= 'a' && name[i] <= 'z' && i == 0)
            name[i] = toupper(name[i]);
        else if (name[i] >= 'A' && name[i] <= 'Z' && i != 0)
            name[i] = tolower(name[i]);
    }

    for (int i = 0; i < sizeof(aftername); i++)
    {
        if (aftername[i] >= 'a' && aftername[i] <= 'z' && i == 0)
            aftername[i] = toupper(aftername[i]);
        else if (aftername[i] >= 'A' && aftername[i] <= 'Z' && i != 0)
            aftername[i] = tolower(aftername[i]);
    }

    system("clear");
    printf("%s %s \n", name, aftername);

    return 0;
}
