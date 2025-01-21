/**
 * @file index.cpp
 * @author Lazar Roksandic (roksandiclazar@gmail.com)
 * @brief Program to create Uncopiable but movable Linked List Queue
 * @version 0.1
 * @date 2025-01-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>

template <typename T>
class Queue
{
    struct Node
    {
        Node *next;
        T item;

        Node(T newItem)
        {
            this->item = 0;
            this->next = nullptr;
        }

        ~Node() {};
    };

    Node *top;
    Node *bottom;

    int currentAmount;
    int maxAmount;

public:
    Queue() = default;

    Queue(const Queue &queue) = delete;
    Queue(Queue &&queue) noexcept : top{queue.top}, bottom{queue.bottom}, currentAmount{queue.currentAmount}, maxAmount{queue.maxAmount}
    {
        delete queue.top;
        delete queue.bottom;

        queue.top = nullptr;
        queue.bottom = nullptr;

        queue.currentAmount = 0;
        queue.maxAmount = 0;
    };

    Queue &operator=(const Queue &queue) = delete;
    Queue &operator=(Queue &&queue) noexcept
    {
        if (this != &queue)
        {
            clear();    

            top = queue.top;
            bottom = queue.bottom;
            currentAmount = queue.currentAmount;
            maxAmount = queue.maxAmount;

            delete queue.top;
            delete queue.bottom;

            queue.top = nullptr;
            queue.bottom = nullptr;
            queue.currentAmount = 0;
            queue.maxAmount = 0;
        }

        return *this;
    };
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
        Node *newNode = new (std::nothrow) Node{item};
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
            Node *temp = top;
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

int main(void)
{
    return 0;
}