#include <iostream>
#include "list.h"

bool List::insert(int item)
{
    bool status{true};
    Node *newNode = new (std::nothrow) Node{nullptr, item};

    if (top == nullptr)
    {
        top = newNode;
        elem_num++;
    }
    else if (newNode != nullptr)
    {
        Node *cursor = top;
        while (cursor->next != nullptr)
        {
            if (cursor->item == item)
            {
                status = false;
                delete newNode;
                break;
            }

            cursor = cursor->next;
        }

        if (status)
        {
            cursor->next = newNode;
            elem_num++;
            sort();
        }
    }
    else
    {
        status = false;
    }

    return status;
}

bool List::modify(int oldItem, int newItem)
{
    bool status{false};

    if (top != nullptr)
    {
        Node *cursor = top;

        while (cursor != nullptr)
        {
            if (cursor->item == oldItem)
            {
                cursor->item = newItem;
                status = true;
                sort();
                break;
            }

            cursor = cursor->next;
        }
    }

    return status;
}

bool List::remove(int item)
{
    bool status{false};

    if (top != nullptr)
    {
        if (top->item == item)
        {
            top = top->next;
            status = true;
            elem_num--;
        }
        else
        {
            Node *cursor = top;

            while (cursor->next != nullptr)
            {
                if (cursor->next->item == item)
                {
                    cursor->next = cursor->next->next;

                    sort();

                    status = true;
                    elem_num--;

                    break;
                }

                cursor = cursor->next;
            }
        }
    }

    return status;
}

int List::search(int item)
{
    int position{0};
    bool found{false};

    if (top != nullptr)
    {
        Node *cursor = top;
        position = 1;

        while (cursor != nullptr)
        {
            if (cursor->item == item)
            {
                found = true;
                break;
            }

            cursor = cursor->next;
            position++;
        }

        if (!found)
        {
            position = 0;
        }
    }

    return position;
}

void List::sort()
{
    if (top != nullptr)
    {
        bool swapped;
        do
        {
            swapped = false;
            Node *cursor = top;

            while (cursor->next != nullptr)
            {
                if (cursor->item > cursor->next->item)
                {
                    swap(cursor, cursor->next);
                    swapped = true;
                }

                cursor = cursor->next;
            }
        } while (swapped);
    }
}

void List::swap(Node *a, Node *b)
{
    int temp{a->item};
    a->item = b->item;
    b->item = temp;
}

void List::print()
{
    if (top != nullptr)
    {
        Node *cursor = top;
        while (cursor != nullptr)
        {
            std::cout << "[Item] : " << cursor->item << std::endl;
            cursor = cursor->next;
        }
    }
    else
    {
        std::cout << "List is empty" << std::endl;
    }
}

void List::clear()
{
    top = nullptr;
    elem_num = 0;
}