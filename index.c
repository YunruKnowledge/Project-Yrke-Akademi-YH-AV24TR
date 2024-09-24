#include <stdio.h>

#define countof(a) (int)(sizeof(a) / sizeof(*(a)))

#define characters    \
    X(Smile_emoji, 23333) \
    X(Y,      15) \
    X(ENUM25, 25) \
    X(Z,      31) \
    X(ENUM40, 40)

#define X(k, v) k = v,
typedef enum {characters} Characters;
#undef X

#define X(k, v) {#k, v},
struct {
    char  *key;
    Characters value;
} Characterss[] = { characters };
#undef X

void main(){
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num == 80085){
        printf("\033[0;37m (\033[0;31m.\033[0;37m)(\033[0;31m.\033[0;37m) \n");
        return;
    }

    for (int i = 0; i < countof(Characterss); i++){
        if (num == Characterss[i].value){
            printf("%s \n", Characterss[i].key);
            return;
        }
    } 
    printf("You are gay \n");
}