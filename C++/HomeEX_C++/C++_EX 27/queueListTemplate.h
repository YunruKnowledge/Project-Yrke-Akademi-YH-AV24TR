/**
 * @file queueListTemplate.h
 * @author Lazar Roksandic (roksandiclazar@gmail.com)
 * @brief Library for Queue Linked List using Template
 * @version 0.1
 * @date 2025-01-15
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef QUEUE_LIST_TEMPLATE
#define QUEUE_LIST_TEMPLATE

#include <iostream>

template <typename T>
class Node
{
public:
    Node *next;
    T item;

    /**
     * @brief Construct a new Node object
     *
     * @param newItem you want to insert into a node
     */
    Node(T newItem)
    {
        this->item = newItem;
        this->next = nullptr;
    }

    ~Node() = default;
};

template <typename T>
class Queue
{
    Node<T> *top;
    Node<T> *bottom;

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
            Node<T> *current = queue.top;
            int counter{1};

            while (current != nullptr)
            {
                os << "Item[" << counter << "]: " << current->item << std::endl;

                counter++;
                current = current->next;
            }
        }
        else
        {
            os << "Queue is empty!";
        }

        return os;
    };

public:
    /**
     * @brief Construct a new Queue object
     *
     * @param size is a max amount of items you want in the queue
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
     * @return true if its full
     * @return false  if its not full
     */
    bool isFull(void) const { return currentAmount == maxAmount; }

    /**
     * @brief Enqueue an item to the queue
     *
     * @param item you want to enqueue
     * @return true if you successfully enqueue the item
     * @return false if you couldn't enqueue the item
     */
    bool enqueue(T item)
    {
        Node<T> *newNode = new Node{item};
        bool status{true};

        if (!this->isFull())
        {
            if (this->isEmpty())
            {
                top = bottom = newNode;
            }
            else
            {
                bottom->next = newNode;
                bottom = newNode;
            }

            currentAmount++;
        }
        else
        {
            delete newNode;
            status = false;
        }

        return status;
    }

    /**
     * @brief Dequeue an item from the queue
     *
     * @return true if you successfully dequeue the item
     * @return false if you couldn't dequeue the item
     */
    bool dequeue(void)
    {
        bool status{true};

        if (!this->isEmpty())
        {
            Node<T> *temp = top;
            top = top->next;

            if (top == nullptr)
            {
                bottom = nullptr;
            }

            currentAmount--;
            delete temp;
        }
        else
        {
            status = false;
        }

        return status;
    }

    /**
     * @brief Get the Top Value from the Queue
     *
     * @return T from the top of the queue
     */
    T getTopValue(void) const
    {
        if (this->isEmpty())
        {
            throw std::out_of_range("Queue is empty!");
        }
        return top->item;
    }

    /**
     * @brief Get the Bottom Value from the Queue
     *
     * @return T from the bottom of the queue
     */
    T getBottomValue(void) const
    {
        if (this->isEmpty())
        {
            throw std::out_of_range("Queue is empty!");
        }
        return bottom->item;
    }

    /**
     * @brief Clear the Queue
     *
     */
    void clear(void)
    {
        while (!this->isEmpty())
        {
            dequeue();
        }
    }

    /**
     * @brief Destroy the Queue and then clear it
     *
     */
    ~Queue() { clear(); };
};

#endif // !QUEUE_LIST_TEMPLATE