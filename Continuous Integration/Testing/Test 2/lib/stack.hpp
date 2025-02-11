#ifndef STACK_HPP
#define STACK_HPP

#include <cstddef>

template <typename T>
class stack
{
    struct node_t
    {
        T item;
        node_t *next;

        node_t(T _item) : item{_item}, next{nullptr} {};
    };

    node_t *top;

    int maxSize;
    int amount;

public:
    stack(size_t size) : top{nullptr}, maxSize{static_cast<int>(size)}, amount{0} {}

    stack(const stack &) = delete;
    stack(const stack &&) = delete;

    stack &operator=(const stack &) = delete;
    stack &operator=(const stack &&) = delete;

    ~stack() { clear(); }

public:
    bool push(T item)
    {
        bool status{true};

        node_t *newNode = new node_t(item);

        if (newNode != nullptr)
        {
            if (!isFull())
            {
                if (top == nullptr)
                {
                    top = newNode;
                    amount++;
                }
                else
                {
                    newNode->next = top;
                    top = newNode;
                    amount++;
                }
            }
            else
            {
                status = false;
            }
            
            delete newNode;
        }
        else
        {
            status = false;
        }

        return status;
    }

    bool pop(T &val)
    {
        bool status{true};

        if (!isEmpty())
        {
            node_t *temp = top;
            val = top->item;
            top = top->next;
            amount--;

            delete top;
        }
        else
        {
            status = false;
        }

        return status;
    }

    bool isFull(void) { return maxSize == amount; }

    bool isEmpty(void) { return amount == 0; }

    T peek(void) { return (top != nullptr) ? top->item : T{}; }

    int getSize(void) { return amount; }

    void clear(void)
    {
        while (top != nullptr)
        {
            node_t *cursor = top;
            top = top->next;
            delete cursor;
        }

        maxSize = 0;
        amount = 0;
    }
};

#endif // !STACK_HPP