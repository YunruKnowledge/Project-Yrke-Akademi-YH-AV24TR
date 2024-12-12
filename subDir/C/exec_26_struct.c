#include <stdio.h>
#include <string.h>

#define NAME_BUFFER 16

typedef struct {
  int age;
  float height;
  char name[NAME_BUFFER];
} person_t;

person_t get_person(void) {
  person_t _user;

  (void)printf("Please enter your age.\n");
  (void)printf("-> ");
  scanf("%3i", &_user.age); // 3 digits

  (void)printf("Now please enter your height, decimals allowed. (Ex. \"169.78\"')\n");
  (void)printf("-> ");
  scanf("%7f", &_user.height);

  (void)printf("And first name please. (Max 16 characters.)\n");
  (void)printf("-> ");
  char _string[NAME_BUFFER];
  scanf("%16s", &_string);
  strcpy(_user.name, _string);
    
  return _user;
}

int main(void) {
  person_t user = get_person();
  printf("[    Age: %16i ]\n", user.age);
  printf("[ Height: %16f ]\n", user.height);
  printf("[   Name: %16s ]\n", user.name);
  return 0;
}
