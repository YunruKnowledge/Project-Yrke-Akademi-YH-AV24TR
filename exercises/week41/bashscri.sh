#!/bin/bash

clear;
sleep 1s
echo "

===SCRIPT LOADING===

";
sleep 1s;
echo "==SCRIPT STARTING==";
sleep 2s;
mkdir -p program/;
cd program/;
rm -f run
touch main.c
echo "
#include <stdio.h>
#include <unistd.h>

#define NAME \"Hello World\"
int main(void){

fflush(stdout);
sleep(2);
printf(\"%s\n\", NAME);

float n = 15;
for(float i = 1; i<n; i++){
printf(\"#\");
fflush(stdout);
sleep(n-i)-1;
}
return 0;}
" > main.c

gcc main.c -o run && ./run

ls