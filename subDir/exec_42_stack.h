#ifndef MODULE_EXEC42_STACK
#define MODULE_EXEC42_STACK

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct STACK stack_t;

/**
 * @brief Creates a stack.
 * 
 * @param _length Max length.
 * @return stack_t* - pointer.
 */
stack_t *stackCreate(const size_t _length);

/**
 * @brief Push a value into a stack.
 * 
 * @param _stack Adress of stack.
 * @param _value Interger to push.
 * @return `true` if successful.
 */
bool stackPush(stack_t *_stack, const uint8_t _value);

/**
 * @brief Pop the top layer and apply value to an int pointer.
 * 
 * @param _stack Adress of stack.
 * @param _iptr Pointer to apply the value to.
 * @return `true` if successful. 
 */
bool stackPop(stack_t *_stack, int *_iptr);

/**
 * @brief Prints all the stack data to the terminal.
 * 
 * @param _stack Adress of stack.
 * @return `size_t` - Current length of stack.
 */
size_t stackRead(stack_t *_stack);

/**
 * @brief Clear the stack.
 * 
 * @param _stack Adress of stack.
 * @return `true` if cleared or is null. 
 */
bool stackClear(stack_t *_stack);

/**
 * @brief Free stack from memory.
 * 
 * @param _stack Adress of stack.
 * @return `true` if successful or is null.
 */
bool stackFree(stack_t *_stack);

#endif