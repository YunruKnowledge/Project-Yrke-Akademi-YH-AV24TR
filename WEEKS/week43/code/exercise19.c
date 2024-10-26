// int main(void){
//     //a for loop to loop through all the chars of an array.
//     //if space printf \n

#include <stdio.h>
// #include <string.h>

int main(){
   
   int ch;
   printf("Enter a string now!: ");

   while(( ch = getchar() ) != '\n'){
    if(ch == ' '){
        putchar('\n');
    }else {
        putchar(ch);
    }
   } 
   putchar('\n');
   
   /* char input[100];//buffer to store the string
    char *token; //pointer to hold the parts of strings

    printf("Enter a string boi!: ");
    fgets(input, sizeof(input),stdin);//read the input with the spaces: size byte, max size, string with spaces.

    input[strcspn(input, "/n")] = 0;//remove the newline char if its present at the end.

    token = strtok(input, " ");//find spaces, print the string that is before the space

    while (token !=NULL){
        printf("%s\n", token);//print one part of the strings
        token = strtok(NULL, " ");// get the next token
    }
    */
    return 0;
}
