// Write a program that searches for a specific word in a file named " text.txt".
//  The program should ask the user for the word to search for,
//  and then print all lines in the file that contain this word.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 99
#define FILE_NAME "text.txt"

int main(void)
{
    FILE *file; /*=  fopen("text.txt", "r")*/

    char theWord[BUFFER];
    char temp[BUFFER];

    file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        perror("Couldn't open the file");
        exit(1);
    }
    else
    {
        printf("FILE EXISTS!\n");
    }
    printf("Input a word to search for:\n");
    scanf(" %s", theWord);

    int count = 0;

    // put to temp, read buffer amount, the file
    while (fgets(temp, BUFFER, file) != NULL)
    {
        if (strstr(temp, theWord) != NULL)
        {
            printf("Found your word: %s\nTHE LINE BELOW:\n%s\n", theWord, temp);
            count++;
        }

        // printf("Lines containing the word '%s':\n", theWord);
    }

        printf("There is ~~%i~~ lines in the file that had your word.", count);
    fclose(file); // close the file

    return 0;
}
