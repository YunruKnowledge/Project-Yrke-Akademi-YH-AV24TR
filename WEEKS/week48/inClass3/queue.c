/*
implement a queue using an array in C, with the following funcs
enqueue(int element): Add an element to the end of the queue.
dequeue(): Remove an element from the front of the queue.
printQueue(): Print the elements in the queue.
isEmpty(): Check if the queue is empty.
iSFull():  Check if the queue is full.

*/

#include <stdio.h>
#include <stdbool.h>
// typedef struct node
// {
//     int data;
//     struct node *next;
// } node_t;

// struct queue
// {
//     node_t *head;
//     node_t *tail;
//     size_t available;
// };
#define MAX 8

static int arr[MAX];
int head = 0, tail = 0, counter = 0;

void enqueue(int element)
{
    arr[head] = element;
    head++;
    counter++;

    // return arr;
}

void dequeue(int e){
    if (arr[tail] != NULL)
    {
        
    }
    
    tail++;
}

void printQueue()
{
    for (int i = 0; i < head; i++)
    {
        printf("pos %i has: %i\n", i, arr[i]);

    }
}

bool isEmpty()
{
    return (counter == 0);
}
