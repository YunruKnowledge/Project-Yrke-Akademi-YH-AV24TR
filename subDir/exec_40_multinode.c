#include "exec_40_multinode.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct NODE {
  int value;
  struct NODE *nextNode;
} node_t;

typedef struct LIST {
  node_t *HEAD;
  size_t COUNT;
} list_t;


list_t *nodeListCreate(void) {
  list_t *_list = (list_t *)malloc(sizeof(list_t));
  if (_list) {
    _list->HEAD = NULL;
    _list->COUNT = 0;
  }

  return _list;
}

bool nodeListCreateNode(list_t *_list, const int _value) {
  node_t *_node = (node_t *)malloc(sizeof(node_t));

  if (_node && _list) {
    _node->value = _value;
    _node->nextNode = NULL;

    if (!_list->HEAD) {
      _list->HEAD = _node;
    } else {
      node_t *_temp = _list->HEAD;
      while (_temp->nextNode) {
        _temp = _temp->nextNode;
      }
      _temp->nextNode = _node;
    }

    _list->COUNT++;
  }

  return _node ? true : false;
}

bool nodeListChange(list_t *_list, const int _value, size_t _index) {
  size_t _whileIndex = 1;
  node_t *_currentNode = NULL;
  if (_list) {
    _currentNode = (_index > 0) ? _list->HEAD : NULL;
    if (_currentNode) {
      while ((_whileIndex < _index) && (_currentNode != NULL)) {
        _currentNode = _currentNode->nextNode;
        _whileIndex++;
      }
      _currentNode->value = _value;
    }
  }

  return (_currentNode != NULL);
}

bool nodeListDelete(list_t *_list, const size_t _index) {
  size_t _whileIndex = 1;
  node_t *_prevNode = NULL;
  node_t *_currNode = NULL;

  if (_list) {
    _currNode = (_index > 0) ? _list->HEAD : NULL;

    while ((_whileIndex < _index) && (_currNode != NULL)) {
      _prevNode = _currNode;
      _currNode = _currNode->nextNode;
      _whileIndex++;
    }

    if (_currNode) {
      if (!_prevNode) {
        _list->HEAD = _currNode->nextNode;
      } else {
        _prevNode->nextNode = _currNode->nextNode;
      }
      _list->COUNT--;
      free(_currNode);
    }
  }

  return (_currNode != NULL);
}

size_t nodeListSearchValue(list_t *_list, const int _value) {
  size_t _index = 0, _queryIndex = 0;

  if (_list) {
    node_t *_currNode = _list->HEAD;

    while (_currNode) {
      _index++;
      if (_currNode->value == _value) {
        _queryIndex = _index;
        break;
      } else {
        _currNode = _currNode->nextNode;
      }
    }
  }

  return _queryIndex;
}

bool nodeListSearchNode(list_t *_list, int *_interger, const size_t _index) {
  node_t *_currNode = NULL;

  if (_interger != NULL && _list != NULL) {
    size_t _whileIndex = 1;
    node_t *_currNode = (_index > 0) ? _list->HEAD : NULL;

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

size_t nodeListGetCount(list_t *_list) { return _list->COUNT; }

void nodeListFreeAll(list_t **_list) {
  if (*_list != NULL) {
    while ((*_list)->HEAD) {
      node_t *_nextNode = (*_list)->HEAD->nextNode;
      free((*_list)->HEAD);
      (*_list)->HEAD = NULL;
      (*_list)->HEAD = _nextNode;
    }
    (*_list)->COUNT = 0;
    free(*_list);
    *_list = NULL;
  }
}