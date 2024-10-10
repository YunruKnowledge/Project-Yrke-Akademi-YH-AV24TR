//use with #include <ctype.h>
#ifndef swapCaseLib
#define swapCaseLib


int swapCase(int ch){
    if(isupper((unsigned char)ch))
        ch = tolower((unsigned char)ch);
    else
        ch = toupper((unsigned char)ch);
    return ch;
}

char *strSwapCase(char *str)
{
    char *wrk = str;
    if(str)
    {
        while(*str) 
        {
            *str = swapCase(*str);
            str++;
        }
    }
    return wrk;
}

#endif