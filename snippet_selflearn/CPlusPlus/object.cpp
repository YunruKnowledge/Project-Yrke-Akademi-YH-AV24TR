#include <iostream>

// HEADER
class rect {
  int width;
  int height;

public:
  rect() : rect(10, 5) {};
  explicit rect(int _width, int _height) : width{_width}, height{_height} {};

  int getWidth(void) const { return width; };
  int getHeight(void) const { return height; };
  int getArea(void) const { return width * height; };

  // Operator
  bool operator==(const rect _b) const {
    return (width == _b.getWidth() && height == _b.getHeight());
  };

  // Friend func *not a member function
  friend rect operator+(rect _a, rect _b) {
    return rect(_a.getWidth() + _b.getWidth(), _a.getHeight() + _b.getHeight());
  };

  ~rect() = default;
};

class singleton {
  int x, y;
  singleton(int _a, int _b) : x{_a}, y{_b} {};

public:
  static singleton *handle(int _x, int _y) {
    static singleton temp(_x, _y);
    return &temp;
  }

  void print(void) { std::cout << "x: " << x << ", y: " << y << std::endl; };
};

class Product {
  int id;
  static int serial;

public:
  Product() : id{++serial} {};
  int getID(void) { return id; };
};

class Resource {
  int *ptr;
  int amount;

public:
  Resource(int _value) : ptr{new(std::nothrow) int{_value}} {};
  int getSus(void) { return static_cast<int>(*ptr); }
  ~Resource() { delete ptr; };
};

// HEADER END
//

int Product::serial{0};

void printRect(rect *_rect);

int main() {
  rect rect1{25, 5};
  printRect(&rect1);

  const rect rect2;
  printRect(const_cast<rect *>(&rect2));

  rect rect3{rect1}; // Copy constructor
  printRect(&rect3);

  // Local static *static public
  singleton *single = singleton::handle(50, 20);
  singleton *single2 = singleton::handle(502, 20);
  single->print();
  single2->print();

  // Global static *static private
  Product soap;
  Product fomp;
  std::cout << soap.getID() << fomp.getID() << std::endl;

  // FRIEND!! *operator
  rect rect4 = rect1 + rect2;
  printRect(&rect4);

  // Dynamic init
  Resource sus{22};
  std::cout << "sus: " << sus.getSus() << std::endl;

  return 0;
}

void printRect(rect *_rect) {
  std::cout << "Width: " << _rect->getWidth()
            << " | Height: " << _rect->getHeight()
            << " | Area: " << _rect->getArea() << std::endl;
}