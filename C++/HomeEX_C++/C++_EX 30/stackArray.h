/**
 * @file stackArray.h
 * @author Lazar Roksandic (roksandiclazar@gmail.com)
 * @brief A library for Template Stack Array that is Uncopiable but Movable class
 * @version 0.1
 * @date 2025-01-21
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <iostream>
#include <ostream>

constexpr int MIN_SIZE = 3; // Min size of an array

template <typename T>
class Stack
{
    T *arr;

    int amount;
    int maxSize;

public:
    Stack<T>() = default;

    /**
     * @brief Overload cin << to print stack
     *
     * @param os what you want to print
     * @param stack you want to take items from
     * @return std::ostream& all items from the stack
     */
    friend std::ostream &operator<<(std::ostream &os, const Stack &stack)
    {
        if (!stack.isEmpty())
        {
            for (int i = 0; i < stack.amount; i++)
            {
                os << "[ " << i << " ]: " << stack.arr[i] << std::endl;
            }
        }
        else
        {
            os << "Stack is empty!" << std::endl;
        }

        return os;
    }

    /**
     * @brief Construct a new Stack object and move old stack into it
     *
     * @param stack You want to move
     */
    Stack(Stack &&stack) noexcept : arr{stack.arr}, amount{stack.amount}, maxSize{stack.maxSize}
    {
        stack.arr = nullptr;
        stack.amount = 0;
        stack.maxSize = 0;
    }

    /**
     * @brief Move old stack to the new one
     *
     * @param stack you want to move
     * @return Stack& of data
     */
    Stack &operator=(Stack &&stack) noexcept
    {
        if (this != stack)
        {
            delete arr;

            arr = stack.arr;
            amount = stack.amount;
            maxSize = stack.maxSize;

            stack.arr = nullptr;
            stack.amount = 0;
            stack.maxSize = 0;
        }

        return *this;
    }

    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &stack) = delete;

public:
    /**
     * @brief Construct a new Stack object
     *
     * @param size you want your stack to have (Min 3)
     */
    Stack(int size = MIN_SIZE) : amount{0}, maxSize{size}
    {
        if (size < MIN_SIZE)
        {
            std::string errorMsg{"Min array size must be 3"};
            throw errorMsg;
        }
        else
        {
            arr = new (std::nothrow) T[size];
            if (!arr)
            {
                throw std::runtime_error("Memory allocation failed!");
            }
        }
    }

    /**
     * @brief Push an item to the stack
     *
     * @param item you want to push
     * @return true if you push item successfully
     * @return false if you couldn't push item to the stack
     */
    bool push(T item)
    {
        bool status{false};

        if (!isFull())
        {
            arr[amount] = item;
            amount++;
            status = true;
        }

        return status;
    }

    /**
     * @brief Pop an item from the top of the stack
     *
     * @param ref for the pooped item
     * @return true if you successfully pooped the item
     * @return false if you couldn't pop the item
     */
    bool pop(T *ref = nullptr)
    {
        bool status{false};

        if (!isEmpty())
        {
            if (ref)
            {
                *ref = arr[amount - 1];
            }

            amount--;
            status = true;
        }

        return status;
    }

    /**
     * @brief Peek the top item from the stack
     * 
     */
    void peek(void)
    {
        if (!isEmpty())
        {
            std::cout << "Peeked value is: " << arr[amount - 1] << std::endl;
        }
        else
        {
            std::cout << "Stack is empty" << std::endl;
        }
    }

    /**
     * @brief Check if stack is full
     * 
     * @return true if stack is full
     * @return false if stack is not full
     */
    bool isFull(void) const { return amount == maxSize; }

    /**
     * @brief Check if stack is empty
     * 
     * @return true if stack is empty
     * @return false if stack is not empty
     */
    bool isEmpty(void) const { return amount == 0; }

    /**
     * @brief Clear the stack
     * 
     */
    void clear(void) { amount = 0; }

    /**
     * @brief Destroy the Stack object
     * 
     */
    ~Stack()
    {
        delete arr;
    };
};

#endif // !STACK_ARRAY_H