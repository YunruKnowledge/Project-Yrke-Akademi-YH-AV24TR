#include <stdio.h>

int doLoopCalculation(int *numbers, int amountOfNumbers, char symbol);

int main()
{
    unsigned int amountOfNumbers;
    int *arrayOfInputNum;
    char character;

    do
    {
        (void)printf("Lets do some Calculations \n");
        (void)printf("Please enter how many numbers you want to do calculation with: \n");
        scanf("%d", &amountOfNumbers);
    } while (arrayOfInputNum == 0);

    for (int i = 0; i < amountOfNumbers; i++)
    {
        (void)printf("Enter number [%d]: ", i);
        scanf("%d", &arrayOfInputNum[i]);
    }

    (void)printf("What type of calculation u want to do? \n");
    (void)printf("Enter one of the for symbols[\"+\", \"-\", \"*\", \"/\"]: ");

    getchar();
    scanf("%c", &character);

    int sum = doLoopCalculation(arrayOfInputNum, amountOfNumbers, character);
    for (int i = 0; i < amountOfNumbers; i++)
    {
        (void)printf("%d ", arrayOfInputNum[i]);
        if (i == amountOfNumbers - 1)
            (void)printf(" = %d \n", sum);
        else
            (void) printf("%c ", character);
    }
    return 0;
}

int doLoopCalculation(int *numbers, int amountOfNumbers, char symbol)
{
    int result = 0;
    for (int i = 0; i < amountOfNumbers; i++)
    {
        if (i == 0)
            result = numbers[i];
        else
        {
            if (symbol == '+')
                result += numbers[i];
            else if (symbol == '-')
                result -= numbers[i];
            else if (symbol == '*')
                result *= numbers[i];
            else if (symbol == '/')
                result /= numbers[i];
        }
    }

    return result;
}