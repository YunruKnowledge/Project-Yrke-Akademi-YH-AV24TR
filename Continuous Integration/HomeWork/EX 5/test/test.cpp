#include <gtest/gtest.h>
#include <string>
#include "queue.h"

TEST(int_queue, TestQueueInt)
{
    queue<int> q;
    EXPECT_EQ(q.getSize(), 0);

    EXPECT_TRUE(q.enqueue(10));
    EXPECT_TRUE(q.enqueue(20));
    EXPECT_TRUE(q.enqueue(30));

    EXPECT_EQ(q.getSize(), 3);
    EXPECT_EQ(q.peek(), 10);

    EXPECT_TRUE(q.dequeue());

    EXPECT_EQ(q.getSize(), 2);
    EXPECT_EQ(q.peek(), 20);

    q.clear();

    EXPECT_EQ(q.getSize(), 0);
    EXPECT_EQ(q.peek(), 0);

    EXPECT_FALSE(q.dequeue());
}

TEST(float_queue, TestQueueFloat)
{
    queue<float> q;
    EXPECT_EQ(q.getSize(), 0);

    EXPECT_TRUE(q.enqueue(10.5));
    EXPECT_TRUE(q.enqueue(20.5));
    EXPECT_TRUE(q.enqueue(30.5));

    EXPECT_EQ(q.getSize(), 3);
    EXPECT_EQ(q.peek(), 10.5);

    EXPECT_TRUE(q.dequeue());

    EXPECT_EQ(q.getSize(), 2);
    EXPECT_EQ(q.peek(), 20.5);

    q.clear();

    EXPECT_EQ(q.getSize(), 0);
    EXPECT_EQ(q.peek(), 0);

    EXPECT_FALSE(q.dequeue());
}

TEST(string_queue, TestQueueString)
{
    queue<std::string> q;
    EXPECT_EQ(q.getSize(), 0);

    EXPECT_TRUE(q.enqueue("Hi"));
    EXPECT_TRUE(q.enqueue("Hello"));
    EXPECT_TRUE(q.enqueue("Me"));

    EXPECT_EQ(q.getSize(), 3);
    EXPECT_EQ(q.peek(), "Hi");

    EXPECT_TRUE(q.dequeue());

    EXPECT_EQ(q.getSize(), 2);
    EXPECT_EQ(q.peek(), "Hello");

    q.clear();

    EXPECT_EQ(q.getSize(), 0);
    EXPECT_EQ(q.peek(), "");

    EXPECT_FALSE(q.dequeue());
}