
// HEADER
#ifndef EXEC_24
#define EXEC_24
#include <iostream>

class List {
  class Node {
  public:
    int value;
    Node *next;
    Node(int _value, Node *_next) : value{_value}, next{_next} {};
  };

  Node *head{nullptr};
  size_t count{0};

public:
  List() = default;
  List(const List &) = delete;
  List &operator=(const List &) = delete;

  bool push(int _value) {
    bool status{false};
    Node *node = new (std::nothrow) Node{_value, head};

    if (node != nullptr) {
      head = node;
      count++;
      status = true;
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

  friend std::ostream &operator<<(std::ostream &_os, const List &_list) {
    Node *temp{_list.head};
    
    while (temp != nullptr) {
      _os << temp->value << " -> ";
      temp = temp->next;
    }
    _os << "nullptr";

    return _os;
  }

  ~List() { clear(); }
};

#endif
// HEADER END
//
//

#include <cassert>
#include <iostream>

int main(void) {
  std::cout << "Assert test starting..." << std::endl;

  List stack;
  assert(0 == stack.amount());
  assert(true == stack.push(11));
  assert(true == stack.push(22));
  assert(true == stack.push(33));
  assert(3 == stack.amount());

  std::cout << stack << std::endl;

  int mita{0};
  assert(true == stack.pop(mita));
  assert(33 == mita);
  assert(true == stack.pop(mita));
  assert(22 == mita);
  assert(1 == stack.amount());

  std::cout << stack << std::endl;

  stack.clear();
  assert(false == stack.pop(mita));
  assert(22 == mita);
  assert(0 == stack.amount());

  std::cout << stack << std::endl;

  std::cout << "Assert test finished." << std::endl;

  return 0;
}