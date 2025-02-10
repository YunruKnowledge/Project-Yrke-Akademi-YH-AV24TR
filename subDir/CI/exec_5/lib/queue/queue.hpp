

#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include <new>

template <typename T> class Queue {
  class Node {
  public:
    T value;
    Node *next;
    Node(T _value, Node *_next) : value{_value}, next{_next} {};
  };

  Node *head{nullptr};
  Node *tail{nullptr};
  size_t count{0};

public:
  Queue() = default;
  Queue(const Queue &) = delete;
  Queue &operator=(const Queue &) = delete;
  ~Queue() { clear(); }

  Queue(Queue &&_inst) noexcept
      : head{_inst.head}, tail{_inst.tail}, count{_inst.count} {
    _inst.count = 0;
    _inst.head = nullptr;
    _inst.tail = nullptr;
  };
  Queue &operator=(Queue &&_inst) {

    if (this != &_inst) {
      head = _inst.head;
      tail = _inst.tail;
      count = _inst.count;

      _inst.count = 0;
      _inst.head = nullptr;
      _inst.tail = nullptr;
    };

    return *this;
  };

public:
  bool enqueue(const T &_value) {
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

  bool dequeue(T &_var) {
    bool status{false};
    if (head != nullptr) {
      status = true;
      _var = head->value;

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
};

#endif