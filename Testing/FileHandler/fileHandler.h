#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdio.h>
#include <stdbool.h>

#define FILE_NAME "text.bin" // Name + extention for file

#define MAX_USER_AMOUNT 10 // Max amount of users allowed in file!
#define BUFFER 32 // Length of a input name

// Student Struct
typedef struct USER t_user;

FILE *createFile();
// A function to create user struct (size for correctly allocating memory usage, file for safety close if struct couldn't be created!)
t_user *createUserStract(int size, FILE *file);

// A function to return true if successfully added user to stack (**user for strcut, *file for the file itself, amount for amount of new users you want to add!)
bool createUser(t_user **user, FILE *file, int amount);
// A function to push struct into a binary file (**user for strcut, *file for the file itself, amount for amount of new users you want to add!)
void addUsersToFile(t_user *user, FILE *file, int amount);
// A function to display all users from a file (**user for strcut, *file for the file itself, amount for amount of new users you want to add!)
void displayAllUsers(FILE *file, t_user *user, int amount);
// A function to delete user of ID from a file (**user for strcut, *file for the file itself, ID of a user that you want to delete, amount for amount of new users you want to add!)
void deleteUser(FILE *file, t_user *user, int id, int *amount);
// A function to modify user of ID from a file (**user for strcut, *file for the file itself, ID of a user that you want to modify, amount for amount of new users you want to add!)
void modifyUser(FILE *file, t_user *user, int id, int amount);

// A function to return how many users are in a file
int getUserAmount(FILE *file);

#endif // !FILE_HANDLER_H