/*
Create a Node Structure: Create a structure called Node that represents a node in the linked list. The structure should have two fields: data, which stores the data of the node, and next, which stores the address of the next node in the list.

Create a Linked List Structure: Create a structure called LinkedList that represents the linked list. The structure should have two fields: head, which stores the address of the first node in the list, and size, which stores the number of elements in the list.

Implement Basic Operations: Implement basic operations for the linked list, such as adding an element to the end of the list, removing an element from the end of the list, and printing the elements of the list.

Test the Linked List: Test the linked list by adding and removing elements, and printing the elements of the list.
Hints:
Use dynamic memory allocation to create new nodes and add them to the list.
Use a pointer to the last node in the list to add elements to the end of the list.
Use a pointer to the second-to-last node in the list to remove the last element from the list.
Use a loop to traverse the list and print the elements.
*/

#include <stdio.h>
#include <stdlib.h>
#include "module.h"

int main()
{
    linkedList_t *list = createLinkedList();

    // add elements
    addElement(list, 10);
    addElement(list, 20);
    addElement(list, 30);

    // print the elements
    printList(list);

    // removing removing elements that added
    removeElement(list);
    printList(list);
    removeElement(list);
    printList(list);
    removeElement(list);
    printList(list);

    // remove from empty list
    removeElement(list);

    // free after use
    free(list);

    return 0;
}
