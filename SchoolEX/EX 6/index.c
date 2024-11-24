#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "text.txt"
#define BUFFER 50

int main(void)
{
    char searchWord[BUFFER];
    FILE *file;

    file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        (void)printf("Error occurred! No file with [%s] found!", FILE_NAME);
        exit(1);
    }

    (void)printf("Enter a single word that you want to look for in [%s] file: ", FILE_NAME);
    (void)scanf(" %s", searchWord);

    int line = -1;
    char *pos, str[BUFFER];
    while ((fgets(str, BUFFER, file)) != NULL)
    {
        line++;
        pos = strstr(str, searchWord);


        if (line != -1)
            printf("['%s'] found at line: %d\n", searchWord, line + 1);
        else
            printf("['%s'] does not exists.", searchWord);
    }
}