/*
Make a C program to define a structure type (user_t)  with name(8 letters) and unique id members. Then

1) Make an array of user_t
2) Make a function to fill users with random names and unique ids started from 1
3) Make a function to print the users to a terminal
4) Make a function to write the users to a binary file
5) Make a function to read the users from the file
6) Make a function to change a user name base on its id in the file

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_USERS 4
#define MAX 20
typedef struct user
{
    char name[MAX];
    int uniqueID;
} user_t;

void randNum(user_t *_users, int _maxUsers)
{
    for (int i = 0; i < _maxUsers; i++)
    {
        _users[i].uniqueID = i + 1;
        // printf("ID is %i", i);
        randName(_users[i].name);
    }
}
void randName(char *_name)
{
    for (int i = 0; i < MAX - 1; i++)
    {
        _name[i] = 'A' + rand() % 26;
    }
    _name[MAX - 1] = '\0';
}
void printTerminal(user_t *_users)
{
    for (int i = 0; i < MAX_USERS; i++)
    {
        printf("user %i\nName: %s\nID: %i\n\n", i+1, _users[i].name, _users[i].uniqueID);
    }
}

int main()
{
    user_t arrOfUsers[MAX];
    srand(time(NULL));

    randNum(arrOfUsers, MAX_USERS);
    printTerminal(arrOfUsers);

    return 0;
}
