#include <stdio.h>
#include <stdlib.h>

#define STRING "ARINYAHBIKLIKISOP"
#define LIMIT 99

int main(void)
{
    char theString[LIMIT]; // save the contents from the file here

    FILE *file = fopen("text.txt", "w+"); // open||create this file.

    if (file == NULL)
    {
        printf("Cannot open file!");
        exit(1);
    }

    if (EOF == fputs(STRING, file))
    {
        printf("Error with the file!");
        (void)fclose(file);
    }
        rewind(file); //To send the pointer back to the top of the file
    if (file == NULL) //If file doesn't exist
    {
        perror("Error opening file");
    }
    else
    {
        if (fgets(theString, LIMIT, file) /*!= NULL //if it doesn't exist do as stated below*/)
        {
            puts(theString);
            fclose(file);
        }
    }

    return 0;
}