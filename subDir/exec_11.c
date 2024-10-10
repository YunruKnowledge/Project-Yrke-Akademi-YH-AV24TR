#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int _char;
    int _last_char = ' ';
    int _seperation = 0; // bool


    printf("Please enter your name.\n");
    while ((_char = getchar()) != '\n')
    {
        if (isalpha(_char))
        {
            if (_last_char == ' ')
            {
                putchar(toupper(_char));
            }
            else
            {
                putchar(tolower(_char));
            }
            _last_char = _char;
            _seperation = 1;
        }
        else if (isspace(_char))
        {
            if (_seperation)
            {
                putchar(' ');
                _last_char = ' ';
                _seperation = 0;
            }
        }
    }
    printf("\n");
    printf("We've formatted your name.\n");
    return 0;
}