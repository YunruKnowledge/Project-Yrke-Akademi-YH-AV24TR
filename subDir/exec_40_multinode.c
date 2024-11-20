#include "exec_40_multinode.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct NODE {
  int value;
  struct NODE *nextNode;
} node_t;
static node_t *HEAD = NULL;
static size_t COUNT;

bool nodeListCreate(const int _value) {
  node_t *_node = (node_t *)malloc(sizeof(node_t));

  if (_node) {
    _node->value = _value;
    _node->nextNode = NULL;

    if (!HEAD) {
      HEAD = _node;
    } else {
      node_t *_temp = HEAD;
      while (_temp->nextNode) {
        _temp = _temp->nextNode;
      }
      _temp->nextNode = _node;
    }

    COUNT++;
  }

  return _node ? true : false;
}

bool nodeListChange(const int _value, size_t _index) {
  size_t _whileIndex = 1;
  node_t *_currentNode = (_index > 0) ? HEAD : NULL;
  if (_currentNode) {
    while ((_whileIndex < _index) && (_currentNode != NULL)) {
      _currentNode = _currentNode->nextNode;
      _whileIndex++;
    }
    _currentNode->value = _value;
  }

  return (_currentNode != NULL);
}

bool nodeListDelete(const size_t _index) {
  size_t _whileIndex = 1;
  node_t *_prevNode = NULL;
  node_t *_currNode = (_index > 0) ? HEAD : NULL;

  while ((_whileIndex < _index) && (_currNode != NULL)) {
    _prevNode = _currNode;
    _currNode = _currNode->nextNode;
    _whileIndex++;
  }

  if (_currNode) {
    if (!_prevNode) {
      HEAD = _currNode->nextNode;
    } else {
      _prevNode->nextNode = _currNode->nextNode;
    }
    COUNT--;
    free(_currNode);
  }

  return (_currNode != NULL);
}

size_t nodeListSearchValue(const int _value) {
  size_t _index = 0, _queryIndex = 0;
  node_t *_currNode = HEAD;

  while (_currNode) {
    _index++;
    if (_currNode->value == _value) {
      _queryIndex = _index;
      break;
    } else {
      _currNode = _currNode->nextNode;
    }
  }

  return _queryIndex;
}

bool nodeListSearchNode(int *_interger, const size_t _index) {
  node_t *_currNode = NULL;

  if (_interger != NULL) {
    size_t _whileIndex = 1;
    node_t *_currNode = (_index > 0) ? HEAD : NULL;

    while ((_whileIndex < _index) && (_currNode != NULL)) {
      _currNode = _currNode->nextNode;
      _whileIndex++;
    }

    if (_currNode) {
      *_interger = _currNode->value;
    }
  }

  return (_currNode != NULL);
}

size_t nodeListGetCount(void) { return COUNT; }

void nodeListFreeAll(void) {
  while (HEAD) {
    node_t *_nextNode = HEAD->nextNode;
    free(HEAD);
    HEAD = _nextNode;
  }
  COUNT = 0;
}