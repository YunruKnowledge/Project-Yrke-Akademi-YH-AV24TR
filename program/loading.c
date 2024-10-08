#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 

int main(){
    for (int i = 0; i < 3; i++){
        system("clear");
        printf("Creating files");
        for (int f = 0; f < 3; f++){
            printf(".");
            fflush(stdout);
            sleep(1);
        }
    }
    return 0;
}
