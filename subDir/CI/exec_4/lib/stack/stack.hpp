
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
  
  ~Stack() { clear(); }

public:
  /**
   * @brief Edit a nodes value based on its index, starts with 1.
   *
   * @param _index node order, from largest valued node.
   * @param _value new value.
   * @return `true` upon success.
   */
  bool edit(const size_t _index, const int _value);

  /**
   * @brief Deletes a node based on value.
   *
   * @param _value value to search for.
   * @return `true` upon success.
   */
  bool remove(const int _value);

  /**
   * @brief Searches for a node index based on a value.
   *
   * @param _value 
   * @return ´0´ upon failure, otherwise 1 n above.
   */
  size_t search(const int _value);

  /**
   * @brief Adds a value into list.
   * 
   * @param _value the value to add.
   * @return `true` upon success.
   */
  bool push(int _value);

  /**
   * @brief Gets the largest value in list.
   * 
   * @param _var reference to apply found value to.
   * @return `true` upon success. (found)
  */
  bool pop(int &_var);

  /**
   * @brief Returns amount of nodes in list.
   * 
   * @return size_t 
   */
  size_t amount(void) { return count; }

  /**
   * @brief Clears/deletes all nodes from the list.
   * 
   */
  void clear(void) {
    while (head != nullptr) {
      Node *temp{head};
      head = head->next;
      delete temp;
    }
    count = 0;
  }
};

bool Stack::edit(const size_t _index, const int _value) {
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
          } else if (_value == temp->next->value) { // if value already exists.
            delete cursor;
            count--;
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

bool Stack::remove(const int _value) {
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

size_t Stack::search(const int _value) {
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

bool Stack::push(int _value) {
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

bool Stack::pop(int &_var) {
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

#endif