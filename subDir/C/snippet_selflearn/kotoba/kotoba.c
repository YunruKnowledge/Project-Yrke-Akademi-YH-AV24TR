#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LEN 64
#define FILENAME "../words_alpha.txt";

static char GLOBAL_LETTER;

void scanfFlush() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

size_t checkStringLength(const char *_string) {
  size_t _index = 0;
  while (_string[_index]) {
    if (_string[_index] == '\0' || _string[_index] == '\n') {
      break;
    } else {
      _index++;
    }
  }

  return _index;
}

void initWord(void) {

  FILE *file = fopen("../words_alpha.txt", "r");
  if (file == NULL) {
    perror("Unable to open file");
    exit(1);
  }

  char _tempWord[MAX_WORD_LEN];
  size_t _randInt = rand() % 370000;
  for (size_t i = 0; i < _randInt; i++) {
    fgets(_tempWord, sizeof(_tempWord), file);
  }
  _tempWord[strcspn(_tempWord, "\n")] = 0;
  GLOBAL_LETTER = _tempWord[checkStringLength(_tempWord) - 1];

  printf("Starting word: %s | ends with \'%c\'\n", _tempWord, GLOBAL_LETTER);

  fclose(file);
}

int search(char *_word) {

  FILE *file = fopen("../words_alpha.txt", "r");
  if (file == NULL) {
    perror("Unable to open file");
    exit(1);
  }

  for (size_t i = 0; i < checkStringLength(_word); i++) {
    _word[i] = tolower(_word[i]);
  }

  char _tempWord[MAX_WORD_LEN];
  while (fgets(_tempWord, sizeof(_tempWord), file)) {
    _tempWord[strcspn(_tempWord, "\n")] = 0;
    // printf("%s - %s | %c - %c\n", _word, _tempWord, _word[0], _tempWord[0]);
    if (_word[0] == _tempWord[0]) {
      if (!strcmp(_word, _tempWord)) {
        GLOBAL_LETTER = _tempWord[checkStringLength(_tempWord) - 1];
        fclose(file);
        return 1;
      }
    }
  }
  fclose(file);

  return 0;
}

int main(void) {
  char input[MAX_WORD_LEN];

  srand(time(NULL));
  initWord();

  do {
    (void)printf("(Exit, by seaching for \"exit\")\n");
    (void)printf("Enter a word starting with '%c'\n", GLOBAL_LETTER);
    (void)printf("Word: ");

    while (1) {
      if (scanf("%s", input) == 1) {
        if (tolower(input[0]) == GLOBAL_LETTER || !strcmp(input, "exit")) {
          break;
        } else {
          (void)printf("Invalid input, please start with \'%c\'\nWord: ",
                       GLOBAL_LETTER);
          scanfFlush();
        }
      }
    }

    if (strcmp(input, "exit")) { // if not "exit"
      if (search(input)) {
        (void)printf("The word \"%s\" exists in the dictionary.\n", input);
      } else {
        (void)printf("The word \"%s\" does not exist in the dictionary.\n",
                     input);
      }
    }
  } while (strcmp(input, "exit"));

  (void)printf("Exiting...\n");
  return 0;
}
