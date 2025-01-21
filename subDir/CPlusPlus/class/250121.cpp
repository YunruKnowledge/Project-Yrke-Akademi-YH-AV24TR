#include <exception>
#include <iostream>

//
//
// Chapter 1: Unused returns
// GCC
__attribute__((warn_unused_result)) int example1(void) {
  std::cout << "Example 1." << std::endl;
  return 1;
}

// C++
[[nodiscard]] int example2(void) {
  std::cout << "Example 2." << std::endl;
  return 2;
}

//
//
// Chapter 2: Try & Catch
class TempA {
  int temp;

public:
  TempA(int _val) : temp{_val} {
    std::cout << "Example Class A." << std::endl;
    try {
      throw 3.25;
    } catch (...) {
      throw;
    }
  }
  ~TempA() { std::cout << "Example Class A destructor called." << std::endl; }
};

class TempB : public TempA {
public:
  TempB(int _val) try : TempA{_val} {
    std::cout << "Example Class B." << std::endl;
  } catch (...) {
    std::cout << "Example Class B catch." << std::endl;
    std::cout << "Exception automatically kept throwin'." << std::endl;
  }
  ~TempB() { std::cout << "Example Class B destructor called." << std::endl; }
};

void example3(void) {
  std::cout << "Example 3." << std::endl;
  TempB temp{4};
}

void example4(void) {
  std::cout << "Example 4." << std::endl;
  try {
    example3();
  } catch (int _code) {
    std::cout << "balls-" << _code << std::endl;
  } catch (...) {
    throw;
  };
}

void example5(void) noexcept { throw "FATAL ERROR BRO."; }

// to disable exceptions
// -fno-exceptions

//
//
// Chapter 3: Smart pointer
template <typename T> class AutoPtr {
  T *ptr;

public:
  AutoPtr(T *_ptr = nullptr) : ptr{_ptr} {
    std::cout << "AutoPtr Constructor called." << std::endl;
  };

  AutoPtr(const AutoPtr &_src) : ptr{new T{*_src.ptr}} {
    std::cout << "AutoPtr Copy constructor called." << std::endl;
  };

  T &operator=(AutoPtr &_src) {
    if (this != &_src) {
      delete ptr;
      ptr = new T{*_src.ptr};
    }
    std::cout << "AutoPtr Copy operator= called." << std::endl;
    return *this;
  };

  T &operator*() const { return *ptr; };
  T &operator->() const { return ptr; };
  ~AutoPtr() {
    delete ptr;
    std::cout << "AutoPtr destructor called." << std::endl;
  };
};

AutoPtr<int> makeAutoPtr(void) { return AutoPtr<int>{new int{44}}; }

//
//
// Chapter 4: Move semantics

// template <typename T> class AutoMovePtr {
//   T *ptr;

// public:
//   AutoMovePtr(const AutoMovePtr &_src) = delete;
//   T &operator=(AutoMovePtr &_src) = delete;

//   AutoMovePtr(T *_ptr = nullptr) : ptr{_ptr} {};

//   AutoMovePtr(const AutoMovePtr &&_src) noexcept : ptr{_src.ptr} {};

//   T &operator=(AutoMovePtr &&_src) noexcept {
//     if (this != &_src) {
//       delete ptr;
//       ptr = _src.ptr;
//       _src.ptr = nullptr;
//     }
//     return *this;
//   };

//   T &operator*() const { return *ptr; };
//   T &operator->() const { return ptr; };
//   ~AutoMovePtr() {
//     delete ptr;
//     std::cout << "AutoMovePtr destructor called." << std::endl;
//   };
// };

// AutoMovePtr<int> makeAutoMovePtr(void) { return AutoMovePtr<int>{new
// int{44}}; }

template <typename T> void Swap(T &_a, T &_b) {
  T temp{std::move(_a)};
  _a = std::move(_b);
  _b = std::move(temp);
}

//
//
// Main
int main(void) {
  std::cout << "Main start." << std::endl;

  // Chapter 1: Unused returns (Warns, if returns are unsused.)
  int var{example1()};
  std::cout << var << std::endl;
  (void)example2();

  // Chapter 2: Try & Catch (Try, if something throws en error, catch.)
  try {
    example4();
  } catch (int _code) {
    std::cout << "ints-" << _code << std::endl;
  } catch (double _code) {
    std::cout << "doubles-" << _code << std::endl;
  } catch (...) {
    std::cout << "others-" << std::endl;
  }

  try {
    // example5(); <--- throws
  } catch (...) {
    std::cout << "baba" << std::endl;
  }

  // Chapter 3: Smart pointer (Deletes itself even if there was a throw)
  try {
    AutoPtr<int> a{new int{22}}, b{a};
    AutoPtr<int> c = b;
    AutoPtr<int> d{makeAutoPtr()};
    std::cout << "SmrtPtr->" << *a << *b << *c << " " << *d << std::endl;
    throw false;
  } catch (bool) {
    ;
  }

  // Chapter 4: Move semantics (no copies, move values directly)
  std::string string = "Bruh";
  std::string stringTemp = std::move(string);
  std::cout << "String: " << string << " | Temp: " << stringTemp << std::endl;

  int lValue{10};
  int &&rValue{std::move(lValue)};
  std::cout << "l-value: " << lValue << " | r-value: " << rValue << std::endl;

  {
    int a{2}, b{7};
    Swap(a, b);
    std::cout << "a-value: " << a << " | b-value: " << b << std::endl;
  }

  // try {
  //   AutoMovePtr<int> a{new int{22}}, b{static_cast<AutoMovePtr<int> &&>(a)};
  //   AutoMovePtr<int> c = makeAutoMovePtr();
  //   AutoMovePtr<int> d{makeAutoMovePtr()};
  //   std::cout << "SmrterPtr->" << *a << *b << *c << " " << *d << std::endl;
  //   throw false;
  // } catch (bool) {
  //   ;
  // }

  std::cout << "Main end." << std::endl;
  return 0;
}
