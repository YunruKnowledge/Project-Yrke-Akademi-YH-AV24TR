#include <unity.h>
#include "../Lib/list.h"

List list;

void setUp(void) {}

void tearDown(void) {}

void test_list_insert(void)
{
    TEST_ASSERT(list.insert(10));
    TEST_ASSERT(list.insert(20));
    TEST_ASSERT(list.insert(30));
    TEST_ASSERT_EQUAL(list.getSize(), 3);
}

void test_list_search(void)
{
    TEST_ASSERT(list.search(10));
    TEST_ASSERT(list.search(20));
    TEST_ASSERT(list.search(30));
}

void test_list_modify(void)
{
    TEST_ASSERT(list.modify(10, 40));
    TEST_ASSERT(list.modify(20, 50));
    TEST_ASSERT(list.modify(30, 60));
}

void test_list_remove(void)
{
    TEST_ASSERT(list.remove(40));
    TEST_ASSERT(list.remove(50));
    TEST_ASSERT(list.remove(60));
    TEST_ASSERT_EQUAL(list.getSize(), 0);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_list_insert);
    RUN_TEST(test_list_search);
    RUN_TEST(test_list_modify);
    RUN_TEST(test_list_remove);

    return UNITY_END();

    return 0;
}