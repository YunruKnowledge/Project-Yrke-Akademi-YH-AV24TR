/**
 * @file exec_29.cpp
 * @author SkyThe (88000687+YunruKnowledge@users.noreply.github.com)
 * @brief Used for converting a value -inside a range -into a different value
 * equivelant to the value in the other range. 
 * @version 0.1
 * @date 2025-01-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>

template <typename Type_b,
          typename = std::enable_if_t<std::is_arithmetic_v<Type_b>>>
class Range {
public:
  Type_b from;
  Type_b to;
};

template <typename Type_a, typename Type_b>
Type_b map(Type_a _value, Range<Type_a> _range_a, Range<Type_b> _range_b) {

  static_assert(std::is_arithmetic_v<Type_a> && std::is_arithmetic_v<Type_b>);

  return (((_range_b.to - _range_b.from) / (_range_a.to - _range_a.from)) *
              (_value - _range_a.from) +
          _range_b.from);
}

int main(void) {
  Range<float> a{0.0f, 3.3f};
  Range<int> b{0, 1023};
  std::cout << map(0.5f, a, b) << std::endl;

  Range<float> a2{0.0f, 100.0f};
  Range<int> b2{0, 1000};
  std::cout << map(10.0f, a2, b2) << std::endl;
  return 0;
}