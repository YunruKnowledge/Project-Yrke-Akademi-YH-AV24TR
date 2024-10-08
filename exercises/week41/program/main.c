
#include <stdio.h>
#include <unistd.h>

#define NAME "Hello World"
int main(void){

fflush(stdout);
sleep(2);
printf("%s\n", NAME);

float n = 15;
for(float i = 1; i<n; i++){
printf("#");
fflush(stdout);
sleep(n-i)-1;
}
return 0;}

