#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdio.h>
#include <stdbool.h>

#define FILE_NAME "text.bin"

#define BUFFER 32
#define MAX_STUDENT_AMOUNT 10

typedef struct STUDENT student_t;

FILE *fileHandler_createFile();
// A function to create student struct (size for correctly allocating memory usage, file for safety close if struct couldn't be created!)
student_t *fileHandler_createStudentStract(int size, FILE *file);

// A function to return true if successfully added user to stack (**user for strcut, *file for the file itself!)
bool fileHandler_createStudent(student_t **student, FILE *file);
// A function to push struct into a binary file (**student for strcut, *file for the file itself, amount for amount of new students you want to add!)
void fileHandler_addStudentsToFile(student_t *student, FILE *file, int amount);
// A function to display all students from a file (**student for strcut, *file for the file itself, amount for amount of new students you want to add!)
void fileHandler_displayAllStudents(FILE *file, student_t *student, int amount);
// A function to delete student of ID from a file (**student for strcut, *file for the file itself, ID of a student that you want to delete, amount for amount of new students you want to add!)
void fileHandler_deleteStudent(FILE *file, student_t *student, int id, int *amount);
// A function to modify student of ID from a file (**student for strcut, *file for the file itself, ID of a student that you want to modify, amount for amount of new students you want to add!)
void fileHandler_modifyStudent(FILE *file, student_t *student, int id, int amount);

// A function to return how many students are in a file
int fileHandler_getStudentAmount(FILE *file);

#endif // !FILE_HANDLER_H