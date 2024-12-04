// Created with by ChatGPT, *is edited.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STRING_BUFFER 128
#define FILENAME "users.bin"
#define USER_CREATE 1
#define USER_READ 2
#define USER_UPDATE 3
#define USER_DELETE 4
#define USER_EXIT 5

typedef struct User {
  char name[STRING_BUFFER];
  size_t id;
} user_t;

/**
 * @brief Clear for pesky scanf invalids.
 *
 */
static void scanfFlush();

/**
 * @brief Prompts for user input and options.
 *
 * @param _input Pointer to apply final input to.
 * @param _isEmpty Bool, if new file.
 */
static void askForInput(unsigned int *_input, const bool _isEmpty);

/**
 * @brief Print all users.
 *
 * @param _users Pointer to users.
 * @param _amount Amount to print.
 */
static void printUsers(const user_t _users[], const int _amount);

/**
 * @brief Reads to see size using ftell.
 *
 * @param _file_name PATH to file.
 * @param _size_t_ptr Pointer to apply size to.
 * @return `true` upon success.
 */
static bool readFileSize(const char *_file_name, size_t *_size_t_ptr);

/**
 * @brief Reads .bin and print, applying last to _user.
 *
 * @param _file_name PATH to file.
 * @param _user Pointer to apply last user.
 * @param _amount Amount of users to read.
 * @param _offset Offset in count of users.
 * @return `true` upon success.
 */
static bool readUser(const char *_file_name, user_t *_user,
                     const size_t _amount, const size_t _offset);

/**
 * @brief Write all users to file.
 *
 * @param _file_name PATH to file.
 * @param _users Users to write.
 * @param _amount Amount to write in.
 * @return `true` upon success.
 */
static bool writeUsers(const char *_file_name, const user_t _users[],
                       const size_t _amount);

/**
 * @brief Applies the decoded users to a pointer.
 *
 * @param _file_name PATH to file.
 * @param _users Pointer to apply users to.
 * @param _amount Amount of users.
 * @return `true` upon success.
 */
static bool applyUsers(const char *_file_name, user_t _users[],
                       const size_t _amount);

/**
 * @brief Updates the user with the ID -with a new name.
 *
 * @param _file_name PATH to file.
 * @param _id Which ID refrence to replace name with.
 * @param _new_name String for name replacement.
 * @return `true` upon success.
 */
static bool updateUser(const char *_file_name, const size_t _id,
                       const char *_new_name);

/**
 * @brief Write a temp copy file, without the selected ID user. Then replace
 * original.
 *
 * @param _file_name PATH to file.
 * @param _id Which ID refrence to delete.
 * @param _user_amount Total amount of users in file.
 * @return `true` upon success.
 */
static bool deleteUser(const char *_file_name, const size_t _id,
                       const size_t _user_amount);

int main() {
  (void)printf("Program start.\n");
  unsigned int input;
  size_t inputIndex = 0;
  char inputString[STRING_BUFFER];
  bool isExiting = false;
  user_t *users = NULL;
  size_t fileSize = 0;

  do {
    if (readFileSize(FILENAME, &fileSize)) {
      size_t userAmount = (fileSize / sizeof(user_t));
      (void)printf("\nFILE_NAME: \"%s\" | FILE_SIZE: %lu bytes | USERS: %lu\n",
                   FILENAME, fileSize, userAmount);

      askForInput(&input, (userAmount == 0));

      switch (input) {
      case USER_CREATE:
        users = (user_t *)calloc(userAmount + 1, sizeof(user_t));
        if (users != NULL) {
          if (!applyUsers(FILENAME, users, userAmount)) {
            break;
          }

          (void)printf("Enter name. "
                       "(No spaces. E.g. Space_B4R?)"
                       "(Max. 128 chars)\n");
          (void)printf("Name: ");
          scanf("%128s", inputString);

          strcpy(users[userAmount].name, inputString);
          if (userAmount > 0) {
            users[userAmount].id = users[userAmount - 1].id + 1;
          } else {
            users[userAmount].id = userAmount + 1;
          }

          if (!writeUsers(FILENAME, users, userAmount + 1)) {
            break;
          }

          free(users);
          users = NULL;
        } else {
          (void)printf("\nCalloc failed, unable to create.\n");
        }
        break;

      case USER_READ:
        users = (user_t *)calloc(1, sizeof(user_t));
        if (users != NULL) {
          readUser(FILENAME, users, userAmount, 0);
          free(users);
          users = NULL;
        } else {
          (void)printf("\nMalloc failed, unable to read.\n");
        }
        break;

      case USER_UPDATE:
        (void)printf("Enter an index for edit. (user ID)\n");
        (void)printf("ID: ");
        while (scanf("%lu", &inputIndex) != 1 && inputIndex < userAmount &&
               inputIndex > 0) {
          scanfFlush();
        }

        (void)printf("Enter a new name. "
                     "(No spaces. E.g. Space_B4R?) "
                     "(Max. 128 chars)\n");
        (void)printf("Name: ");
        scanf("%128s", inputString);

        if (!updateUser(FILENAME, inputIndex, inputString)) {
          break;
        }

        break;

      case USER_DELETE:
        (void)printf("Enter an index for edit. (user ID)\n");
        (void)printf("ID: ");
        while (scanf("%lu", &inputIndex) != 1 && inputIndex < userAmount &&
               inputIndex > 0) {
          scanfFlush();
        }

        if (!deleteUser(FILENAME, inputIndex, userAmount)) {
          break;
        }

        break;

      default:
        (void)printf("Exiting...\n");
        isExiting = true;
        break;
      }
    } else {
      (void)printf("\nUnable to open file for reading.\n");
      (void)printf("Exiting...\n");
      isExiting = true;
    }
  } while (!isExiting);

  if (users != NULL) {
    free(users);
    users = NULL;
  }

  return 0;
}

static void scanfFlush() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

static void askForInput(unsigned int *_input, const bool _isEmpty) {
  unsigned int _temp = 0;
  if (!_isEmpty) {
    (void)printf("Select an option.\n");
    (void)printf("1. Create record.\n");
    (void)printf("2. Read record.\n");
    (void)printf("3. Update record.\n");
    (void)printf("4. Delete record.\n");
    (void)printf("5. Exit.\n");
    (void)printf("Input: ");

    while (scanf("%u", &_temp) != 1 && _temp > USER_DELETE) {
      scanfFlush();
      (void)printf("Invalid input try again.\n");
    }
  } else {
    (void)printf("***NO DATA FOUND OR IS CORRUPTED.***\n");
    (void)printf("***MAKE SURE FILE IS EMPTY BEFORE CREATING RECORD.***\n");
    (void)printf("***CREATING RECORD WILL OVERWRITE FILE DATA.***\n");
    (void)printf("Select an option.\n");
    (void)printf("1. Create record.\n");
    (void)printf("5. Exit.\n");
    (void)printf("Input: ");

    while (scanf("%u", &_temp) != 1 && _temp != USER_CREATE &&
           _temp < USER_DELETE) {
      scanfFlush();
      (void)printf("Invalid input try again.\n");
    }
  }
  *_input = _temp;
}

void printUsers(const user_t _users[], const int _amount) {
  printf("ID\tName\n");
  printf("------------\n");
  for (int i = 0; i < _amount; i++) {
    printf("%d\t%s\n", _users[i].id, _users[i].name);
  }
}

static bool readFileSize(const char *_file_name, size_t *_size_t_ptr) {
  bool _isSuccess = false;
  FILE *_file = fopen(_file_name, "rb");
  if (_file != NULL) {
    fseek(_file, 0L, SEEK_END);
    *_size_t_ptr = (size_t)ftell(_file);
    _isSuccess = true;
    fclose(_file);
  } else {
    (void)printf("Could not read/find file: [%s].\n", _file_name);
  }
  return _isSuccess;
}

static bool readUser(const char *_file_name, user_t *_user,
                     const size_t _amount, const size_t _offset) {
  bool _isSuccess = false;
  FILE *file = fopen(_file_name, "rb");
  if (file != NULL && _amount > 0) {
    fseek(file, sizeof(user_t) * _offset, SEEK_CUR);
    (void)printf("ID\tName\n");
    (void)printf("------------\n");
    for (size_t i = 0; i < _amount; i++) {
      fread(_user, sizeof(user_t), 1, file);
      (void)printf("%d\t%s\n", _user->id, _user->name);
    }

    fclose(file);
    _isSuccess = true;
  } else {
    (void)printf("Failed to open file for reading.\n");
  }
  return _isSuccess;
}

static bool writeUsers(const char *_file_name, const user_t _users[],
                       const size_t _amount) {
  bool _isSuccess = false;
  FILE *_file = fopen(_file_name, "wb");
  if (_file != NULL) {
    fwrite(_users, sizeof(user_t), _amount, _file);
    fclose(_file);
    _isSuccess = true;
  } else {
    (void)printf("Failed to open file for writing.\n");
  }
  return _isSuccess;
}

static bool applyUsers(const char *_file_name, user_t _users[],
                       const size_t _amount) {
  bool _isSuccess = false;
  FILE *_file = fopen(_file_name, "rb");
  if (_file != NULL) {
    fread(_users, sizeof(user_t), _amount, _file);
    fclose(_file);
    _isSuccess = true;
  } else {
    (void)printf("Failed to open file for reading.\n");
  }
  return _isSuccess;
}

static bool updateUser(const char *_file_name, const size_t _id,
                       const char *_new_name) {
  bool _isSuccess = false;
  FILE *_file = fopen(_file_name, "r+b");
  if (_file != NULL) {
    user_t _user;
    while (fread(&_user, sizeof(user_t), 1, _file)) {
      if (_user.id == _id) {
        strncpy(_user.name, _new_name, STRING_BUFFER - 1);
        _user.name[STRING_BUFFER - 1] = '\0';

        fseek(_file, -sizeof(user_t), SEEK_CUR);
        fwrite(&_user, sizeof(user_t), 1, _file);
        break;
      }
    }
    fclose(_file);
    _isSuccess = true;
  } else {
    (void)printf("Failed to open file for updating.\n");
  }
  return _isSuccess;
}

static bool deleteUser(const char *_file_name, const size_t _id,
                       const size_t _user_amount) {
  bool _isSuccess = false;
  FILE *_file = fopen(_file_name, "rb");
  FILE *_temp_file = fopen("temp.bin", "wb");
  if (_file != NULL && _temp_file != NULL) {

    user_t _user;
    size_t _loop = 0;
    bool _found = false;

    while (fread(&_user, sizeof(user_t), 1, _file) && _loop < _user_amount) {
      if (_user.id != _id) {
        fwrite(&_user, sizeof(user_t), 1, _temp_file);
      } else {
        _found = true;
      }
      _loop++;
    }

    fclose(_file);
    fclose(_temp_file);

    if (_found) {
      if (remove(_file_name) != 0) {
        (void)printf("Failed to remove the original file.\n");
      }
      if (rename("temp.bin", _file_name) != 0) {
        (void)printf("Successfully deleted original file but ");
        (void)printf("failed to rename temporary file.\n");
      } else {
        _isSuccess = true;
      }
    } else {
      remove("temp.bin");
    }

  } else {
    (void)printf("Failed to open file for reading and or writing.\n");
  }

  return _isSuccess;
}