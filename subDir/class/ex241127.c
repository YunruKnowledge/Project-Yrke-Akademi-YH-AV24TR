// Create a Node Structure: Create a structure called Node that represents a
// node in the linked list. The structure should have two fields: data, which
// stores the data of the node, and next, which stores the address of the next
// node in the list.

// Create a Linked List Structure: Create a structure called LinkedList that
// represents the linked list. The structure should have two fields: head, which
// stores the address of the first node in the list, and size, which stores the
// number of elements in the list.

// Implement Basic Operations: Implement basic operations for the linked list,
// such as adding an element to the end of the list, removing an element from
// the end of the list, and printing the elements of the list.

// Test the Linked List: Test the linked list by adding and removing elements,
// and printing the elements of the list. Hints: Use dynamic memory allocation
// to create new nodes and add them to the list. Use a pointer to the last node
// in the list to add elements to the end of the list. Use a pointer to the
// second-to-last node in the list to remove the last element from the list. Use
// a loop to traverse the list and print the elements.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SECOND_LAST_NODE 2

typedef struct NODE {
  int data;
  struct NODE *nextNode;
  struct NODE *prevNode;
} node_t;

typedef struct LinkedList {
  struct NODE *head;
  size_t size;
} link_t;

void test(void);
link_t *listCreate(void);
bool listAddNode(link_t *_list, const size_t _data);
bool listRemoveLastNode(link_t *_list);
void listRead(link_t *_list);
void listFree(link_t *_list);

link_t *listCreate(void) {
  link_t *_link = (link_t *)malloc(sizeof(link_t));
  _link->head = NULL;
  _link->size = 0;
  return _link;
}

bool listAddNode(link_t *_list, const size_t _data) {
  node_t *_node = (node_t *)malloc(sizeof(node_t));
  if (_node != NULL && _list != NULL) {
    _node->data = _data;
    _node->nextNode = NULL;
    if (_list->head != NULL) {
      node_t *_temp = _list->head;
      while (_temp->nextNode != NULL) {
        _temp = _temp->nextNode;
      }
      _temp->nextNode = _node;
    } else {
      _list->head = _node;
    }
    _list->size++;
  }
  return (_node != NULL);
}

bool listRemoveLastNode(link_t *_list) {
  bool _success = false;
  if (_list != NULL) {
    node_t *_temp = _list->head;
    for (size_t i = 0; i < _list->size - SECOND_LAST_NODE; i++) {
      _temp = _temp->nextNode;
    }
    free(_temp->nextNode);
    _temp->nextNode = NULL;
    _list->size--;
    _success = true;
  }
  return _success;
}

void listRead(link_t *_list) {
  if (_list != NULL) {
    (void)printf("[%u]", _list->size);
    node_t *_temp = _list->head;
    while (_temp != NULL) {
      (void)printf(" %u ->", _temp->data);
      _temp = _temp->nextNode;
    }
    (void)printf(" NULL\n");
  }
}

void listFree(link_t *_list) {
  if (_list != NULL) {
    while (_list->head != NULL) {
      node_t *_temp = _list->head->nextNode;
      free(_list->head);
      _list->head = _temp;
    }
    free(_list);
    _list = NULL;
  }
}

int main() {
  link_t *list1 = listCreate();
  listAddNode(list1, 11);
  listAddNode(list1, 23);
  listAddNode(list1, 36);
  listRead(list1);

  listRemoveLastNode(list1);
  listRead(list1);

  listFree(list1);

  link_t *list2 = listCreate();
  listAddNode(list2, 13);
  listAddNode(list2, 26);
  listAddNode(list2, 356);
  listRead(list2);

  listRemoveLastNode(list2);
  listRemoveLastNode(list2);
  listRead(list2);

  listFree(list2);
  // test();
  return 0;
}

void test(void) {

  node_t test1;
  test1.data = 12;
  test1.nextNode = NULL;
  test1.prevNode = NULL;

  node_t test2;
  test2.data = 24;
  test2.nextNode = NULL;
  test2.prevNode = NULL;

  node_t test3;
  test3.data = 33;
  test3.nextNode = NULL;
  test3.prevNode = NULL;

  test1.nextNode = &test2;
  test2.nextNode = &test3;

  test2.prevNode = &test1;
  test3.prevNode = &test2;

  // merge
  node_t test4_2;
  test4_2.data = 420;
  test4_2.nextNode = NULL;
  test4_2.prevNode = NULL;

  test4_2.nextNode = &test2;
  test4_2.prevNode = &test1;
  test1.nextNode = &test4_2;
  test2.prevNode = &test4_2;

  node_t *current = &test1;
  for (size_t i = 1; current->nextNode != NULL; i++) {
    printf("[%i]: %i\n", i, current->data);
    current = current->nextNode;
    if (current->nextNode == NULL)
      printf("[%i]: %i\n", i + 1, current->data);
  }

  for (size_t i = 1; current->prevNode != NULL; i++) {
    printf("[%i]: %i\n", i, current->data);
    current = current->prevNode;
    if (current->prevNode == NULL)
      printf("[%i]: %i\n", i + 1, current->data);
  }
}