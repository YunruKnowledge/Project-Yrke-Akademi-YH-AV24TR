/**
 * @file exec_19.cpp
 * @author SkyThe (88000687+YunruKnowledge@users.noreply.github.com)
 * @brief File containing solution to exercise 19,
 *        all in one for VSC CompileRun extension.
 *        "Develop and test a multiple-instance linked list module to strore and
 *        restore data of type int [...]".
 * @version 1
 * @date 2025-01-02
 *
 * @copyright Copyright (c) 2025
 *
 */
// HEADER START
#ifndef EXEC_19
#define EXEC_19

struct list_t;

namespace list {
list_t *create(void);
bool insert(list_t *_list, int _value);
int available(list_t *_list);
bool search(list_t *_list, const int _value);
bool remove(list_t *_list, const int _value);
bool edit(list_t *_list, const int _query, const int _value);
void destroy(list_t *&_list);
} // namespace list

#endif
// HEADER END
//

// SOURCE START
#include <new>

struct node_t {
  int value;
  node_t *next;
};

struct list_t {
  node_t *head;
  int amount;
};

list_t *list::create(void) { return new (std::nothrow) list_t{nullptr, 0}; }

bool list::insert(list_t *_list, int _value) {
  bool _status{false};
  if (_list != nullptr) {
    node_t *_prevNode{nullptr};
    node_t *_currNode{_list->head};

    while (_currNode != nullptr) {
      if (_currNode->value >= _value) {
        break;
      }
      _prevNode = _currNode;
      _currNode = _currNode->next;
    }

    if (_currNode == nullptr || _currNode->value != _value) {
      node_t *_node{new (std::nothrow) node_t{_value, nullptr}};

      if (_node != nullptr) {
        _node->value = _value;
        _node->next = nullptr;

        if (_currNode == nullptr && _prevNode == nullptr) {
          _list->head = _node;
        } else if (_currNode != nullptr && _prevNode == nullptr) {
          _list->head = _node;
          _node->next = _currNode;
        } else if (_currNode == nullptr && _prevNode != nullptr) {
          _prevNode->next = _node;
        } else {
          _node->next = _currNode;
          _prevNode->next = _node;
        }

        _list->amount++;
        _status = true;
      }
    }
  }
  return _status;
}

int list::available(list_t *_list) {
  return _list != nullptr ? _list->amount : -1;
}

bool list::search(list_t *_list, const int _value) {
  bool _status{false};
  if (_list != nullptr) {
    node_t *_temp{_list->head};

    while (_temp != nullptr) {
      if (_temp->value == _value) {
        _status = true;
        break;
      }

      _temp = _temp->next;
    }
  }
  return _status;
}

bool list::remove(list_t *_list, const int _value) {
  bool _status{false};
  if (_list != nullptr) {
    node_t *_prevNode{nullptr};
    node_t *_currNode{_list->head};

    while (_currNode != nullptr) {
      if (_currNode->value == _value) {
        if (_prevNode != nullptr) {
          _prevNode->next = _currNode->next;
        } else {
          _list->head = _currNode->next;
        }

        _status = true;
        delete _currNode;
        _list->amount--;
        break;
      } else {
        _prevNode = _currNode;
        _currNode = _currNode->next;
      }
    }
  }
  return _status;
}

bool list::edit(list_t *_list, const int _query, const int _value) {
  bool _status{false};
  if (_list != nullptr) {
    if (search(_list, _query)) {
      if (remove(_list, _query)) {
        _status = insert(_list, _value);
      }
    }
  }
  return _status;
}

void list::destroy(list_t *&_list) {
  if (_list != nullptr) {
    node_t *_node{_list->head};

    while (_node != nullptr) {
      _list->head = _node->next;
      delete _node;
      _node = _list->head;
    }

    delete _list;
    _list = nullptr;
  }
}
// SOURCE END
//

// TEST START
#include <cassert>
#include <iostream>

int main(void) {
  std::cout << "balls " << std::endl;

  list_t *test = list::create();
  assert(test != nullptr);
  assert(0 == list::available(test));
  assert(!list::remove(test, 0));

  assert(list::insert(test, 30));
  assert(1 == list::available(test));

  assert(!list::insert(test, 30));
  assert(1 == list::available(test));

  assert(list::insert(test, 20));
  assert(2 == list::available(test));
  assert(!list::insert(test, 20));

  assert(list::insert(test, 10));
  assert(3 == list::available(test));

  assert(list::search(test, 10));
  assert(list::search(test, 20));
  assert(list::search(test, 30));
  assert(!list::search(test, 15));

  assert(list::edit(test, 20, 15));
  assert(!list::search(test, 20));
  assert(list::search(test, 15));

  assert(list::remove(test, 10));
  assert(2 == list::available(test));

  assert(list::remove(test, 15));
  assert(1 == list::available(test));

  list::destroy(test);
  assert(test == nullptr);

  std::cout << "All the tests passed!" << std::endl;

  return 0;
}
// TEST END
//