
// HEADER
#ifndef EXEC_24
#define EXEC_24
#include <cstddef>
#include <new>

class Stack {
  class Node {
  public:
    int value;
    Node *next;
    Node(int _value, Node *_next) : value{_value}, next{_next} {};
  };

  Node *head{nullptr};
  size_t count{0};

public:
  Stack() = default;
  Stack(const Stack &) = delete;
  Stack &operator=(const Stack &) = delete;

  Stack(Stack &&_instance) noexcept
      : head{_instance.head}, count{_instance.count} {
    _instance.head = nullptr;
    _instance.count = 0;
  };

  // NOTE: SOME BUG WHEN USING POP IN A FOR LOOP BEFORE operator=
  //       count did not decrement
  Stack &operator=(Stack &&_instance) noexcept {
    if (this != &_instance) {
      head = _instance.head;
      count = _instance.count;

      _instance.head = nullptr;
      _instance.count = 0;
    };

    return *this;
  }

public:
  bool edit(const size_t _index, const int _value) {
    bool status{false};
    Node *cursor{head}, *previous{nullptr};
    size_t index{0};

    // find & edit value + unlink from list.
    if (cursor != nullptr && _index != 0) {
      index++;
      if (_index == index) {
        head = cursor->next;
        cursor->value = _value;
        status = true;
      } else {
        while (cursor->next != nullptr && index < _index) {
          previous = cursor;
          cursor = cursor->next;
          index++;
        }
        if (index == _index) {
          previous->next = cursor->next;
          cursor->value = _value;
          status = true;
        }
      }
    }

    // sort, link back to list
    if (status && index > 1) {
      Node *temp{head};
      status = false;

      if (temp != nullptr) {
        if (_value > temp->value) { // if value is largest
          head = cursor;
          cursor->next = temp;
          status = true;
        } else {
          while (temp->next != nullptr) { // while next node has smaller value
            if (_value > temp->next->value) {
              cursor->next = temp->next;
              temp->next = cursor;
              status = true;
              break;
            } else {
              temp = temp->next;
            }
          }
          if (status == false) { // if all fails, value is smallest
            temp->next = cursor;
            status = true;
          }
        }
      }
    }

    return status;
  };

  bool remove(const int _value) {
    bool status{false};

    Node *temp{head};
    if (temp != nullptr) {         // if has Nodes
      if (temp->value == _value) { // if head is value
        head = temp->next;
        delete temp;
        count--;
        status = true;
      } else if (temp->next != nullptr) { // if has other Nodes
        while (temp->next != nullptr) {
          if (temp->next->value == _value) { // if next node is value
            Node *temp_delete{temp->next};
            temp->next = temp->next->next;
            delete temp_delete;
            count--;
            status = true;
            break;
          } else {
            temp = temp->next;
          }
        }
      }
    }

    return status;
  }; // remove node based on val

  size_t search(const int _value) {
    size_t index{0};
    bool isFound{false};
    Node *temp{head};

    while (temp != nullptr) {
      index++;
      if (temp->value == _value) {
        isFound = true;
        break;
      }
      temp = temp->next;
    }

    return isFound ? index : 0;
  };

  bool push(int _value) {
    bool status{false};

    if (search(_value) == 0) {
      Node *node = new (std::nothrow) Node{_value, head};

      if (node != nullptr) {                // if successfull creation
        if (node->next != nullptr) {        // if other nodes exist
          if (_value > node->next->value) { // if _value is largest
            head = node;
          } else { // else find and sorting itself.
            Node *temp{head};
            while (temp->next != nullptr) {
              if (_value < temp->next->value) {
                temp = temp->next;
              } else {
                node->next = temp->next;
                temp->next = node;
                break;
              }
            }
          }
        } else { // else is first node
          head = node;
        }
        count++;
        status = true;
      }
    }

    return status;
  }

  bool pop(int &_var) {
    bool status{false};

    if (head != nullptr) {
      status = true;
      _var = head->value;
      Node *temp{head};
      head = head->next;
      delete temp;
      count--;
    }

    return status;
  }

  size_t amount(void) { return count; }

  void clear(void) {
    while (head != nullptr) {
      Node *temp{head};
      head = head->next;
      delete temp;
    }
    count = 0;
  }
  
  ~Stack() { clear(); }
};

#endif