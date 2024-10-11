#include <stdio.h>
#include <string.h>

#define MAXUSERS 3

struct user {
    int id; 
    char name[20]; 
    char password[30];
};

int main(void){
//loading thing.
// bir anaLoop, icinde loop1 9 a yetisene kaadar print yapiyor. altinda bir loop2 9 ile basliyip -i.

    int n = 9;
    
   for (int i = 0; i <= n; i++){
    
    printf("[");
    for (int j = 0; j <= i; j++){
        printf("#");
        fflush(stdout);
    }

        for (int a = n; a > i; a--){
            printf("-");
            fflush(stdout);
        }
    printf("]\n");
    fflush(stdout);
    sleep(1);
    } 


/*
    printf("[#------]\n");
    sleep(1);printf("[##-----]\n");
    sleep(1);printf("[###----]\n");
    sleep(1);printf("[####---]\n");
    sleep(1);printf("[#####--]\n");
    sleep(3);printf("[######-]\n");
    sleep(1);printf("[#######]\n");
    sleep(1);

    printf("THE PROGRAM LOADED.\n");
    sleep(3);
    printf("**LOADED**\n--LAUNCHING NOW--\n");
    sleep(4);
    */

//App below
    int usersAmount;
    
    printf("How many users would you like to create? (MAX 3): ");
    scanf("%i", &usersAmount);

    if (usersAmount > MAXUSERS){
        printf("You've entered more users than the limit...\n The program will close now.\n You may restart it if you wish to.");
        return 1;
    }

    struct user userData[MAXUSERS];///Macro for struct amounts to compensate the users.

    for (int i = 0; i<MAXUSERS; i++){
        printf("User %i\n", i);
    printf("What is your ID?: ");
    scanf("%i", &userData[i].id);

    printf("Input name MAX 20 characters: ");
    scanf("%s", userData[i].name);

    printf("Input a password: ");
    scanf("%s", userData[i].password);

    }

    for (int i = 0; i < usersAmount; i++){

    printf("The data you provided is below\n --- --- --- --- --- --- --- --- --- ---\n User ID: %i\n User Name: %s \n User Password: %s ", userData[i].id, userData[i].name, userData[i].password);
    }

    return 0;
}