#include "studentRecordBin.h"
#include <stdio.h>
#include <string.h>

#define VALID_INPUT 1
#define NO_OFFSET 0

int main() {
  (void)printf("Program start.\n");
  char input = ' ';
  size_t inputIndex = 0;
  char inputString[STRING_BUFFER];
  int inputAge = 0;

  bool isExiting = false;
  size_t fileSize = 0, studentAmount = 0;
  student_t student;
  
  do {
    if (readFileSize(&fileSize)) {
      studentAmount = getStudentCount();
      (void)printf("\nFILE_NAME: \"%s\" | FILE_SIZE: %lu bytes | USERS: %lu\n",
                   FILENAME, fileSize, studentAmount);

      askUserOptions(&input);

      if (input == USER_CREATE) {

        (void)printf("Enter name. "
                     "(No spaces. E.g. Space_B4R?)"
                     "(Max. 32 chars)\n");
        (void)printf("Name: ");
        scanf("%32s", inputString);

        (void)printf("Enter an age for student.\nAge: ");
        while (scanf("%i", &inputAge) != VALID_INPUT) {
          (void)printf("Invalid input try again.\nAge: ");
          flushUserInput();
        }

        strcpy(student.name, inputString);
        student.age = inputAge;
        student.id = getNewStudentID();

        if (!writeStudent(&student)) {
          (void)printf("Student dropped... \nSTRUCT - Name: %s | Age: %i\n",
                       student.name, student.age);
        }

      } else if (input == USER_READ) {
        readFile(&student, studentAmount, NO_OFFSET, true);

      } else if (input == USER_UPDATE) {
        (void)printf("Enter an index for edit. (user ID)\nID: ");
        while (scanf("%lu", &inputIndex) != VALID_INPUT) {
          (void)printf("Invalid input try again.\nID: ");
          flushUserInput();
        }

        (void)printf("Enter a new name. "
                     "(No spaces. E.g. OnLINE_f4R) "
                     "(Max. 32 chars)\n");
        (void)printf("Name: ");
        scanf("%32s", inputString);

        (void)printf("Enter an age for student.\nAge: ");
        while (scanf("%i", &inputAge) != VALID_INPUT) {
          (void)printf("Invalid input try again.\nAge: ");
          flushUserInput();
        }

        if (!updateUser(inputIndex, inputString, inputAge)) {
          (void)printf("Update dropped... \nSTRUCT - Name: %s | Age: %i\n",
                       inputString, inputAge);
        }

      } else if (input == USER_DELETE) {
        (void)printf("Enter an index for edit. (user ID)\nID: ");
        while (scanf("%lu", &inputIndex) != VALID_INPUT) {
          (void)printf("Invalid input try again.\nID: ");
          flushUserInput();
        }

        if (!deleteUser(inputIndex, studentAmount)) {
          (void)printf("Looping to menu...\n");
        }
      } else {
        (void)printf("Exiting...\n");
        isExiting = true;
      }

    } else {
      (void)printf("\nUnable to open file for reading.\n");
      (void)printf("Exiting...\n");
      isExiting = true;
    }
  } while (!isExiting);

  return 0;
}
