/**
 * @file files.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of file handling in C
 * @version 0.1
 * @date 2021-03-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("temp.txt", "w");

    if (file == NULL)
    {
        printf("Failed to open temp.txt\n");
        exit(1);
    }

    if (EOF == fclose(file))
    {
        printf("Failed to close temp.txt\n");
        exit(1);
    }

    if (0 != rename("temp.txt", "test.txt"))
    {
        printf("Failed to rename temp.txt to test.txt\n");
        exit(1);
    }

    if (0 != remove("test.txt"))
    {
        printf("Failed to delete test.txt\n");
        exit(1);
    }

    file = fopen("file.txt", "a");

    if (file == NULL)
    {
        printf("Failed to open text.txt\n");
        exit(1);
    }

    if (EOF == fputs("Hello World!", file))
    {
        fclose(file);
        printf("Failed to write to text.txt\n");
        exit(1);
    }

    fflush(file);
    fseek(file, 0, SEEK_END);
    printf("Size of the file in bytes: %d\n", ftell(file));

    if (EOF == fclose(file))
    {
        printf("Failed to close text.txt\n");
        exit(1);
    }

    return 0;
}