#include "list.h"
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

static node_t *head = NULL;
static size_t available = 0;

bool listInsert(int val)
{
    bool returnBool = false;
    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    if (newNode != NULL)
    {
        available++;
        returnBool = true;

        newNode->next = NULL;
        newNode->data = val;

        if (head == NULL)
            head = newNode;
        else
        {
            node_t *currentNode = head;
            while (currentNode->next != NULL)
            {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    return returnBool;
}

bool listGetData(size_t n, int *intPtr)
{
    node_t *cursor = NULL;

    if (intPtr != NULL)
    {
        size_t position = 1;
        cursor = (n > 0) ? head : NULL;

        while ((position < n) && (cursor != NULL))
        {
            cursor = cursor->next;
            position++;
        }

        if (cursor != NULL)
            *intPtr = cursor->data;
    }

    return (cursor != NULL);
}

bool listRemove(size_t n)
{
    size_t position = 1;

    node_t *previous = NULL;
    node_t *current = (n > 0) ? head : NULL;

    while ((position < n) && (current != NULL))
    {
        previous = current;
        current = current->next;
        position++;
    }

    if (current != NULL)
    {
        if (previous == NULL)
            head = current->next;
        else
            previous->next = current->next;

        available--;
        free(current);
    }

    return (current != NULL);
}

bool listUpdate(size_t n, int val)
{
    size_t position = 1;
    node_t *cursor = (n > 0) ? head : NULL;

    while ((position < n) && (cursor != NULL))
    {
        cursor = cursor->next;
        position++;
    }

    if (cursor != NULL)
        cursor->data = val;

    return (cursor != NULL);
}

size_t listAvalble(void)
{
    return available;
}

size_t listFind(int val)
{
    size_t counter = 0;
    size_t position = 0;

    node_t *cursor = head;

    while (cursor != NULL)
    {
        counter++;

        if (cursor->data == val)
        {
            position = counter;
            break;
        }

        cursor = cursor->next;
    }

    return position;
}

void listDelete(void)
{
    while (head !=NULL)
    {
        node_t *next = head->next;
        free(head);
        head=next;
    }
    available = 0; 
}
