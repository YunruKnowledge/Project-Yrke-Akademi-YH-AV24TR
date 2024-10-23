#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    struct tm *info;
    char buffer[80];

    (&rawtime);
    info = localtime(&rawtime);
    
    strftime(buffer, sizeof(buffer), "Current local time and date: %Y-%m-%d %H:%M:%S", info);
    printf("%s\n", buffer);

    return 0;
}
