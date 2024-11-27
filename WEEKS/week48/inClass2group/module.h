#ifndef MODULE_H
#define MODULE_H

#include <stdio.h>

typedef struct Node Node_t;

typedef struct linkedList linkedList_t;

linkedList_t *createLinkedList();
// createNewNode
Node_t *createNode(int data);

// add element to end of list
void addElement(linkedList_t *list, int data);

void removeElement(linkedList_t *list);

void printList(linkedList_t *list);

#endif //MODULE_H