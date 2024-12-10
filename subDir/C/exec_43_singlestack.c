

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int value;
  struct NODE *nextNode;
} node_t;

static struct NODE *TOP_NODE = NULL;
static size_t COUNT = 0;

/**
 * @brief Pushes a value as a node into the stack.
 * 
 * @param _value Interger to apply into node.
 * @return `true` is success. 
 */
bool stackPush(const int _value);

/**
 * @brief Reads the top of stack, and remove node.
 * 
 * @param _iptr 
 * @return `true` if success.
 */
bool stackPop(int *_iptr);

/**
 * @brief Returns the count of nodes in stack, optionally can be set to verbose.
 * 
 * @param _verbal Prints all node values to terminal if `true`
 * @return size_t - count of nodes.
 */
size_t stackGetCount(bool _verbal);

/**
 * @brief Frees all nodes from memory (in the stack).
 * 
 */
void stackFree(void);

/**
 * @brief Assert test run.
 * 
 */
int main() {
  (void)printf("TESTING PUSH...\n");
  stackPush(77);
  stackPush(66);
  stackPush(800);
  assert(3 == stackGetCount(true));

  (void)printf("TESTING POP...\n");
  int _temp;
  stackPop(&_temp);
  (void)printf("%i\n", _temp);
  assert(800 == _temp);

  stackPop(&_temp);
  (void)printf("%i\n", _temp);
  assert(66 == _temp);

  (void)printf("TESTING FREE...\n");
  assert(1 == stackGetCount(false));

  stackFree();
  assert(0 == stackGetCount(true));

  return 0;
}

bool stackPush(const int _value) {
  bool _success = false;

  node_t *_node = (node_t *)malloc(sizeof(node_t));
  if (_node) {
    if (!TOP_NODE) {
      _node->value = _value;
      _node->nextNode = NULL;
      TOP_NODE = _node;
    } else {
      _node->value = _value;
      _node->nextNode = TOP_NODE;
      TOP_NODE = _node;
    }
    _success = true;
    COUNT++;
  }
  return _success;
}

bool stackPop(int *_iptr) {
  bool _success = false;
  if (TOP_NODE) {
    *_iptr = TOP_NODE->value;
    node_t *_temp = TOP_NODE->nextNode;
    free(TOP_NODE);
    TOP_NODE = _temp;
    COUNT--;
    _success = true;
  }
  return _success;
}

size_t stackGetCount(bool _verbal) {
  if (_verbal) {
    (void)printf("Count: %u |", COUNT);
    node_t *_temp = TOP_NODE;
    while (_temp) {
      (void)printf(" %i ->", _temp->value);
      _temp = _temp->nextNode;
    }
    (void)printf(" NULL\n");
  }
  return COUNT;
}

void stackFree(void) {
  while (TOP_NODE) {
    node_t *_temp = TOP_NODE->nextNode;
    free(TOP_NODE);
    TOP_NODE = _temp;
  }
  COUNT = 0;
}