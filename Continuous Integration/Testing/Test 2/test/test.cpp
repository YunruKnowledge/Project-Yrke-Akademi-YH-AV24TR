#include <gtest/gtest.h>
#include <string>
#include "stack.hpp"

TEST(test_stack_int, TestStackInt)
{
    stack<int> s{10};
    int value;

    EXPECT_EQ(s.getSize(), 0);
    EXPECT_EQ(s.peek(), 0);

    EXPECT_TRUE(s.push(10));
    EXPECT_EQ(s.getSize(), 1);

    EXPECT_TRUE(s.push(20));
    EXPECT_EQ(s.getSize(), 2);

    EXPECT_TRUE(s.push(30));
    EXPECT_EQ(s.getSize(), 3);

    EXPECT_EQ(s.peek(), 30);

    EXPECT_TRUE(s.pop(value));
    EXPECT_EQ(value, 30);
    EXPECT_EQ(s.peek(), 20);
    EXPECT_EQ(s.getSize(), 2);

    EXPECT_TRUE(s.pop(value));
    EXPECT_EQ(value, 20);
    EXPECT_EQ(s.peek(), 10);
    EXPECT_EQ(s.getSize(), 1);

    EXPECT_TRUE(s.pop(value));
    EXPECT_EQ(value, 10);
    EXPECT_EQ(s.peek(), 0);
    EXPECT_EQ(s.getSize(), 0);

    s.clear();
    EXPECT_EQ(s.getSize(), 0);
}

TEST(test_stack_float, TestStackFloat)
{
    stack<float> s{10};
    float value;

    EXPECT_EQ(s.getSize(), 0);
    EXPECT_EQ(s.peek(), 0);

    EXPECT_TRUE(s.push(10.5));
    EXPECT_EQ(s.getSize(), 1);

    EXPECT_TRUE(s.push(20.5));
    EXPECT_EQ(s.getSize(), 2);

    EXPECT_TRUE(s.push(30.5));
    EXPECT_EQ(s.getSize(), 3);

    EXPECT_EQ(s.peek(), 30.5);

    EXPECT_TRUE(s.pop(value));
    EXPECT_EQ(value, 30.5);
    EXPECT_EQ(s.peek(), 20.5);
    EXPECT_EQ(s.getSize(), 2);

    EXPECT_TRUE(s.pop(value));
    EXPECT_EQ(value, 20.5);
    EXPECT_EQ(s.peek(), 10.5);
    EXPECT_EQ(s.getSize(), 1);

    EXPECT_TRUE(s.pop(value));
    EXPECT_EQ(value, 10.5);
    EXPECT_EQ(s.peek(), 0);
    EXPECT_EQ(s.getSize(), 0);

    s.clear();
    EXPECT_EQ(s.getSize(), 0);
}

TEST(test_stack_string, TestStackString)
{
    stack<std::string> s{10};
    std::string value;

    EXPECT_EQ(s.getSize(), 0);
    EXPECT_EQ(s.peek(), "");

    EXPECT_TRUE(s.push("Hello"));
    EXPECT_EQ(s.getSize(), 1);

    EXPECT_TRUE(s.push("Hi"));
    EXPECT_EQ(s.getSize(), 2);

    EXPECT_TRUE(s.push("Bye"));
    EXPECT_EQ(s.getSize(), 3);

    EXPECT_EQ(s.peek(), "Bye");

    EXPECT_TRUE(s.pop(value));
    EXPECT_EQ(value, "Bye");
    EXPECT_EQ(s.peek(), "Hi");
    EXPECT_EQ(s.getSize(), 2);

    EXPECT_TRUE(s.pop(value));
    EXPECT_EQ(value, "Hi");
    EXPECT_EQ(s.peek(), "Hello");
    EXPECT_EQ(s.getSize(), 1);

    EXPECT_TRUE(s.pop(value));
    EXPECT_EQ(value, "Hello");
    EXPECT_EQ(s.peek(), "");
    EXPECT_EQ(s.getSize(), 0);

    s.clear();
    EXPECT_EQ(s.getSize(), 0);
}