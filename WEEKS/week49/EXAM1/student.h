#ifndef STUDENT_H
#define STUDENT_H

typedef struct student student_t;

/**
 * @brief Displays a menu that the user can chose what action to take.
 * 
 */
void displayMenu();

/**
 * @brief Loads structs of students from the binary file.
 * 
 */
void loadStudentfromFile();

/**
 * @brief Saves the students information into the file.
 * 
 */
void saveToFile();


/**
 * @brief Create a User object that is of type struct with these values: ID, Name, Age.
 * 
 */
void createUser();

/**
 * @brief Prints the users to the terminal.
 * 
 */
void readStudents();

/**
 * @brief Lets the user to update data of each users struct through the terminal.
 * 
 */
void updateStudent();

/**
 * @brief Deletes the selected user by identifying the ID, shifting the user over the student that is going to be deleted.
 * 
 */
void deleteStudent();


/**
 * @brief Takes a char of users choice, returns a number instead to be used in switch:case condition.
 * 
 * @param choice is a char, being converted into a int to be used with switch:case.
 * @return int that is choice char converted into a num value to be used in the function.
 */
//  take inn the char choice, convert, return choiceNum as int.
int choiceConverter(char choice);


#endif //STUDENT_H