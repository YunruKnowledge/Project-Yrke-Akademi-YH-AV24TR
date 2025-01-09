/**
 * @file singleton.h
 * @author Lazar Roksandic (roksandiclazar@gmail.com)
 * @brief A heather file for creating singleton stack
 * @version 0.1
 * @date 2025-01-09
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

/**
 * @brief Defined Max size of a array
 *
 */
#define MAX_SIZE 3

class Stack
{
    /**
     * @brief Array for stack with defined max size
     *
     */
    static int stackArr[MAX_SIZE];

    /**
     * @brief amount of items in array
     *
     */
    static int currentSize;

public:
    /**
     * @brief Makes the stack uncopyble
     *
     * @return Error if you try to copy a stack
     */
    Stack &operator=(const Stack &) = delete;

    /**
     * @brief Initialize a stack
     * 
     * @return Initialized stack
     */
    static Stack &init()
    {
        static Stack stack;
        return stack;
    };

    /**
     * @brief Push an item to stack
     * 
     * @param item you want to push
     * @return true if item is subsecfull added to stack
     * @return false if item is not added to stack
     */
    bool push(int item);

    /**
     * @brief Remove top item from stack
     * 
     * @return true if removing item is successful
     * @return false if item is not successful
     */
    bool pop();

    /**
     * @brief Get the Current Amount of items in stack
     * 
     * @return amount of items in stack 
     */
    int getCurrentSize() { return currentSize; }

    /**
     * @brief Peek the top item inside the stack
     * 
     */
    void peek();

    /**
     * @brief Check if stack is full
     * 
     * @return true if stack is full
     * @return false if stack is not full
     */
    bool isFull() { return currentSize == MAX_SIZE; }

    /**
     * @brief Check if stack is empty
     * 
     * @return true if stack is empty
     * @return false if stack is full
     */
    bool isEmpty() { return currentSize == 0; }

    /**
     * @brief Destroy the Stack object
     * 
     */
    ~Stack() {};
};

#endif // !SINGLETON_H
