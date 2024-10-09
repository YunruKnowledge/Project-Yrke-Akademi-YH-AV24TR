#include <stdio.h>

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char *argv[]){

    int num = 30;
    //0001 1110
    int mask = 0xF;
    //0000 1111

    int result = num & mask;

    // printf("%d\n", result);

    printf("%d", (0b1100 | 0b0010));
}