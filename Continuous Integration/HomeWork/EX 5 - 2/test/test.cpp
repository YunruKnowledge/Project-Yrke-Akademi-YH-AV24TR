#include <gtest/gtest.h>
#include <string>
#include <type_traits>
#include "queue.h"

template <typename T>
class SizeTest : public testing::Test
{
protected:
    queue<T> q;

    void SetUp(void) override
    {
        T x{1};
        for (int i = 0; i < 10; i++)
        {
            if constexpr (std::is_same<T, std::string>::value)
            {
                q.enqueue(std::to_string(i));
            }
            else
            {
                q.enqueue(i * x);
            }
        }
    }

    void TearDown(void) override {}
};

using MyTypes = ::testing::Types<int, float, std::string>;

TYPED_TEST_SUITE(SizeTest, MyTypes);

TYPED_TEST(SizeTest, TestQueueSizes)
{
    EXPECT_EQ(this->q.getSize(), 10);
}

TYPED_TEST(SizeTest, TestQueuePop)
{
    TypeParam var;
    EXPECT_TRUE(this->q.dequeue());
    EXPECT_TRUE(this->q.dequeue());
    EXPECT_TRUE(this->q.dequeue());
    EXPECT_TRUE(this->q.dequeue());

    EXPECT_EQ(this->q.getSize(), 6);
}

TYPED_TEST(SizeTest, TestQueuePeek)
{
    if constexpr (std::is_same<TypeParam, std::string>::value)
    {
        EXPECT_EQ(this->q.peek(), "0");
        EXPECT_EQ(this->q.peek(), "0");
        EXPECT_EQ(this->q.peek(), "0");
        EXPECT_EQ(this->q.peek(), "0");
    }
    else
    {
        EXPECT_EQ(this->q.peek(), 0);
        EXPECT_EQ(this->q.peek(), 0);
        EXPECT_EQ(this->q.peek(), 0);
        EXPECT_EQ(this->q.peek(), 0);
    }

    EXPECT_EQ(this->q.getSize(), 10);
}