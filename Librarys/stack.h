#ifndef STACK
#define STACK

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    int top;
    unsigned capacity;
    int *array;
} Stack;

Stack *stack_create(unsigned capacity);

void stack_push(Stack *stack, uint8_t item);
void stack_clear(Stack *stack);
void stack_delete(Stack *stack);

int stack_pop(Stack *stack);
int stack_peek(Stack *stack);
int stack_getLength(Stack *stack);

bool stack_isEmpty(Stack *stack);
bool stack_isFull(Stack *stack);

#include "stack.c"

#endif // !STACK
