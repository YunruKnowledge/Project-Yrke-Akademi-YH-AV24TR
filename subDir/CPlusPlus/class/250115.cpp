#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <map>

// Template Type but checks for Numbers only.
template <typename Type,
          typename = std::enable_if_t<std::is_arithmetic_v<Type>>>
void print(const Type _val) {
  std::cout << _val << std::endl;
}

// Nested templates. & redefine outside class scope.
template <typename x> class Class_A {
public:
  x value;
  template <typename y> class Class_B {
  public:
    void func(x _a, y _b) {};
  };

  Class_A(const x _val) : value{_val} {};
};

template <typename x>
template <typename y>
void Class_A<x>::Class_B<y>::func(x _a, y _b) {
  std::cout << _a << _b << std::endl;
};

// Template with multi args.
template <typename Type, typename... Multi>
void print(Type _first, Multi... _args) {
  std::cout << _val << std::endl;
  std::cout << _args << std::endl;
}

// Template using another template.
// (using Class_B) (note: "typename U" works on newer C++ versions)
template <typename X, typename Y, class U> class Class_C {
public:
  U<X, Y>;
};

// Tests
int main(void) {
  print(2);         // <-- INT
  print(2.2f);      // <-- FLOAT
  print(2.2222222); // <-- DOUBLE
  // print("aom"); // <-- fails (CONST CHAR *)

  Class_A classA{2};
  Class_A<int>::Class_B<double> classB;
  classB.func(classA.value, 3.1415);

  print(24, "lmao", 25, "multiargs.?()");

  Class_C<int, double, Class_A<int>::Class_B<double>> classC; // what

  //
  //
  //

  std::deque<int> deque{1, 2}; // queue but both front and back.
  deque.push_front(0);
  deque.push_back(3);

  std::list<int> list(5); // takes in amount of elements.
  list.assign(1, 25);

  // adding "multi" before set or map, makes them no longer handle uniques.
  std::set<int> set{1, 1, 1, 2, 2}; // uniques (numbers) only. (e.g set has only 1, 2)

  // adding "unordered_" before (multi)map, makes them ignore ordering.
  std::map<std::string, int> map; // uniques (string) only. Sorted by value.
  map["keyName"] = 33;
  map["keyName"] = 44; // <-- GONE
  map["Baller Moves"] = 11; // <-- now the new first element

  return 0;
}