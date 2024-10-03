
#include <stdio.h>
enum usableColors
{
    red,
    white,
    blue,
    black,
    green,
    yellow,
    magenta,
    cyan,
};

char GetColor(enum usableColors color){
    if (color == red)
        return printf("\033[31m");

    if (color == blue)
        return printf("\x1b[34m");

    if (color == white)
        return printf("\x1b[37m");

    if (color == black)
        return printf("\x1b[30m");

    if (color == green)
        return printf("\x1b[32m");

    if (color == yellow)
        return printf("\x1b[33m");

    if (color == magenta)
        return printf("\x1b[35m");

    if (color == cyan)
        return printf("\x1b[36m");
}

char GetBGColor(enum usableColors color){
    if (color == red)
        return printf("\033[41m");

    if (color == blue)
        return printf("\x1b[44m");

    if (color == white)
        return printf("\x1b[47m");

    if (color == black)
        return printf("\x1b[40m");

    if (color == green)
        return printf("\x1b[42m");

    if (color == yellow)
        return printf("\x1b[43m");

    if (color == magenta)
        return printf("\x1b[45m");

    if (color == cyan)
        return printf("\x1b[46m");
}