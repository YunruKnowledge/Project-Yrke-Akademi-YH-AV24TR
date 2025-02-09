#include "stack.hpp"
#include <gtest/gtest.h>
// #LIST NOT A STACK

TEST(STACK_GENERAL, PUSH) {
  Stack stack;
  for (size_t i = 1; i <= 10000; i++) {
    EXPECT_TRUE(stack.push((i * 10)));
    EXPECT_EQ(stack.amount(), i);
  }
}

TEST(STACK_GENERAL, POP) {
  Stack stack;
  for (size_t i = 1; i <= 10; i++) {
    EXPECT_TRUE(stack.push((i * 10)));
  }

  int temp{0};
  for (size_t i = 10; i <= 1; i--) {
    (void)stack.pop(temp);
    EXPECT_EQ(temp, (i * 10));
  }
}

TEST(STACK_GENERAL, CLEAR) {
  Stack stack;
  int temp{0};
  for (size_t i = 1; i <= 10; i++) {
    EXPECT_TRUE(stack.push((i * 10)));
  }
  EXPECT_EQ(stack.amount(), 10);

  stack.clear();
  EXPECT_EQ(stack.amount(), 0);
  EXPECT_FALSE(stack.pop(temp));
}

TEST(STACK_REQUIREMENTS, UNIQUE) {
  Stack stack;
  EXPECT_TRUE(stack.push(11));
  EXPECT_FALSE(stack.push(11));
  EXPECT_EQ(stack.amount(), 1);
}

TEST(STACK_REQUIREMENTS, SORTED) {
  Stack stack;
  int temp{0};

  EXPECT_TRUE(stack.push(11));
  EXPECT_TRUE(stack.push(33));
  EXPECT_TRUE(stack.push(22));

  (void)stack.pop(temp);
  EXPECT_EQ(temp, 33);
  (void)stack.pop(temp);
  EXPECT_EQ(temp, 22);
  (void)stack.pop(temp);
  EXPECT_EQ(temp, 11);
}

TEST(STACK_REQUIREMENTS, MOVABLE) {
  Stack stack;
  int temp{0};

  for (size_t i = 1; i <= 10; i++) {
    EXPECT_TRUE(stack.push(i));
  }
  EXPECT_EQ(stack.amount(), 10);

  Stack spacc{std::move(stack)};
  EXPECT_EQ(spacc.amount(), 10);
  EXPECT_EQ(stack.amount(), 0);

  (void)spacc.pop(temp);
  (void)spacc.pop(temp);
  (void)spacc.pop(temp);
  (void)spacc.pop(temp);
  (void)spacc.pop(temp);
  EXPECT_EQ(spacc.amount(), 5);

  stack = std::move(spacc);
  EXPECT_EQ(stack.amount(), 5);
  EXPECT_EQ(spacc.amount(), 0);

  for (size_t i = 5; i <= 1; i--) {
    (void)spacc.pop(temp);
    EXPECT_EQ(temp, i);
  }
}

TEST(STACK_REQUIREMENTS, SEARCH) {
  Stack stack;

  EXPECT_TRUE(stack.push(11));
  EXPECT_TRUE(stack.push(33));
  EXPECT_TRUE(stack.push(22));

  EXPECT_EQ(stack.search(22), 2);
  EXPECT_EQ(stack.search(44), 0);
}

TEST(STACK_REQUIREMENTS, REMOVE) {
  Stack stack;
  int temp{0};

  EXPECT_TRUE(stack.push(11));
  EXPECT_TRUE(stack.push(44));
  EXPECT_TRUE(stack.push(33));
  EXPECT_TRUE(stack.push(22));
  EXPECT_EQ(stack.amount(), 4);

  EXPECT_TRUE(stack.remove(22));

  EXPECT_EQ(stack.amount(), 3);
  EXPECT_EQ(stack.search(22), 0);

  (void)stack.pop(temp);
  EXPECT_EQ(temp, 44);
}

TEST(STACK_REQUIREMENTS, EDIT) {
  Stack stack;
  int temp{0};

  EXPECT_TRUE(stack.push(11));
  EXPECT_TRUE(stack.push(22));
  EXPECT_TRUE(stack.push(33));
  EXPECT_TRUE(stack.push(44));
  EXPECT_TRUE(stack.push(55));

  // largest
  EXPECT_TRUE(stack.edit(stack.search(22), 66));

  // smallest
  EXPECT_TRUE(stack.edit(stack.search(11), 15));

  // moved deeper
  EXPECT_TRUE(stack.edit(stack.search(44), 27));

  // same place
  EXPECT_TRUE(stack.edit(stack.search(33), 39));

  EXPECT_TRUE(stack.pop(temp));
  EXPECT_EQ(temp, 66);
  EXPECT_TRUE(stack.pop(temp));
  EXPECT_EQ(temp, 55);
  EXPECT_TRUE(stack.pop(temp));
  EXPECT_EQ(temp, 39);
  EXPECT_TRUE(stack.pop(temp));
  EXPECT_EQ(temp, 27);
  EXPECT_TRUE(stack.pop(temp));
  EXPECT_EQ(temp, 15);
}