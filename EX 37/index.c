#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 50

void splitString(const char *string, const char *word, char **part1, char **part2);
int findDelimiter(const char *string, const char *word);

int main()
{
    char string[] = "This is a test string, split by the word test in C.";
    const char *word = "test";

    char *part1 = NULL; 
    char *part2 = NULL;

    splitString(string, word, &part1, &part2);

    if (part1)
    {
        printf("Part 1: %s\n", part1);
        free(part1);
        part1 = NULL;
    }
    if (part2)
    {
        printf("Part 2: %s\n", part2);
        free(part2);
        part2 = NULL;
    }

    return 0;
}

int findDelimiter(const char *string, const char *word)
{
    int i = 0, j = 0;
    int returnVal = -1;
    while (string[i] != '\0')
    {
        if (string[i] == word[j])
        {
            int k = i;
            while (string[k] == word[j] && word[j] != '\0')
            {
                k++;
                j++;
            }
            if (word[j] == '\0')
                returnVal = i;
            else
                j = 0;
        }
        i++;
    }
    return returnVal;
}

void splitString(const char *string, const char *word, char **part1, char **part2)
{
    int pos = findDelimiter(string, word);

    if (pos == -1)
    {
        *part1 = (char *)string;
        *part2 = NULL;
        return;
    }

    *part1 = (char *)malloc(pos + 1);
    if (*part1 == NULL)
    {
        printf("Memory allocation failed for part1\n");
        return;
    }

    int i;
    for (i = 0; i < pos; i++)
    {
        (*part1)[i] = string[i];
    }
    (*part1)[i] = '\0'; 

    *part2 = (char *)malloc(strlen(string) - pos - strlen(word) + 1);
    if (*part2 == NULL)
    {
        printf("Memory allocation failed for part2\n");
        return;
    }

    int j = 0;
    for (i = pos + strlen(word); string[i] != '\0'; i++)
    {
        (*part2)[j++] = string[i];
    }
    (*part2)[j] = '\0'; 
}