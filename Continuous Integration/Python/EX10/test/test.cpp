#include <gtest/gtest.h>
#include "list.h"

List list;

TEST(test_list_insert, test_list_insert)
{
    EXPECT_TRUE(list.insert(10));
    EXPECT_TRUE(list.insert(20));
    EXPECT_TRUE(list.insert(30));
    EXPECT_EQ(list.getSize(), 3);
}

TEST(test_list_search, test_list_search)
{
    EXPECT_EQ(list.search(10), 1);
    EXPECT_EQ(list.search(20), 2);
    EXPECT_EQ(list.search(30), 3);
}

TEST(test_list_modify, test_list_modify)
{
    EXPECT_TRUE(list.modify(10, 40));
    EXPECT_TRUE(list.modify(20, 50));
    EXPECT_TRUE(list.modify(30, 60));
}

TEST(test_list_remove, test_list_remove)
{
    EXPECT_TRUE(list.remove(40));
    EXPECT_TRUE(list.remove(50));
    EXPECT_TRUE(list.remove(60));
    EXPECT_EQ(list.getSize(), 0);
}