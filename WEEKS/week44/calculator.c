#include <stdio.h>
#include <ctype.h>

 int *calcFunc(char *sign, int *n1, int *n2);

int main(void)
{
//take 2 nums from user. Switch to put & get char later on.
    int n1 = 0;
    int n2 = 0;

    printf("Input 2 numbers with a space inbetween:\n");
    // scanf(" %i", &n1);
    // scanf(" %i", &n2);

    int ch = 0;
    int flag = 0;
    while((ch = getchar()) != '\n')
    {
        if( flag == 0 && ch == ' '){
            continue;
        }
        else if ( !isdigit(ch) == 0 && flag == 0)//if is digit returns 0 and flag is at pos 0, execute.
        {
            n1 = ch - '0';
            flag = 1;
            continue;
        }
        else if(!isdigit(ch) == 0)
        {
            n2 = ch - '0';
        }
    }



    //ask user for what type of calculation(+, -, *, /)
    char calcType = ' ';
    printf("Choose a calculatioin (+, -, *, /):\n");
    scanf(" %c", &calcType);
    printf("You chose: %c\n", calcType);
    printf("You chose: %i and %i\n", n1, n2);



    //use func pointer.
    int (*calc)(char *, int *,int *) = calcFunc;
    
    int results = calc(&calcType, &n1, &n2);

    printf("The result is: %i\n", results);

    return 0;
}

    //if (operType == *) {}
 int *calcFunc(char *sign, int *n1, int *n2)
{

     int result;

    if ( *sign == '+')
    {
       result = (*n1 + *n2);

    } else if( *sign == '-')
    {
       result = (*n1 - *n2);
    }
    else if(*sign == '*'){
        result = (*n1 * *n2);
    }else{
        if (*n2 == 0){
            printf("Ivalid number, can't divide by 0!");
            return 0;
        }
        result = (*n1 / *n2);
    }

    return result;
}
