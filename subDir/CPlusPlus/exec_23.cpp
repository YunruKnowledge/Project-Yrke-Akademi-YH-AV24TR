
#include <cassert>
#include <iostream>

static constexpr double PI{3.1415};

class Shape {
private:
  std::string name;
  double area;

protected:
  void setName(std::string _string) { name = _string; }
  void setArea(const double _value) { area = _value; }

public:
  void printArea(void) const {
    std::cout << "Ze area of " << name << "is: " << area << std::endl;
  }
};

class Point {
  double x, y;

public:
  Point(double _x, double _y) : x{_x}, y{_y} {};
};

class Circle : public Shape {
  double radius;
  Point origin;

  void setShape(void) {
    double area{radius * radius * PI};
    std::string name{"Circle Shape"};

    Shape::setArea(area);
    Shape::setName(name);
  }

public:
  Circle(const double _radius) : radius{_radius}, origin{radius, radius} {
    setShape();
  };

  double getArea(void) const { return (radius * radius * PI); }

  friend bool operator==(const Circle &_a, const Circle &_b) {
    return (_a.radius == _b.radius);
  }
};

class Square : public Shape {
  double length;
  Point origin;

public:
  Square(const double _side_length)
      : length{_side_length}, origin{length / 2, length / 2} {
    std::string name{"Square Shape"};
    Shape::setArea(length * 2);
    Shape::setName(name);
  };

  double getArea(void) { return length * 2; }
};

int main(void) {
  std::cout << "Assert Test Starting..." << std::endl;

  Circle circle1{2};
  circle1.printArea();
  Circle circle2{4};
  circle2.printArea();
  Circle circle3{2};
  circle3.printArea();
  assert(circle3 == circle1);

  Square Square{20};
  Square.printArea();
  assert(40 == Square.getArea());

  std::cout << "Assert Test Finished" << std::endl;

  return 0;
}