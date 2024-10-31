#include <stdio.h>
#include <stdarg.h>
#include "module.h"

//i switched &local address in a function o static to not lose the function in the memory/cpu.

typedef void (*func_t)(int);

static void print_value(int a)
{
    printf("The value is %d\n", a);
}

static func_t my_func(void)
{
    return &print_value;
}

// Here we can define hello as a function, despite of having hello in module.c
static void hello(char *name)
{
    printf("Hello %s!\n", name);
}

static void func(char array[][6][5]); // Using multidimensional array as a parameter

extern void hello_extern(void); // Using hello_extern implemented in module.c

int add(int x, int y); // Function declaration (prototype form)

// The declaration and definition of multiply
int multiply(int x, int y)
{
    return (x * y);
}

static int *function(void)
{
    static int local = 0;

    return &local; // Address of local variables shall not be returned.
}

// max has been defined as an inline function
static inline int max(int x, int y)
{
    return (x > y) ? x : y;
}

unsigned long long int factorial(unsigned short int n)
{
    return (n == 0) ? 1U : (n * factorial(n - 1));
}

// This function return the sum of a variable number of integer numbers
int addnint(unsigned int n, ...)
{
    int sum = 0;
    va_list args;
    va_start(args, n); // The second argument is the last mandatory argument

    for (int i = 0; i < n; i++)
    {
        sum += va_arg(args, int);
    }

    va_end(args);

    return sum;
}

int main(int argc, char *argv[])
{
    // You can get arguments to the program
    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d) %s\n", i, argv[i]);
    }

    int a = 2, b = 3;

    print(a, b, '+', add(a, b));

    print(a, b, 'x', multiply(a, b));

    hello("Stefan");

    hello_extern();

    // Using addnint which is a variadic function
    printf("Sum1 is %d\n", addnint(2, 10, 20));
    printf("Sum2 is %d\n", addnint(5, 10, 20, 30, 40, 50));

    printf("100! = %llu\n", factorial(20));

    func_t funcptr = &print_value; // A function pointer initialized with the print_value function. & can be omitted.

    (*funcptr)(10); // or funcptr(10); call print_value using the function pointer

    my_func()(20); // my_func returns a function pointer

    return 0;
}

// Definition of the add function
int add(int x, int y)
{
    return (x + y);
}

// Definition of the func function
static void func(char array[][6][5])
{
    ;
}