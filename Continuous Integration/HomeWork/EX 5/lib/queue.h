#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class queue
{
    struct node
    {
        T item;
        node *next;

        node(T _item) : item{_item}, next{nullptr} {};
    };

    node *top;
    node *bottom;

    int count;

public:
    queue() : top{nullptr}, bottom{nullptr}, count{0} {};

    queue(const queue &) = delete;
    queue(queue &&q) noexcept : top{q.top}, bottom{q.bottom}, count{q.count}
    {
        q.top = q.bottom = nullptr;
        q.count = 0;
    };

    queue &operator=(const queue &) = delete;
    queue &operator=(queue &&q)
    {
        if (this != &q)
        {
            clear();
        }

        top = q.top;
        bottom = q.bottom;
        count = q.count;

        q.top = q.bottom = nullptr;
        q.count = 0;

        return *this;
    };

    ~queue() { clear(); };

public:
    bool enqueue(T item)
    {
        bool status{true};

        node *newNode = new node{item};

        if (newNode == nullptr)
            status = false;

        if (top == nullptr)
        {
            top = bottom = newNode;
            count++;
        }
        else
        {
            bottom->next = newNode;
            bottom = newNode;
            count++;
        }

        return status;
    }

    bool dequeue(void)
    {
        bool status{true};

        if (!isEmpty())
        {
            node *cursor = top;
            top = top->next;

            while (top == nullptr)
            {
                bottom = nullptr;
            }

            count--;
            delete cursor;
        }
        else
        {
            status = false;
        }

        return status;
    };

    T peek(void) { return (top != nullptr) ? top->item : T{}; }

    int getSize(void) { return count; }

    bool isEmpty(void) { return count == 0; };

    void clear(void)
    {
        while (top != nullptr)
        {
            node *cursor = top;
            top = top->next;
            delete cursor;
        }

        bottom = nullptr;
        count = 0;
    };
};

#endif // !QUEUE_H