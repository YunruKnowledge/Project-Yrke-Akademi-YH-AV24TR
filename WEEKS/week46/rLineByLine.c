#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 100
#define MAX_FILE_SIZE 499

int main(void)
{
    char temp[BUFFER];
    char allContents[MAX_FILE_SIZE];
    int count;

    FILE *fptr = fopen("story.txt", "r");
    if (fptr == NULL)
    {
        printf("Couldn't create the file");
        exit(1);
    }

    while ( fgets(temp, BUFFER, fptr) != NULL){
        //copy the new line that fget put into temp, move to allContents.
        strcat(allContents, temp); 
        count++;
    }

    fclose(fptr);
    printf("The contents below:\n%s\n", allContents);
    printf("There was %i line in the story.txt file.", count);

    return 0;
}