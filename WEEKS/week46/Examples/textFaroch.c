/**
 * @file main.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to write "Hello World!\n" to a file 10 times and
 *        read the first 5 lines of the file and print them to the terminal.
 *
 * @version 0.1
 * @date 2022-11-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define READ_NUM 5
#define WRITE_NUM 10
#define STRING "Hello World!\n"

int main(void)
{
    // Create a file (text.txt) using fopen
    FILE *file = fopen("text.txt", "w");
    if (file == NULL)
    {
        (void)printf("Failed to open the file!\n");
        exit(1);
    }

    // Using a for loop write "Hello World!\n" 10 times to the file
    for (int i = 0; i < WRITE_NUM; i++)
    {
        if (EOF == fputs(STRING, file))
        {
            (void)fclose(file);
            (void)printf("Failed to write to the file!\n");
            exit(1);
        }
    }

    if (0 != fclose(file))
    {
        (void)printf("Failed to close the file!\n");
        exit(1);
    }

    // Open the file (text.txt) for reading
    file = fopen("text.txt", "r");
    if (file == NULL)
    {
        (void)printf("Failed to open the file!\n");
        exit(1);
    }

    // Using a for loop read the first 5 lines of the file and print them to the terminal
    for (int i = 0; i < READ_NUM; i++)
    {
        char buffer[sizeof(STRING)] = {0};
        if (NULL == fgets(buffer, sizeof(STRING), file))
        {
            (void)fclose(file);
            (void)printf("Failed to read from the file!\n");
            exit(1);
        }
        (void)printf("%s", buffer);
    }

    if (0 != fclose(file))
    {
        (void)printf("Failed to close the file!\n");
    }

    return 0;
}