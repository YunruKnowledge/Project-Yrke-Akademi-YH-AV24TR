#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node_t;

int main()
{

    Node_t node1;
    node1.data = 19;
    node1.next = NULL;
    node1.prev = NULL;

    Node_t node2;
    node2.data = 40;
    node2.next = NULL;
    node2.prev = NULL;

    Node_t node3;
    node3.data = 80;
    node3.next = NULL;
    node3.prev = NULL;

    Node_t node4;
    node4.data = 25;
    node4.next = NULL;
    node4.prev = NULL;

    node1.next = &node4;
    node1.prev = NULL;

    node2.next = &node3;
    node2.prev = &node4;

    node3.next = NULL;
    node3.prev = &node2;

    node4.next = &node2;
    node4.prev = &node1;

    Node_t *head = &node1;
    Node_t *tail = &node3;

    // struct of ptr current, points to address of node1; while current is not NULL(empty)
    // Current is, current of next.
        printf("Forward: ");
    for (Node_t *current = head; current != NULL; current = current->next)
    {
        printf("%d -> ", current->data);
    }

    printf("\n");

        printf("Backward: ");
    for (Node_t *current = tail; current != NULL; current = current->prev)
    {
        printf("%d -> ", current->data);
    }

    printf("NULL\n");

    return 0;
}
