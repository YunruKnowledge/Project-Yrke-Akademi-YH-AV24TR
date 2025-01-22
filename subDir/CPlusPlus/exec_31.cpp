
// HEADER
#ifndef EXEC_31
#define EXEC_31

#include <iostream>

template <typename T> class Stack {
  T *ptr;
  size_t size;
  size_t count{0};
  static constexpr size_t MIN_SIZE{3};

public:
  Stack(const Stack &) = delete;
  Stack &operator=(const Stack &) = delete;

  Stack(Stack &&_instance) noexcept
      : ptr{_instance.ptr}, size{_instance.size}, count{_instance.count} {
    _instance.ptr = nullptr;
    _instance.size = 0;
    _instance.count = 0;
  };

  Stack &operator=(Stack &&_instance) noexcept {
    if (this != &_instance) {
      delete ptr;

      ptr = _instance.ptr;
      size = _instance.size;
      count = _instance.count;

      _instance.ptr = nullptr;
      _instance.size = 0;
      _instance.count = 0;
    }

    return *this;
  }

  Stack(const size_t _size) : ptr{new T[_size]}, size{_size} {
    std::cout << "Constructor called!" << std::endl;
    if (_size <= MIN_SIZE) {
      try {
        throw std::range_error("Below min size.");
      } catch (...) {
        throw;
      }
    }
  };

  size_t getSize() { return size; };

  bool push(const T _value) {
    bool status{false};

    if (count >= size) {
      try {
        throw std::length_error("Cannot push, overflow.");
      } catch (...) {
        throw;
      }
    } else {
      ptr[count] = _value;
      count++;
      status = true;
    }

    return status;
  }

  bool pop(T &_var) {
    bool status{false};

    if (count == 0) {
      try {
        throw std::range_error("Stack empty.");
      } catch (...) {
        throw;
      }
    } else {
      count--;
      _var = ptr[count];
      status = true;
    }

    return status;
  }

  size_t getNumber(void) { return count; }

  void clear(void) {
    count = 0;
    std::cout << "Clear called!" << std::endl;
  }

  ~Stack() {
    std::cout << "Destructor called!" << std::endl;
    delete ptr;
  }
};

#endif
// HEADER END
//
//
#include <cassert>

void TestNo3(void);
void TestNo2(void);
void TestNo1(void);

int main(void) {
  TestNo1();
  TestNo2();
  TestNo3();

  return 0;
}

void TestNo1(void) {
  std::cout << std::endl << "Test No. 1 Start" << std::endl;
  try {
    std::cout << "Creating Mila..." << std::endl;
    Stack<double> mila{4};
    assert(4 == mila.getSize());
    std::cout << "Size: " << mila.getSize() << std::endl;
    std::cout << "Count: " << mila.getNumber() << std::endl;
    std::cout << "Pushing..." << std::endl;
    assert(true == mila.push(44.4));
    assert(true == mila.push(22.4));
    assert(true == mila.push(11.4));
    assert(true == mila.push(0.44));
    std::cout << "Count: " << mila.getNumber() << std::endl;
    assert(4 == mila.getNumber());

    try {
      assert(false == mila.push(66.66));
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      std::cout << "Push failed, but expected." << std::endl;
    }
    std::cout << "Count: " << mila.getNumber() << std::endl;
    assert(4 == mila.getNumber());

    std::cout << "Popping..." << std::endl;
    double var{0};

    assert(true == mila.pop(var));
    std::cout << var << std::endl;
    assert(true == mila.pop(var));
    std::cout << var << std::endl;
    assert(true == mila.pop(var));
    std::cout << var << std::endl;
    assert(true == mila.pop(var));
    std::cout << var << std::endl;
    std::cout << "Count: " << mila.getNumber() << std::endl;

    try {
      assert(false == mila.pop(var));
      std::cout << var << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      std::cout << "Popping failed, but expected." << std::endl;
    }

  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "Test No. 1 End" << std::endl;
}

void TestNo2(void) {
  std::cout << std::endl << "Test No. 2 Start" << std::endl;
  try {
    std::cout << "Creating Mila..." << std::endl;
    Stack<double> mila{4};
    assert(4 == mila.getSize());
    std::cout << "Size: " << mila.getSize() << std::endl;
    std::cout << "Count: " << mila.getNumber() << std::endl;
    std::cout << "Pushing..." << std::endl;
    assert(true == mila.push(44.4));
    assert(true == mila.push(22.4));
    assert(true == mila.push(11.4));
    assert(true == mila.push(0.44));
    std::cout << "Count: " << mila.getNumber() << std::endl;
    assert(4 == mila.getNumber());

    std::cout << "Creating Mita using Copy constructor..." << std::endl;
    Stack mita{std::move(mila)};

    double var{0};
    std::cout << "Popping... (Mila)" << std::endl;
    try {
      assert(false == mila.pop(var));
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      std::cout << "Popping failed, but expected." << std::endl;
    }

    std::cout << "Popping... (Mita)" << std::endl;
    std::cout << "Count: " << mita.getNumber() << std::endl;
    assert(4 == mita.getNumber());

    mita.pop(var);
    std::cout << var << std::endl;
    mita.pop(var);
    std::cout << var << std::endl;

    std::cout << "Count: " << mita.getNumber() << std::endl;
    assert(2 == mita.getNumber());

    std::cout << "Clearing... (Mita)" << std::endl;
    mita.clear();
    std::cout << "Count: " << mita.getNumber() << std::endl;
    std::cout << "Size: " << mita.getSize() << std::endl;
    assert(0 == mita.getNumber());
    assert(4 == mita.getSize());

  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "Test No. 2 End" << std::endl;
}

void TestNo3(void) {
  std::cout << std::endl << "Test No. 3 Start" << std::endl;

  try {
    std::cout << "Creating Mila..." << std::endl;
    Stack<double> mila{4};
    assert(4 == mila.getSize());
    std::cout << "Size: " << mila.getSize() << std::endl;
    std::cout << "Count: " << mila.getNumber() << std::endl;
    std::cout << "Pushing..." << std::endl;
    assert(true == mila.push(44.4));
    assert(true == mila.push(22.4));
    assert(true == mila.push(11.4));
    assert(true == mila.push(0.44));
    std::cout << "Count: " << mila.getNumber() << std::endl;
    assert(4 == mila.getNumber());

    std::cout << "Creating Mita 2 using Copy operator..." << std::endl;
    Stack mita2 = std::move(mila);
    std::cout << "Size: " << mita2.getSize() << std::endl;
    std::cout << "Count: " << mita2.getNumber() << std::endl;
    std::cout << "Pushing... (Mita 2)" << std::endl;
    try {
      assert(false == mita2.push(66.66));
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      std::cout << "Push failed, but expected." << std::endl;
    }

  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "Test No. 3 End" << std::endl;
}