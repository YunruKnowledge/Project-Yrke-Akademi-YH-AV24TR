
// HEADER
#ifndef EXEC_25
#define EXEC_25

#include <cstddef>
#include <new>

class Queue {
  class Node {
  public:
    int value;
    Node *next;
    Node(int _value, Node *_next) : value{_value}, next{_next} {};
  };

  Node *head{nullptr};
  Node *tail{nullptr};
  size_t count{0};

  Queue(const Queue &) = delete;
  Queue &operator=(const Queue &) = delete;

public:
  Queue() = default;

  bool enqueue(const int &_value) {
    bool status{false};

    Node *node = new (std::nothrow) Node{_value, nullptr};
    if (node != nullptr) {
      if (tail == nullptr) {
        head = node;
        tail = head;
      } else {
        tail->next = node;
        tail = node;
      }
      status = true;
      count++;
    }
    return status;
  }

  bool dequeue(int &_value) {
    bool status{false};
    if (head != nullptr) {
      status = true;
      _value = head->value;

      Node *temp{head};
      head = head->next;
      delete temp;
      count--;

      if (head == nullptr) {
        tail = nullptr;
      }
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
    tail = head;
  }

  ~Queue() { clear(); }
};

#endif
// HEADER END
//
//

#include <cassert>
#include <iostream>

int main(void) {

  std::cout << "Assert test start." << std::endl;
  Queue queue;

  assert(true == queue.enqueue(11));
  assert(true == queue.enqueue(22));
  assert(true == queue.enqueue(33));
  assert(true == queue.enqueue(44));
  assert(4 == queue.amount());

  int mila{0};
  assert(true == queue.dequeue(mila));
  assert(11 == mila);
  assert(true == queue.dequeue(mila));
  assert(22 == mila);
  assert(2 == queue.amount());

  queue.clear();
  assert(0 == queue.amount());
  assert(false == queue.dequeue(mila));

  std::cout << "Assert test finished." << std::endl;

  return 0;
}