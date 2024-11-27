#include <stdio.h>
#include <stdlib.h>
#include "module.h"

typedef struct Node
{
    int data;
    struct Node *next;
} Node_t;

typedef struct linkedList
{
    int size;
    Node_t *head; // point to the first node
} linkedList_t;

linkedList_t *createLinkedList()
{
    linkedList_t *list = (linkedList_t *)malloc(sizeof(linkedList_t));
    list->head = NULL;
    list->size = 0;
    return list;
}

// createNewNode
Node_t *createNode(int data)
{
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));

    newNode->data = data; // newly created Nodes data is the argument passed in yani.
    newNode->next = NULL;
    return newNode;
}

// add element to end of list
void addElement(linkedList_t *list, int data)
{
    Node_t *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        Node_t *current = list->head;
        // while next node exists, switch the current to it.
        while (current->next != NULL)
        {
            current = current->next;
        }
        // while next is NULL, assign newNode as the next.
        current->next = newNode;
    }
    list->size++;
}

void removeElement(linkedList_t *list)
{
    if (list->head == NULL)
    {
        printf("Empty list!");
        return;
    }

    if (list->head->next == NULL)
    {
        free(list->head);
        list->head = NULL;
    }
    else
    {
        Node_t *current = list->head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->size--;
}

void printList(linkedList_t *list)
{
    if (list->head == NULL)
    {
        printf("Empty list!");
        exit(2);
    }

    Node_t *current = list->head;
    printf("List elements: ");

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}