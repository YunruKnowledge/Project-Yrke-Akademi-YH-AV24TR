#include "queue.hpp"
#include <gtest/gtest.h>
#include <string>

using MyTypes = ::testing::Types<int, float>;
template <typename T> class QueueTest : public ::testing::Test {
protected:
  Queue<T> queue;
};

TYPED_TEST_SUITE(QueueTest, MyTypes);
TYPED_TEST(QueueTest, ENQUEUE_N_SIZE) {
  for (size_t i = 0; i < 1000; i++) {
    TypeParam value;
    value = static_cast<TypeParam>(i);
    EXPECT_TRUE(this->queue.enqueue(value));
    EXPECT_EQ(this->queue.amount(), i + 1);
  }
}

TYPED_TEST(QueueTest, DEQUEUE) {
  TypeParam value1, value2, value3;

  value1 = static_cast<TypeParam>(11);
  value2 = static_cast<TypeParam>(22);
  value3 = static_cast<TypeParam>(33);

  this->queue.enqueue(value1);
  this->queue.enqueue(value2);
  this->queue.enqueue(value3);

  TypeParam temp;
  EXPECT_TRUE(this->queue.dequeue(temp));
  EXPECT_EQ(temp, value1);

  EXPECT_TRUE(this->queue.dequeue(temp));
  EXPECT_EQ(temp, value2);

  EXPECT_TRUE(this->queue.dequeue(temp));
  EXPECT_EQ(temp, value3);
}

TYPED_TEST(QueueTest, CLEAR) {
  TypeParam value1, value2, value3;

  value1 = static_cast<TypeParam>(11);
  value2 = static_cast<TypeParam>(22);
  value3 = static_cast<TypeParam>(33);

  this->queue.enqueue(value1);
  this->queue.enqueue(value2);
  this->queue.enqueue(value3);

  this->queue.clear();

  TypeParam temp;
  EXPECT_FALSE(this->queue.dequeue(temp));
  EXPECT_EQ(this->queue.amount(), 0);
}

TYPED_TEST(QueueTest, MOVABLE) {
  TypeParam value1, value2, value3;

  value1 = static_cast<TypeParam>(11);
  value2 = static_cast<TypeParam>(22);
  value3 = static_cast<TypeParam>(33);

  this->queue.enqueue(value1);
  this->queue.enqueue(value2);
  this->queue.enqueue(value3);
  EXPECT_EQ(this->queue.amount(), 3);

  Queue<TypeParam> queue_two{std::move(this->queue)};
  EXPECT_EQ(queue_two.amount(), 3);
  EXPECT_EQ(this->queue.amount(), 0);

  TypeParam temp;
  EXPECT_TRUE(queue_two.dequeue(temp));
  EXPECT_EQ(temp, value1);

  EXPECT_TRUE(queue_two.dequeue(temp));
  EXPECT_EQ(temp, value2);
  EXPECT_EQ(queue_two.amount(), 1);

  this->queue = std::move(queue_two);
  EXPECT_EQ(this->queue.amount(), 1);
  EXPECT_EQ(queue_two.amount(), 0);

  EXPECT_TRUE(this->queue.dequeue(temp));
  EXPECT_EQ(temp, value3);
  EXPECT_EQ(this->queue.amount(), 0);
}

TEST(QUEUE_STRING, ENQUEUE_N_SIZE) {
  Queue<std::string> queue;
  for (size_t i = 0; i < 1000; i++) {
    std::string temp = "STRING-" + std::to_string(i);
    EXPECT_TRUE(queue.enqueue(temp));
    EXPECT_EQ(queue.amount(), i + 1);
  }
}

TEST(QUEUE_STRING, DEQUEUE) {
  Queue<std::string> queue;
  std::string temp{""}, answer{""};
  for (size_t i = 0; i < 5; i++) {
    temp = "STRING-" + std::to_string(i);
    EXPECT_TRUE(queue.enqueue(temp));
  }

  for (size_t i = 0; i < 5; i++) {
    answer = "STRING-" + std::to_string(i);
    EXPECT_TRUE(queue.dequeue(temp));
    EXPECT_EQ(temp, answer);
  }
}

TEST(QUEUE_STRING, CLEAR) {
  Queue<std::string> queue;
  std::string temp{""};
  for (size_t i = 0; i < 5; i++) {
    temp = "STRING-" + std::to_string(i);
    EXPECT_TRUE(queue.enqueue(temp));
  }

  queue.clear();
  EXPECT_EQ(queue.amount(), 0);
  EXPECT_FALSE(queue.dequeue(temp));
}

TEST(QUEUE_STRING, MOVABLE) {
  Queue<std::string> queue;
  std::string temp{""}, answer{""};
  for (size_t i = 0; i < 10; i++) {
    temp = "STRING-" + std::to_string(i);
    EXPECT_TRUE(queue.enqueue(temp));
  }

  Queue<std::string> queue_two{std::move(queue)};
  EXPECT_EQ(queue.amount(), 0);
  EXPECT_EQ(queue_two.amount(),10);

  for (size_t i = 0; i < 5; i++) {
    answer = "STRING-" + std::to_string(i);
    EXPECT_TRUE(queue_two.dequeue(temp));
    EXPECT_EQ(temp, answer);
  }

  queue = std::move(queue_two);
  EXPECT_EQ(queue_two.amount(),0);
  EXPECT_EQ(queue.amount(), 5);
  
  for (size_t i = 4; i < 10; i++) {
    answer = "STRING-" + std::to_string(i);
    EXPECT_TRUE(queue.dequeue(temp));
    EXPECT_EQ(temp, answer);
  }
}
