#ifndef COLOR_LIB
#define COLOR_LIB
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
char SetTextColor(enum usableColors color);

char SetBoldTextColor(enum usableColors color);

char SetUnderlineTextColor(enum usableColors color);

char SetTextHighIntenstyColor(enum usableColors color);

char SetBoldTextHighIntenstyColor(enum usableColors color);

char SetBGColor(enum usableColors color);

char SetBGHighIntenstyColor(enum usableColors color);

char ResetColors();

#include "color.c"
#endif