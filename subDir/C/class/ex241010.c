
#include <stdio.h>
#include <string.h>

struct user
{
    int _oid;
    char name[32];
    char password[128];
};

union userUnion
{
    int _oid;
    char name[32];
    char password[128];
};

int main(void)
{
    struct user users[4];
    users[0]._oid = 1101;
    strcpy(users[0].name, "JOhn Smith");
    strcpy(users[0].password, "forgor12");

    users[1]._oid = 1102;
    strcpy(users[1].name, "Johnnny Smith");
    strcpy(users[1].password, "forgor21");

    users[2]._oid = 1103;
    strcpy(users[2].name, "Smithen Johnny");
    strcpy(users[2].password, "Forgot#");

    users[3]._oid = 1104;
    strcpy(users[3].name, "Gwen Ripper");
    strcpy(users[3].password, "Isolde3");

    for (int i = 0; i < 4; i++)
    {
        printf("\nuser[%i]\n", i);
        printf("%i\n", users[i]._oid);
        printf("%s\n", users[i].name);
        printf("%s\n", users[i].password);
    }

    printf("\n#############################################32 union\n");

    union userUnion user5;
    user5._oid = 1105;
    strcpy(user5.name, "JOhn Smith");
    strcpy(user5.password, "forgor12");

    union userUnion user6;
    user6._oid = 1106;
    strcpy(user6.name, "Swithy Hon");
    strcpy(user6.password, "21Zorut");

    union userUnion user7;
    user7._oid = 1106;
    strcpy(user7.name, "Mother Hah");
    strcpy(user7.password, "mommywoommy");

    printf("\nuser5\n");
    printf("%i\n", user5._oid);
    printf("%s\n", user5.name);
    printf("%s\n", user5.password);
    printf("\nuser6\n");
    printf("%i\n", user6._oid);
    printf("%s\n", user6.name);
    printf("%s\n", user6.password);
    printf("\nuser7\n");
    printf("%i\n", user7._oid);
    printf("%s\n", user7.name);
    printf("%s\n", user7.password);
}