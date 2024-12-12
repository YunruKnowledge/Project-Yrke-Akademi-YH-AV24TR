
#ifndef MODULE_STUDENT_RECORD_BIN_H
#define MODULE_STUDENT_RECORD_BIN_H

#include <stdbool.h>
#include <stdlib.h>

#define STRING_BUFFER 32
#define FILENAME "studentRecordBin_db.bin"
#define OPTION_TRIES 5

#define USER_CREATE 'C'
#define USER_READ 'P'
#define USER_UPDATE 'U'
#define USER_DELETE 'D'
#define USER_EXIT 'E'

// Changing this will make previous bin files not readable.
typedef struct Student {
  unsigned int id;
  char name[STRING_BUFFER];
  int age;
} student_t;

/**
 * @brief flushes for pesky remainders.
 *
 */
void flushUserInput();

/**
 * @brief Get the count of readable students.
 * NEED readFileSize() to run first.
 * Divides filesize with count.
 *
 * @return size_t
 */
size_t getStudentCount(void);

/**
 * @brief Prompts the user menu. Menu adapts if file is empty or not.
 *
 * @param _input Address to apply the user input as.
 */
void askUserOptions(char *_input);

/**
 * @brief Calculate new ID based on lastest file and program session.
 *
 * @return int
 */
int getNewStudentID(void);

/**
 * @brief Reads the size by moving cursor and ftell back.
 *
 * @param _size_t_ptr Address to apply size to.
 * @return `true` upon success.
 */
bool readFileSize(size_t *_size_t_ptr);

/**
 * @brief Reads the file based on student_t chunks.
 *
 * @param _user Pointer to apply remainder student to.
 * @param _amount How many chunks are read.
 * @param _offset Skip how many chunks.
 * @param _verbose Prints students or not.
 * @return `true` upon success.
 */
bool readFile(student_t *_user, const size_t _amount, const size_t _offset,
              const bool _verbose);

/**
 * @brief Write into bin file.
 *
 * @param _student Pointer of student to append into file.
 * @return `true` upon success.
 */
bool writeStudent(const student_t *_student);

/**
 * @brief Reads and finds matching ID, replace chunk with new chunk.
 * 
 * @param _id ID to match with.
 * @param _new_name String of name.
 * @param _new_age Age.
 * @return `true` upon success.
 */
bool updateUser(const size_t _id, const char *_new_name, const int _new_age);

/**
 * @brief Reads and copy chunks into a temp file, skipping matching ID. 
 * 
 * @param _id ID to skip.
 * @param _user_amount How many chunks to copy.
 * @return `true` upon success.
 */
bool deleteUser(const size_t _id, const size_t _user_amount);

#endif