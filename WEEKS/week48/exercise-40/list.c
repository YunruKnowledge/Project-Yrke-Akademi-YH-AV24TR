#include "list.h"
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

struct list
{
    node_t *head;
    size_t available;
};

list_t *list_create(void)
{
    list_t *list = (list_t *)malloc(sizeof(list_t));

    if (list != NULL)
    {
        list->available = 0;
        list->head = NULL;
    }

    return list;
}

bool list_insert(list_t *list, int value)
{
    bool status = false;

    if (list != NULL)
    {
        node_t *previous = NULL;
        node_t *current = list->head;

        // Find position of the new node
        while (current != NULL)
        {
            if (current->data >= value)
            {
                break;
            }
            previous = current;
            current = current->next;
        }

        if ((current == NULL) || (current->data != value)) // Check if value is unique
        {
            node_t *new_node = (node_t *)malloc(sizeof(node_t));

            if (new_node != NULL)
            {
                status = true;
                list->available++;
                new_node->next = NULL;
                new_node->data = value;

                // Add the node to
                if (current == NULL && previous == NULL) /* the empty list */
                {
                    list->head = new_node;
                }
                else if (current != NULL && previous == NULL) /* the begining of the list */
                {
                    list->head = new_node;
                    new_node->next = current;
                }
                else if (current == NULL && previous != NULL) /* the end of the list */
                {
                    previous->next = new_node;
                }
                else /* before the current node */
                {
                    new_node->next = current;
                    previous->next = new_node;
                }
            }
        }
    }

    return status;
}

ssize_t list_available(list_t *list)
{
    ssize_t available = -1;

    if (list != NULL)
    {
        available = list->available;
    }

    return available;
}

size_t list_find(list_t *list, int value)
{
    size_t position = 0;

    if (list != NULL)
    {
        size_t counter = 0;
        node_t *cursor = list->head;

        while (cursor != NULL)
        {
            counter++;

            if (cursor->data == value)
            {
                position = counter;
                break;
            }

            cursor = cursor->next;
        }
    }

    return position;
}

bool list_get_data(list_t *list, size_t n, int *data)
{
    node_t *cursor = NULL;

    if ((list != NULL) && (data != NULL))
    {
        size_t position = 1;
        cursor = (n > 0) ? list->head : NULL;

        while ((position < n) && (cursor != NULL))
        {
            cursor = cursor->next;
            position++;
        }

        if (cursor != NULL)
        {
            *data = cursor->data;
        }
    }

    return (cursor != NULL);
}

bool list_delete(list_t *list, int value)
{
    bool status = false;

    if (list != NULL)
    {
        node_t *previous = NULL;
        node_t *current = list->head;

        while (current != NULL)
        {
            if (current->data == value)
            {
                if (previous == NULL)
                {
                    list->head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }

                list->available--;
                status = true;
                free(current);
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

bool list_update(list_t *list, int oval, int nval)
{
    bool status = false;

    if (list != NULL)
    {
        if (0 == list_find(list, nval))
        {
            if (list_delete(list, oval))
            {
                status = list_insert(list, nval);
            }
        }
    }

    return status;
}

void list_destroy(list_t **list)
{
    if ((list != NULL) && (*list != NULL))
    {
        node_t *current = (*list)->head;

        while (current != NULL)
        {
            (*list)->head = current->next;
            free(current);
            current = (*list)->head;
        }

        free(*list);
        *list = NULL;
    }
}