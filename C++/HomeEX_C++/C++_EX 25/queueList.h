/**
 * @file queueList.h
 * @author Lazar Roksandic (roksandiclazar@gmail.com)
 * @brief Library for creating a connected list Queue
 * @version 0.1
 * @date 2025-01-14
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include <iostream>

class Node
{
public:
    int item;
    Node *next;

    Node(int newItem)
    {
        this->item = newItem;
        this->next = nullptr;
    }
};

class Queue
{
    Node *top;
    Node *bottom;

    int currentAmount;
    int maxAmount;

public:
    Queue(const Queue &queue) = delete;
    Queue(Queue &&queue) = delete;

    Queue &operator=(const Queue &queue) = delete;
    Queue &operator=(Queue &&queue) = delete;

    /**
     * @brief Overload cin to print entire queue
     *
     * @param os you want to print
     * @param queue you want to go throw
     * @return std::ostream& cin out all items from the queue
     */
    friend std::ostream &operator<<(std::ostream &os, const Queue &queue)
    {
        if (!queue.isEmpty())
        {
            Node *current = queue.top;
            int counter{1};

            os << std::endl;

            while (current != nullptr)
            {
                os << "Item[" << counter << "]: " << current->item << std::endl;

                counter++;
                current = current->next;
            }
        }
        else
        {
            os << "Queue is empty!" << std::endl;
        }

        return os;
    };

public:
    /**
     * @brief Construct a new Queue object
     *
     * @param size of your queue
     */
    Queue(int size) : top{nullptr}, bottom{nullptr}, currentAmount{0}, maxAmount{size} {};

    /**
     * @brief Check if queue is empty
     * 
     * @return true if its empty
     * @return false if its not empty
     */
    bool isEmpty(void) const { return top == nullptr; }

    /**
     * @brief Check if queue is full
     * 
     * @return true if queue is full
     * @return false if queue is not full
     */
    bool isFull(void) const { return maxAmount == currentAmount; }

    /**
     * @brief Enqueue an item to the queue
     * 
     * @param item you want to enqueue
     * @return true if you enqueue the item successfully
     * @return false if you fail to enqueue the item to the queue
     */
    bool enqueue(int item);

    /**
     * @brief Dequeue the item form the queue
     * 
     * @return true if you successfully dequeue the item from the queue
     * @return false if you fail to dequeue the item from the queue
     */
    bool dequeue(void);

    /**
     * @brief Get the Top Item from the queue
     * 
     * @return int item from the top of the queue
     */
    int getTopItem(void) const { return !this->isEmpty() ? top->item : 0; }

    /**
     * @brief Get the Bottom Item from the queue
     * 
     * @return int item from the bottom of the queue
     */
    int getBottomItem(void) const { return !this->isEmpty() ? bottom->item : 0; }

    /**
     * @brief Get the Number Of Items in the queue
     * 
     * @return int amount of items in currently in the queue
     */
    int getNumberOfItems(void) const { return currentAmount; }

    /**
     * @brief Clear the entire queue
     * 
     */
    void clear(void)
    {
        currentAmount = 0;
        top = bottom = nullptr;
    }

    ~Queue() {};
};

#endif // !QUEUE_LIST_H
