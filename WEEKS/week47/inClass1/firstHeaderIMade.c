/*
Create a file that that has 2 functions.

1. fucntion1: Checks length of the string.
2. function2: Compares 2 strings and returns true if its a match. (use boolean)

3. now include the .h of this file(make it a local library) and call it to-
file 2 and compile file 2 and run(example: gcc file1.c file2.c -o main).

must run and work.
*/
#include <stdio.h>
#include <stdbool.h>
#include "firstHeaderIMade.h"

static int checkLen(char *_name)
{
    int count = 0;

    while (_name[count] != '\0')
    {
        if (_name[count] != '\0' || _name[count] != EOF)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    return count;
}

int fakeFunc(char *_name)
{
   return checkLen(_name);
}

bool cmpr2str(char *str1, char *str2)
{
    int i = 0;
    bool status = true;
    // run until str1 ends.
    while (str1[i] != '\0')
    {
        // if same letter
        if (str1[i] == str2[i])
        {
            i++;
            continue;
        }
        else if (str1[i] != str2[i])
        {
            status = false;

            break;
        }
        else
        {
            break;
        }
    }

    return status;
}

