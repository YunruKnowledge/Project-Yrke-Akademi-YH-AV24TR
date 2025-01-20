
#include <cassert>
#include <iostream>

class Shape {
private:
  double area;
  std::string name;

public:
  Shape(std::string _name = "") : name{_name} {};
  void printArea(void) const {
    std::cout << "Ze area of " << name << " is: " << this->getArea() << std::endl;
  }
  std::string getName(void) const { return name; }
  virtual double getArea(void) const = 0;
};

class Point {
  int x, y;

public:
  Point(int _x, int _y) : x{_x}, y{_y} {};
};

class Circle : public Shape {
  double radius;
  Point origin;
  static constexpr double PI{3.1415};

public:
  Circle(int _x, int _y, const double _radius, std::string _name = "")
      : radius{_radius}, origin{_x, _y},
        Shape{("Circle " + _name)} {};

  double getArea(void) const override { return (radius * radius * PI); }

  friend bool operator==(const Circle &_a, const Circle &_b) {
    return (_a.radius == _b.radius);
  }
};

class Square : public Shape {
  double length;

public:
  Square(const double _side_length, std::string _name = "")
      : length{_side_length}, Shape{("Square " + _name)} {};

  double getArea(void) const override { return length * length; }
};

int main(void) {
  std::cout << "Assert Test Starting..." << std::endl;

  Circle circle1{0, 0, 2, "A"};
  circle1.printArea();
  Circle circle2{0, 0, 4, "B"};
  circle2.printArea();
  Circle circle3{0, 0, 2, "C"};
  circle3.printArea();

  assert(circle3 == circle1);
  std::cout << circle1.getName() << ((circle3 == circle1) ? " is" : " is not")
            << " the same." << std::endl;

  Square Square{20, "D"};
  Square.printArea();
  assert(400 == Square.getArea());

  std::cout << "Assert Test Finished" << std::endl;

  return 0;
}