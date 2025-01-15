/**
 * @file stackList.h
 * @author Lazar Roksandic (roksandiclazar@gmail.com)
 * @brief Library to create stack of linked list
 * @version 0.1
 * @date 2025-01-09
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef STACKLIST_H
#define STACKLIST_H

#include <iostream>

class Node
{
public:
    int item;
    Node *next;

    /**
     * @brief Destroy the Node object
     * 
     */
    ~Node() {};
};

class Stack : public Node
{
    Node *top{nullptr};

public:
    static int amount;

    /**
     * @brief Function to overload cout
     *
     * @param os What you want to display
     * @param stack information you want to take from
     * @return desired text
     */
    friend std::ostream &operator<<(std::ostream &os, Stack &stack)
    {
        Node *current = stack.top;
        int counter{1};

        while (current != nullptr)
        {
            os << "Item[" << counter << "]: " << current->item << std::endl;

            counter++;
            current = current->next;
        }

        return os;
    }

public:
    /**
     * @brief Construct a new Stack object
     *
     */
    Stack() : top{nullptr} {};

    /**
     * @brief Push an item to the stack
     * 
     * @param item you want to push
     * @return true if item is successfully pushed to the stack
     * @return false if item is not successfully pushed to the stack
     */
    bool push(int item);

    /**
     * @brief Pop the top item from the stack
     * 
     * @return true if item is successfully popped
     * @return false if item is not successfully popped
     */
    bool pop(void);

    /**
     * @brief Peek the top item from the stack
     * 
     * @return true if peek is successful
     * @return false if peek is not successful
     */
    bool peek(void) const;

    /**
     * @brief Get the Amount Of Items inside the stack
     * 
     * @return int amount of items
     */
    int getAmountOfItems() { return amount; }

    /**
     * @brief Clear the stack
     * 
     */
    void clear();

    /**
     * @brief Destroy the Stack object
     * 
     */
    ~Stack() { clear(); };
};

#endif // !STACKLIST_H