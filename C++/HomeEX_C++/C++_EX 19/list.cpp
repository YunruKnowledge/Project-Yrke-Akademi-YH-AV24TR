#include "list.h"
#include <new>

using namespace std;

struct node_t
{
    int data;
    node_t *next;
};

struct list_t
{
    node_t *head;
    int elem_num;
};

list_t *List::create(void)
{
    return new (nothrow) list_t{nullptr, 0};
}

bool List::insert(list_t *list, int value)
{
    bool state{false};

    if (list != nullptr)
    {
        node_t *node{new (nothrow) node_t{value, nullptr}};

        if (list->head == nullptr)
        {
            list->head = node;
        }
        else
        {
            node_t *cursor = list->head;
            while (cursor->next != nullptr)
            {
                cursor = cursor->next;
            }
            cursor->next = node;
        }

        list->elem_num++;
        state = true;
    }

    return state;
}

bool List::search(list_t *list, int value)
{
    bool state{false};

    if (list != nullptr)
    {
        node_t *cursor{list->head};

        while (cursor != nullptr)
        {
            if (cursor->data == value)
            {
                state = true;
                break;
            }

            cursor = cursor->next;
        }
    }

    return state;
}

bool List::remove(list_t *list, int value)
{
    bool status{false};

    if (list != nullptr)
    {
        node_t *previous{nullptr};
        node_t *current(list->head);

        while (current != nullptr)
        {
            if (current->data == value)
            {
                if (previous == nullptr)
                {
                    list->head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }

                delete current;

                status = true;
                list->elem_num--;

                break;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
    }

    return status;
}

bool List::edit(list_t *list, int oldValue, int newValue)
{
    bool status{false};

    if (list != nullptr)
    {
        node_t *cursor{list->head};

        while (cursor != nullptr)
        {
            if (cursor->data == oldValue)
            {
                cursor->data = newValue;
                status = true;
                break;
            }

            cursor = cursor->next;
        }
    }

    return status;
}

void List::clear(list_t *list)
{
    if (list != nullptr)
    {
        node_t *current;

        while (list->head != nullptr)
        {
            current = list->head;
            list->head = list->head->next;
            delete current;
        }

        list->elem_num = 0;
    }
}

void List::destroy(list_t *&list)
{
    if (list != nullptr)
    {
        node_t *current;

        while (list->head != nullptr)
        {
            current = list->head;
            list->head = list->head->next;
            delete current;
        }

        delete list;
        list = nullptr;
    }
}

int List::getAmountOfData(list_t *list)
{
    return list->elem_num;
}