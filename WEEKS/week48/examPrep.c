#include <stdio.h>

int main(void)
{
    FILE *fptr = fopen("test.txt", "w");

    if (fptr == NULL)
    {
        printf("Problem sir, write acccess denied!");
    }

    char str[] = "FUMOS ARE BEST";
    int age = 21;

    // write into the file.
    fprintf(fptr, "The string: %s\nThe age: %i", str, age);
    fclose(fptr);

    FILE *fptrr = fopen("test.txt", "r");

    if (fgets(str, 14, fptrr) != NULL)
    {
        // fputs(str, stdout);
        printf("%s", str);
    }

    fclose(fptrr);

    return 0;
}