/**
 * @file stack.h
 * @author Lazar Roksandic
 * @brief Library for creating the stack
 * @version 0.1
 * @date 2024-12-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef STACK_H
#define STACK_H

#include <iostream>

struct stack_t;

namespace Stack
{
    /**
     * @brief Function to create stack
     * 
     * @param size to set max stack size
     * @return stack_t or null if create fails
     */
    stack_t *create(int size);

    /**
     * @brief Function to check if stack is full
     * 
     * @param stack to check
     * @return true if its Full
     * @return false if its not Full
     */
    bool isFull(stack_t *stack);

    /**
     * @brief Function to check if stack is emtpy
     * 
     * @param stack to check
     * @return true if its empty
     * @return false if its not empty
     */
    bool isEmpty(stack_t *stack);

    /**
     * @brief Function to inset a value to stack
     * 
     * @param stack you want to insert value to
     * @param value you want to insert
     * @return true if inserting is successfully
     * @return false if stack is null or if stack is full
     */
    bool insert(stack_t *stack, int value);

    /**
     * @brief Function to pop the top value from stack
     * 
     * @param stack you want to pop from
     * @return true if pop is successful
     * @return false if stack is null or if stack is empty
     */
    bool pop(stack_t *stack);

    /**
     * @brief Get the Size of stack
     * 
     * @param stack you want to get size of
     * @return the size of stack
     */
    int getSize(stack_t *stack);

    /**
     * @brief Function to clear all items from stack
     * 
     * @param stack you want to clear
     */
    void clearStack(stack_t *stack);

    /**
     * @brief Function to destroy stack
     * 
     * @param stack you want to destroy
     */
    void destroyStack(stack_t *&stack);

    /**
     * @brief Function to print all items from the stack
     * 
     * @param stack you want to print vals from
     */
    void printStack(stack_t *stack);

    /**
     * @brief Function to peek the top value in stack
     * 
     * @param stack you want to peek
     */
    void peek(stack_t *stack);
}

#endif // !STACK_H