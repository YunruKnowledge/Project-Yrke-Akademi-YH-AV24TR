

#include "TCircularBuffer.hpp"
#include <cassert>
#include <iostream>

int main(void) {
  std::cout << "Assert test start." << std::endl;

  // Testing creation and size.
  std::cout << std::endl << "Creating buffer... (with size of 2)" << std::endl;
  try {
    Buffer<double, 2> circle;
  } catch (const std::exception &e) {
    std::cout << "Exception thrown." << std::endl;
    std::cerr << e.what() << '\n';
  }
  std::cout << "Creating buffer... (with size of 4)" << std::endl;
  Buffer<double, 4> circle;

  // Testing writing data, and overflowing of data.
  std::cout << std::endl << "Writing data..." << std::endl;
  assert(true == circle.write(11.4));
  assert(true == circle.write(22.4));
  assert(true == circle.write(33.4));
  assert(true == circle.write(44.4));
  std::cout << "Current count: " << circle.getCount() << std::endl;
  std::cout << "Current state of Buffer: " << circle << std::endl;
  assert(true == circle.isFull()); // <-- Forgot to add this assert when handled it in. But it is working. 

  std::cout << "Overflowing data..." << std::endl;
  assert(false == circle.write(55.4));
  assert(4 == circle.getCount());
  std::cout << "Current count: " << circle.getCount() << std::endl;
  std::cout << "Current state of Buffer: " << circle << std::endl;

  // Testing reading the data from the buffer.
  std::cout << std::endl << "Reading data..." << std::endl;
  double var{0};

  assert(true == circle.read(var));
  assert(22.4 == var);
  std::cout << var << " >> ";
  assert(true == circle.read(var));
  assert(33.4 == var);
  assert(2 == circle.getCount());
  std::cout << var << " >> ";

  assert(true == circle.read(var));
  assert(44.4 == var);
  std::cout << var << " >> ";
  assert(true == circle.read(var));
  assert(55.4 == var);
  assert(0 == circle.getCount());
  std::cout << var << std::endl;

  std::cout << "Reading empty Buffer..." << std::endl;
  assert(false == circle.read(var));
  assert(55.4 == var);
  assert(0 == circle.getCount());
  std::cout << "Unchanged value: " << var << std::endl;

  // Testing clear().
  std::cout << std::endl << "Preparing for clearing test..." << std::endl;
  std::cout << "Writing data..." << std::endl;
  assert(true == circle.write(111.4));
  assert(true == circle.write(222.4));
  assert(true == circle.write(3.1415));
  assert(true == circle.write(444.4));
  assert(4 == circle.getCount());
  std::cout << "Current count: " << circle.getCount() << std::endl;
  std::cout << "Current state of Buffer: " << circle << std::endl;

  std::cout << "Clearing..." << std::endl;
  circle.clear();
  assert(0 == circle.getCount());
  assert(false == circle.read(var));
  assert(55.4 == var);
  std::cout << "Current state of Buffer: " << circle << std::endl;

  // Testing for different types of instances.
  std::cout << std::endl
            << "Preparing for multi instances test..." << std::endl;
  std::cout << "Creating buffers..." << std::endl;
  Buffer<std::string, 6> square;
  Buffer<int, 12> triangle;

  std::cout << std::endl << "Writing data..." << std::endl;
  assert(true == circle.write(0.10));
  assert(true == square.write("One Thousand"));
  assert(true == square.write("Two Hundred Thousand"));
  assert(true == triangle.write(10));
  assert(true == triangle.write(25));
  std::cout << "Current state of Circle: " << circle << std::endl;
  std::cout << "Current state of Square: " << square << std::endl;
  std::cout << "Current state of Triangle: " << triangle << std::endl;

  // Testing avarage function.
  std::cout << std::endl << "Using special Avarage function..." << std::endl;
  double temp{circle.getAvarage<double>()};
  assert(0.1 == temp);
  temp = triangle.getAvarage<double>();
  assert(17.5 == temp);
  std::cout << "Circle Avarage: " << circle.getAvarage<double>() << std::endl;
  std::cout << "*Single value returns itself as an avarage." << std::endl;
  std::cout << "Triangle Avarage: " << triangle.getAvarage<int>() << std::endl;
  std::cout << "*Successfully avaraged INT to DOUBLE." << std::endl;
  std::cout << "Skipping Square... (type std::string)" << std::endl;

  // not arithmetic compile error
  // std::cout << Sauce.getAvarage<std::string>() << std::endl;

  std::cout << std::endl << "Assert test finished!!" << std::endl;

  return 0;
}
