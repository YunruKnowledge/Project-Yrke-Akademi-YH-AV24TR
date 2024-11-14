// Write a program to make an array of person_t dynamically.

//     The program shall ask the user to enter length of the array.
//     Then the program shall allocate memory for the array.
//     Then the program shall ask the user to enter name and age of each person.
//         Memory for the name member shall be allocated dynamically.
//     Then the program shall print all the persons to the output.
//     In the end the program shall release all the dynamically allocated
//     memory.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  int age;
} person_t;

typedef struct {
  char *inputName;
  int inputAge;
  int inputMemorySize;
} input_t;

void scanfFlush();
static person_t *askForPerson(void);
static person_t *create(const char *_name, const int _buffer, const int _age);

int main(void) {
  (void)printf("Asking for user 1.\n");
  person_t *_user1 = askForPerson();
  (void)printf("Asking for user 2.\n");
  person_t *_user2 = askForPerson();

  (void)printf("User1: \"%s\", %i\n", _user1->name, _user1->age);
  (void)printf("User2: \"%s\", %i\n", _user2->name, _user2->age);

  if (_user1) {
    free(_user1->name);
    free(_user1);
    _user1 = NULL;
  }

  if (_user2) {
    free(_user2->name);
    free(_user2);
    _user2 = NULL;
  }

  return 0;
}

void scanfFlush() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

static person_t *create(const char *_name, const int _buffer, const int _age) {
  person_t *_temp = (person_t *)malloc(sizeof(person_t));
  if (_temp) {
    _temp->name = (char *)malloc(sizeof(char) * _buffer);
    if (_temp->name) {
      int _index = 0;
      while (_name[_index] != '\0' && _name[_index] != EOF) {
        _temp->name[_index] = _name[_index];
        _index++;
      }
      _index++;
      _temp->name[_index] = '\0';
    } else {
      free(_temp);
      _temp = NULL;
    }
    _temp->age = _age;
  }

  return _temp;
}

static person_t *askForPerson(void) {
  input_t _input;
  person_t *_person;
  int validCount = 0;

  do {
    validCount = 0;
    (void)printf("Enter how many bytes will be needed for each name. (1 per "
                 "character.)\n");
    validCount = scanf(" %i", &_input.inputMemorySize);
    scanfFlush();
  } while (!validCount);

  _input.inputName = (char *)malloc(sizeof(char) * _input.inputMemorySize);
  if (_input.inputName) {
    do {
      validCount = 0;
      (void)printf("Enter a name.\n");
      validCount = scanf(" %s", _input.inputName);
      scanfFlush();
    } while (!validCount);

    do {
      validCount = 0;
      (void)printf("Enter a age.\n");
      validCount = scanf(" %i", &_input.inputAge);
      scanfFlush();
    } while (!validCount);
  } else {
    (void)printf("Memory allocation failed. Exiting...\n");
  }

  _person = create(_input.inputName, _input.inputMemorySize, _input.inputAge);

  free(_input.inputName);
  _input.inputName = NULL;

  return _person;
}

// char *inputName = (char *)malloc(sizeof(char) * 64);
// *inputName = (char *)realloc(sizeof(char) * allocMemSize);