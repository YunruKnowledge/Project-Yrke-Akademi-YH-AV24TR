#include <stdio.h>

int main(){
    int var = 10;
    int *pt = &var;
    (void)printf("[Integer value] : \t\t[%d], \n[Pointer value] : \t\t[%d], \n[Pointer point address] : \t[%p] \n", var, *pt, pt);
}