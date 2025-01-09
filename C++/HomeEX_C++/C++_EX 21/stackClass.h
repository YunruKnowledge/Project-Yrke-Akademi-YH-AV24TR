/**
 * @file stackClass.h
 * @author Lazar Roksandic (roksandiclazar@gmail.com)
 * @brief A header file to create stack using class
 * @version 0.1
 * @date 2025-01-09
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef STACK_CLASS_H
#define STACK_CLASS_H

#define ARRAY_SIZE 3

class Stack
{
    int stackArr[ARRAY_SIZE];
    int maxSize;
    int currentSize;

public:
    /**
     * @brief Construct a new Stack object
     *
     */
    explicit Stack() : stackArr{0}, maxSize{ARRAY_SIZE}, currentSize{0} {};

    /**
     * @brief Push item to a stack
     *
     * @param item you want to push
     * @return true if you subsecfull pushed item to the stack
     * @return false if you couldn't push item to the stack
     */
    bool push(int item);

    /**
     * @brief Pop top item from the stack
     *
     * @return true if you successfully popt item from stack
     * @return false if you didn't pop the item form the stack
     */
    bool pop();

    /**
     * @brief Peek top item from the stack
     *
     */
    void peek();

    /**
     * @brief Get the Max Size of stack
     * 
     * @return int max size of a stack
     */
    int getMaxSize() { return maxSize; }

    /**
     * @brief Get the Current Amount of items in stack
     * 
     * @return int amount of items in stack
     */
    int getCurrentSize() { return currentSize; }

    /**
     * @brief Check if stack is full
     * 
     * @return true if stack is full
     * @return false if stack is not full
     */
    bool isFull() { return currentSize == maxSize; }

    /**
     * @brief Check if stack is empty
     * 
     * @return true if stack is empty
     * @return false if stack is not empty
     */
    bool isEmpty() { return currentSize == 0; }

    /**
     * @brief Destroy the Stack object
     * 
     */
    ~Stack() {};
};

#endif // !STACK_CLASS_H