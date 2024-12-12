
#include "studentRecordBin.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SINGLE 1
#define NEXT 1
#define FRIST_ID 1
#define FILE_EDIT_SUCCESS 0

static size_t STUDENT_COUNT = 0;
static unsigned int GLOBAL_ID = 1;

void flushUserInput() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

size_t getStudentCount(void) { return STUDENT_COUNT; }

void askUserOptions(char *_input) {
  char _temp = 0;
  unsigned int _tries = 0;
  if (STUDENT_COUNT > 0) {
    (void)printf("** Select an option. ******\n");
    (void)printf("%c. Create A Student.\n", USER_CREATE);
    (void)printf("%c. Print All students.\n", USER_READ);
    (void)printf("%c. Update A Student.\n", USER_UPDATE);
    (void)printf("%c. Delete a Student.\n", USER_DELETE);
    (void)printf("%c. Exit.\n", USER_EXIT);
    (void)printf("Input: ");

  } else {
    (void)printf("***NO DATA FOUND OR IS CORRUPTED.***\n");
    (void)printf("***MAKE SURE FILE IS EMPTY BEFORE CREATING RECORD.***\n");
    (void)printf("***CREATING RECORD WILL OVERWRITE FILE DATA.***\n");
    (void)printf("Select an option.\n");
    (void)printf("%c. Create a Student.\n", USER_CREATE);
    (void)printf("%c. Exit.\n", USER_EXIT);
    (void)printf("Input: ");
  }

  while (true) {
    if (_tries > OPTION_TRIES) {
      (void)printf("Too many attemps... forcing exit. (%c)\n", USER_EXIT);
      _temp = USER_EXIT;
      break;
    } else {
      if (scanf(" %c", &_temp)) {
        _temp = toupper(_temp);

        if (STUDENT_COUNT == 0 &&
            (_temp == USER_CREATE || _temp == USER_EXIT)) {
          break;
        } else if (_temp == USER_CREATE || _temp == USER_READ ||
                   _temp == USER_UPDATE || _temp == USER_DELETE ||
                   _temp == USER_EXIT) {
          break;
        }
        flushUserInput();
      }
    }
    _tries++;
    (void)printf("Invalid input try again.\nInput: ");
  }

  *_input = _temp;
}

int getNewStudentID(void) {
  unsigned int _tempID;

  if (STUDENT_COUNT > 0) {
    student_t _tempStud;
    readFile(&_tempStud, SINGLE, STUDENT_COUNT - SINGLE, false);

    if (GLOBAL_ID <= _tempStud.id) {
      GLOBAL_ID = _tempStud.id + NEXT;
      _tempID = GLOBAL_ID;
    } else {
      _tempID = GLOBAL_ID;
    }
  } else {
    _tempID = FRIST_ID;
  }
  return _tempID;
}

bool readFileSize(size_t *_size_t_ptr) {
  bool _isSuccess = false;
  FILE *_file = fopen(FILENAME, "rb");
  if (_file != NULL) {
    fseek(_file, 0L, SEEK_END);
    *_size_t_ptr = (size_t)ftell(_file);
    STUDENT_COUNT = ((size_t)ftell(_file) / sizeof(student_t));
    _isSuccess = true;
    fclose(_file);
  } else {
    (void)printf("Could not read/find file: [%s].\n", FILENAME);
  }
  return _isSuccess;
}

bool readFile(student_t *_user, const size_t _amount, const size_t _offset,
              const bool _verbose) {
  bool _isSuccess = false;
  FILE *file = fopen(FILENAME, "rb");
  if (file != NULL) {
    if (_amount > 0 && (_amount + _offset) <= STUDENT_COUNT) {
      if (_verbose) {
        (void)printf("ID\tAge\tName\n");
        (void)printf(
            "------------------------------------------------------------\n");
      }
      fseek(file, sizeof(student_t) * _offset, SEEK_CUR);
      for (size_t i = 0; i < _amount; i++) {
        fread(_user, sizeof(student_t), SINGLE, file);
        if (_verbose) {
          (void)printf("%d\t%u\t%s\n", _user->id, _user->age, _user->name);
        }
      }
      _isSuccess = true;
    }
    fclose(file);
  } else {
    (void)printf("Failed to open file for reading.\n");
  }
  return _isSuccess;
}

bool writeStudent(const student_t *_student) {
  bool _isSuccess = false;
  FILE *_file = fopen(FILENAME, "ab+");
  if (_file != NULL) {
    fwrite(_student, sizeof(student_t), SINGLE, _file);
    fclose(_file);
    GLOBAL_ID++;
    _isSuccess = true;
  } else {
    (void)printf("Failed to open file for writing.\n");
  }
  return _isSuccess;
}

bool updateUser(const size_t _id, const char *_new_name, const int _new_age) {
  bool _isSuccess = false;
  FILE *_file = fopen(FILENAME, "r+b");
  if (_file != NULL) {
    student_t _user;
    while (fread(&_user, sizeof(student_t), SINGLE, _file)) {
      if (_user.id == _id) {
        strncpy(_user.name, _new_name, STRING_BUFFER - 1);
        _user.name[STRING_BUFFER - 1] = '\0';
        _user.age = _new_age;

        fseek(_file, -sizeof(student_t), SEEK_CUR);
        fwrite(&_user, sizeof(student_t), SINGLE, _file);
        _isSuccess = true;
        break;
      }
    }
    // simple check to see if any value has been assigned at all.
    if (_user.age != _new_age) {
      (void)printf("Failed match to ID for updating.\n");
    }
    fclose(_file);
  } else {
    (void)printf("Failed to open file for updating.\n");
  }
  return _isSuccess;
}

bool deleteUser(const size_t _id, const size_t _user_amount) {
  bool _isSuccess = false;
  FILE *_file = fopen(FILENAME, "rb");
  FILE *_temp_file = fopen("temp.bin", "wb");
  if (_file != NULL && _temp_file != NULL) {

    student_t _user;
    size_t _loop = 0;
    bool _found = false;

    while (fread(&_user, sizeof(student_t), SINGLE, _file) &&
           _loop < _user_amount) {
      if (_user.id != _id) {
        fwrite(&_user, sizeof(student_t), SINGLE, _temp_file);
      } else {
        _found = true;
      }
      _loop++;
    }

    fclose(_file);
    fclose(_temp_file);

    if (_found) {
      if (remove(FILENAME) != FILE_EDIT_SUCCESS) {
        (void)printf("Failed to remove the original file.\n");
      }
      if (rename("temp.bin", FILENAME) != FILE_EDIT_SUCCESS) {
        (void)printf("Successfully deleted original file but ");
        (void)printf("failed to rename temporary file.\n");
      } else {
        _isSuccess = true;
      }
    } else {
      (void)printf("Failed to find ID match.\n");
      remove("temp.bin");
    }

  } else {
    (void)printf("Failed to open file for reading and or writing.\n");
  }

  return _isSuccess;
}