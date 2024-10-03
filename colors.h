#include <stdio.h>

enum usableColors {
  red,
  white,
  blue,
  black,
  green,
  yellow,
  magenta,
  cyan,
};

char SetTextColor(enum usableColors color) {
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

char SetBoldTextColor(enum usableColors color) {
  if (color == red)
    return printf("\e[1;31m");

  if (color == blue)
    return printf("\e[1;34m");

  if (color == white)
    return printf("\e[1;37m");

  if (color == black)
    return printf("\e[1;30m");

  if (color == green)
    return printf("\e[1;32m");

  if (color == yellow)
    return printf("\e[1;33m");

  if (color == magenta)
    return printf("\e[1;35m");

  if (color == cyan)
    return printf("\e[1;36m");
}

char SetUnderlineTextColor(enum usableColors color) {
  if (color == red)
    return printf("\e[4;31m");

  if (color == blue)
    return printf("\e[4;34m");

  if (color == white)
    return printf("\e[4;37m");

  if (color == black)
    return printf("\e[4;30m");

  if (color == green)
    return printf("\e[4;32m");

  if (color == yellow)
    return printf("\e[4;33m");

  if (color == magenta)
    return printf("\e[4;35m");

  if (color == cyan)
    return printf("\e[4;36m");
}

char SetTextHighIntenstyColor(enum usableColors color) {
  if (color == red)
    return printf("\e[4;91m");

  if (color == blue)
    return printf("\e[4;94m");

  if (color == white)
    return printf("\e[4;97m");

  if (color == black)
    return printf("\e[4;90m");

  if (color == green)
    return printf("\e[4;92m");

  if (color == yellow)
    return printf("\e[4;93m");

  if (color == magenta)
    return printf("\e[4;95m");

  if (color == cyan)
    return printf("\e[4;96m");
}

char SetBoldTextHighIntenstyColor(enum usableColors color) {
  if (color == red)
    return printf("\e[1;91m");

  if (color == blue)
    return printf("\e[1;94m");

  if (color == white)
    return printf("\e[1;97m");

  if (color == black)
    return printf("\e[1;90m");

  if (color == green)
    return printf("\e[1;92m");

  if (color == yellow)
    return printf("\e[1;93m");

  if (color == magenta)
    return printf("\e[1;95m");

  if (color == cyan)
    return printf("\e[1;96m");
}

char SetBGColor(enum usableColors color) {
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

char SetBGHighIntenstyColor(enum usableColors color) {
  if (color == red)
    return printf("\e[1;101m");

  if (color == blue)
    return printf("\e[1;104m");

  if (color == white)
    return printf("\e[1;107m");

  if (color == black)
    return printf("\e[1;100m");

  if (color == green)
    return printf("\e[1;102m");

  if (color == yellow)
    return printf("\e[1;103m");

  if (color == magenta)
    return printf("\e[1;105m");

  if (color == cyan)
    return printf("\e[1;96m");
}

char ResetColors() { return printf("\x1b[m"); }