/*
Description:

Implement a multiple-instance linked list module of unique and sorted data elements of type int.

 The module shall be tested using assertion and support the following operations:

Creating a list
Inserting a new node in a list
Change a data element in a list
Deleting a value from a list
Searching for a value in a list
Getting data stored in the nth node of a list
Getting available number of elements stored in a list
Destroying a list


Sorted means that when you want to add a new data element, you should find the right position for the new node in a way that the list is always sorted.
*/
#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

typedef list
{
    node_t *node;
    int size; 
} list_t;

/* THE FUNCTIONS   */

//return type list_t, create it.
list_t *create_list(){

    list_t *_newList = (list_t *)malloc(sizeof(list_t));//allocate memory.
    if (!_newList)
    {
        perror("Failed to create the list!");
        return NULL;
    }

    _newList->head = NULL;
    _newList->size = 0;

    return _newList;
}

//INSERT NEW NODE INTO LIST
bool insertNode(){
    

}


int main()
{
    node_t node1;
    node_t node2;

    list_t listForNodes;




    node1.data = 88;
    node1.next = &node2;

    printf("%i", node1.data);


    return 0;
}