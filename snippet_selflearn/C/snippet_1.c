#include <stdio.h>

void main () {
    int input;
    printf("Input a http code!\n");
    scanf("%d", &input);

    int keycodes[] = {200, 404, 80085};
    char *keywords[] = {"OK", "ERROR", "[REDACTED]"};

    for (int i = 0; i < sizeof(keycodes); i++)
    {
        if (input == keycodes[i]) {
            if (i >= sizeof(keywords) / 8) return;

            printf("%s \n", keywords[i]);
            return;
        }
    }
}