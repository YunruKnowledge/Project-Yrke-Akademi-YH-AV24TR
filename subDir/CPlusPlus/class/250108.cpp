#include <iostream>

//
//
// CHAPTER: Objects / Class
class Point {
  class position {
  public:
    int x, y;
  };

  position origin;

public:
  constexpr Point() : origin{0, 0} {};
  constexpr Point(int _x, int _y) : origin{_x, _y} {};

  void print(void) const {
    std::cout << "[" << origin.x << ", " << origin.y << "]" << std::endl;
  };

  ~Point() {
    std::cout << "LINE:" << __LINE__ << "|" << __TIME__ << "|Descontructed"
              << std::endl;
  }
};

//
//
// CHAPTER: Singleton & FRIEND
class singletonV2 {
  int _value;
  singletonV2() { singletonV2(0); };
  singletonV2(int _val) : _value{_val} {};

public:
  static singletonV2 &instance(int _val) {
    static singletonV2 singleton_var{_val};
    return singleton_var;
  }
  void setValue(int _val) { _value = _val; };
  void print(void) { std::cout << _value << std::endl; };

  friend std::ostream &operator<<(std::ostream &_os,
                                  const singletonV2 &_instance) {
    _os << _instance._value;
    return _os;
  };
};

//
//
// CHAPTER: Inheritance
class MainClass {
  int a;

protected:
  void protectedPrint(void) {
    std::cout << "Main>>This is a protected print." << std::endl;
  };

public:
  MainClass(int _a) : a{_a} { std::cout << "Main>>con-structor" << std::endl; };
  void print() { std::cout << "Main>>" << a << std::endl; };
  ~MainClass() { std::cout << "Main>>de-structor" << std::endl; };
};

// inherits public data.
class SubClassPublic : public MainClass {
  int b;

public:
  SubClassPublic(int _a, int _b) : MainClass{_a}, b{_b} {
    std::cout << "SubPublic>>con-structor" << std::endl;
  };
  void print() {
    MainClass::print();
    std::cout << "SubPublic>>" << b << std::endl;
  };
  ~SubClassPublic() { std::cout << "SubPublic>>de-structor" << std::endl; };
};

// inherits public and protected data, converts all to protected.
class SubClassProtected : protected MainClass {
  int c;

public:
  SubClassProtected() : MainClass{5}, c{33} {
    std::cout << "SubProtect>>con-structor" << std::endl;
  };
  void print() {
    MainClass::print();
    std::cout << "SubProtect>>" << c << std::endl;
  };
  void printProtected() { protectedPrint(); }
  ~SubClassProtected() { std::cout << "SubProtect>>de-structor" << std::endl; };
};

// inherits protected & public, are now private here.
class SubClassPrivate : private MainClass {
  int d;

public:
  SubClassPrivate() : MainClass{50}, d{44} {
    std::cout << "SubPrivate>>con-structor" << std::endl;
  };
  void print() {
    MainClass::print();
    std::cout << "SubPrivate>>" << d << std::endl;
  };
  void printProtectedNowPrivate() { protectedPrint(); }
  ~SubClassPrivate() { std::cout << "SubPrivate>>de-structor" << std::endl; };
};

// Inherits from SubClassProtected, and *named* -meaning no more inherits from
// this one onwards.
class subDoubleInherit final : protected SubClassProtected {

  int e;

public:
  subDoubleInherit() : SubClassProtected{}, e{66} {
    std::cout << "subDoubleProtect>>con-structor" << std::endl;
  };
  void print() {
    MainClass::print();
    SubClassProtected::print();
    SubClassProtected::printProtected();
    std::cout << "subDoubleProtect>>" << e << std::endl;
  };
  ~subDoubleInherit() {
    std::cout << "subDoubleProtect>>de-structor" << std::endl;
  };
};

//
//
// MAIN
int main(void) {

  std::cout << std::endl << "CHAPTER: Objects / Class" << std::endl;
  {
    Point Baller;
    Point Alex{2, 5};
    Baller.print();
    Alex.print();
  }
  std::cout << std::endl << "CHAPTER: Singleton & FRIEND" << std::endl;
  {
    singletonV2 &first{singletonV2::instance(2)};
    singletonV2 &second{singletonV2::instance(4444)};
    second.setValue(47);
    second.print();
    first.setValue(28);
    std::cout << first << std::endl;
  }
  std::cout << std::endl << "CHAPTER: Inheritance" << std::endl;
  {
    {
      std::cout << "*---SCOPE-RESET---* MAIN v" << std::endl;
      MainClass mainClass{11};
      mainClass.print();
    }
    {
      std::cout << "*---SCOPE-RESET---* PUBLIC v" << std::endl;
      SubClassPublic subPublic{22, 27};
      subPublic.print();
    }
    {
      std::cout << "*---SCOPE-RESET---* PROTECTED v" << std::endl;
      SubClassProtected subProtect;
      subProtect.print();
      subProtect.printProtected();
    }
    {
      std::cout << "*---SCOPE-RESET---* PRIVATE v" << std::endl;
      SubClassPrivate subPrivate;
      subPrivate.print();
      subPrivate.printProtectedNowPrivate();
    }
    {
      std::cout << "*---SCOPE-RESET---* PUBLIC CASTED v" << std::endl;
      SubClassPublic subPublic{55, 27};
      MainClass &upCasted{subPublic};
      upCasted.print();
    }
    {
      std::cout << "*---SCOPE-RESET---* DOUBLE PROTECT v" << std::endl;
      subDoubleInherit subDouble;
      subDouble.print();
    }
  }

  return 0;
}