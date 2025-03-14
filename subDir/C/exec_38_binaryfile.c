// Created with by ChatGPT, *is edited.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 4
#define MAX 8
#define FILENAME "users.bin"

typedef struct {
  int id;
  char name[MAX];
} user_t;

void getRandomName(char *_name);
void fillUsers(user_t _users[], const int _size);
void printUsers(const user_t _users[], const int _size);
void writeUsers(const char *_file_name, const user_t _users[], const int _size);
void readUsers(const char *_file_name, user_t _users[], const int _size);
void updateUser(const char *_file_name, const int _id, const char *_new_name);

int main() {
  // 1. Create array
  user_t users[MAX_USERS];
  srand((unsigned int)time(NULL));

  // 2. Fill users
  fillUsers(users, MAX_USERS);

  // 3. Print users
  printf("Set users:\n");
  printUsers(users, MAX_USERS);

  // 4. Write users to a file as binary
  writeUsers(FILENAME, users, MAX_USERS);

  // 5. Read users back from the file
  user_t decodedUsers[MAX_USERS];
  readUsers(FILENAME, decodedUsers, MAX_USERS);

  printf("\nDecoded users from file:\n");
  printUsers(decodedUsers, MAX_USERS);

  // 6. Find and change username based on id
  char new_name[MAX] = "NEWNAME";
  updateUser(FILENAME, 2, new_name);

  readUsers(FILENAME, decodedUsers, MAX_USERS);
  printf("\nUsers after Update:\n");
  printUsers(decodedUsers, MAX_USERS);

  return 0;
}

/**
 * @brief Function to generate a random name of 8 letters
 *
 * @param _name
 */
void getRandomName(char *_name) {
  for (int i = 0; i < MAX - 1; i++) {
    _name[i] = 'A' + rand() % 26;
  }
  _name[MAX - 1] = '\0';
}

/**
 * @brief Function to fill the users array with random data
 *
 * @param _users
 * @param _size
 */
void fillUsers(user_t _users[], const int _size) {
  for (int i = 0; i < _size; i++) {
    _users[i].id = i + 1;
    getRandomName(_users[i].name);
  }
}

/**
 * @brief Function to print the users to the terminal
 *
 * @param _users
 * @param _size
 */
void printUsers(const user_t _users[], const int _size) {
  printf("ID\tName\n");
  printf("------------\n");
  for (int i = 0; i < _size; i++) {
    printf("%d\t%s\n", _users[i].id, _users[i].name);
  }
}

/**
 * @brief Function to write the users array to a binary file
 *
 * @param _file_name
 * @param _users
 * @param _size
 */
void writeUsers(const char *_file_name, const user_t _users[],
                const int _size) {
  FILE *file = fopen(_file_name, "wb");
  if (!file) {
    perror("Failed to open file for writing");
    exit(EXIT_FAILURE);
  }
  fwrite(_users, sizeof(user_t), _size, file);
  fclose(file);
}

/**
 * @brief Function to read the users array from a binary file
 *
 * @param _file_name
 * @param _users
 * @param _size
 */
void readUsers(const char *_file_name, user_t _users[], const int _size) {
  FILE *file = fopen(_file_name, "rb");
  if (!file) {
    perror("Failed to open file for reading");
    exit(EXIT_FAILURE);
  }
  fread(_users, sizeof(user_t), _size, file);
  fclose(file);
}

/**
 * @brief Function to update a name based on ID in the binary file
 *
 * @param _file_name
 * @param _id
 * @param _new_name
 */
void updateUser(const char *_file_name, const int _id, const char *_new_name) {
  FILE *file = fopen(_file_name, "r+b");
  if (!file) {
    perror("Failed to open file for updating");
    exit(EXIT_FAILURE);
  }

  user_t user;
  while (fread(&user, sizeof(user_t), 1, file)) {
    if (user.id == _id) {
      strncpy(user.name, _new_name, MAX - 1);
      user.name[MAX - 1] = '\0'; // Ensure null-termination
      fseek(file, -sizeof(user_t),
            SEEK_CUR); // Move file pointer back to overwrite
      fwrite(&user, sizeof(user_t), 1, file);
      break;
    }
  }
  fclose(file);
}