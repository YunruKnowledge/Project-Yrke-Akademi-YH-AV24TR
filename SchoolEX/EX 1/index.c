#include <stdio.h>
#include <stdbool.h>

#define INT 2

int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);

bool state = true;

int main(void)
{
    int num1, num2;
    char operator;

    int (*operation)(int, int);
    
    (void)printf("Enter two numbers(Divided by space): ");
    if (INT == scanf("%i %i", &num1, &num2))
    {
        getchar();
        (void)printf("Enter a operator you want to do(+, -, *, /): ");
        (void)scanf("%c", &operator);
        switch (operator)
        {
        case '+':
            operation = add;
            break;
        case '-':
            operation = subtract;
            break;
        case '*':
            operation = multiply;
            break;
        case '/':
            operation = divide;
            break;
        default:
            (void)printf("Invalid input! \n");
            state = false;
            break;
        }

        if (state)
        {
            int result = operation(num1, num2);
            (void)printf("Result: %d \n", result);
        }
    }
    else
    {
        (void)printf("Invalid input! \n");
    }
}

int add(int num1, int num2)
{
    return num1 + num2;
}

int subtract(int num1, int num2)
{
    return num1 - num2;
}

int multiply(int num1, int num2)
{
    return num1 * num2;
}

int divide(int num1, int num2)
{
    if (num2 == 0)
    {
        (void)printf("Error! Cannot divide by 0");
        return 0;
    }
    else
    {
        return num1 / num2;
    }
}