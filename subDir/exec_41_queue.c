#include "exec_41_queue.h"

typedef struct NODE {
  int value;
  struct NODE *nextNode;
} node_t;

typedef struct QUEUE {
  node_t *HEAD;
  node_t *TAIL;
  size_t count;
} queue_t;

queue_t *queueCreate(void) {
  queue_t *_queue = (queue_t *)malloc(sizeof(queue_t));

  if (_queue) {
    _queue->HEAD = NULL;
    _queue->TAIL = NULL;
    _queue->count = 0;
  }

  return _queue;
}

bool queueAdd(queue_t *_queue, const int _value) {
  node_t *_node = NULL;
  if (_queue != NULL) {
    _node = (node_t *)malloc(sizeof(node_t));

    if (_node) {
      _node->nextNode = NULL;
      _node->value = _value;
      _queue->count++;

      if (_queue->HEAD) {
        _queue->TAIL->nextNode = _node;
        _queue->TAIL = _node;
      } else {
        _queue->HEAD = _node;
        _queue->TAIL = _queue->HEAD;
      }
    }
  }

  return (_node != NULL) ? true : false;
}

bool queueRead(queue_t *_queue, int *_int_ptr) {
  bool _success = false;
  if (_queue != NULL && _int_ptr != NULL) {
    if (_queue->HEAD) {
      *_int_ptr = _queue->HEAD->value;
      node_t *_head = _queue->HEAD;
      _queue->HEAD = _queue->HEAD->nextNode;
      free(_head);

      if (_queue->HEAD == NULL) {
        _queue->TAIL = NULL;
      }
      _success = true;
      _queue->count--;
    }
  }

  return _success;
}

size_t queueCount(queue_t *_queue) { return _queue->count; }

void queueFree(queue_t **_queue) {
  if ((_queue != NULL) & (*_queue != NULL)) {
    node_t *_head = (*_queue)->HEAD;
    while (_head) {
      node_t *_node = _head;
      _head = _head->nextNode;
      free(_node);
    }

    free(*_queue);
    *_queue = NULL;
  }
}