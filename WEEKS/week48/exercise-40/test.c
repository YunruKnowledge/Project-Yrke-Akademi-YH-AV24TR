#include "list.h"
#include <stdio.h>
#include <assert.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

static list_t *list = NULL;

static void insert_into_list(list_t *lst, int *array, size_t len)
{
    for (ssize_t i = 0; i < len; i++)
    {
        assert(list_insert(lst, array[i]));
        assert(i + 1 == list_available(list));
    }
}

void test_list_create(void)
{
    list = list_create();
    assert(list != NULL);

    assert(-1 == list_available(NULL));
    assert(0 == list_available(list));

    list_t *temp = list_create();
    assert(temp != NULL);
    assert(0 == list_available(temp));

    list_destroy(&temp);
    assert(temp == NULL);

    list_destroy(&list);
    assert(list == NULL);
}

void test_list_insert(void)
{
    list = list_create();
    assert(list != NULL);
    assert(0 == list_available(list));

    int data[] = {10, 2, 8, 20};
    insert_into_list(list, data, ARRAY_SIZE(data));

    assert(!list_insert(NULL, 30));

    assert(!list_insert(list, 10)); // Test for a duplicate value

    // Check if the list is sorted
    int value = 0;

    assert(list_get_data(list, 1, &value));
    assert(2 == value);

    assert(list_get_data(list, 2, &value));
    assert(8 == value);

    assert(list_get_data(list, 3, &value));
    assert(10 == value);

    assert(list_get_data(list, 4, &value));
    assert(20 == value);

    // Test for invalid parameters
    value = 0;
    assert(!list_get_data(NULL, 1, &value));
    assert(!list_get_data(NULL, 1, NULL));
    assert(!list_get_data(list, 1, NULL));
    assert(!list_get_data(list, 40, &value));
    assert(0 == value);

    list_destroy(&list);
    assert(list == NULL);
}

void test_list_find(void)
{
    list = list_create();
    assert(list != NULL);
    assert(0 == list_available(list));

    size_t position = 0;
    int data[] = {10, 2, 8, 20};
    insert_into_list(list, data, ARRAY_SIZE(data));

    assert(0 == list_find(NULL, 2));
    assert(0 == list_find(list, 40));

    assert(2 == list_find(list, 8));
    assert(3 == list_find(list, 10));

    list_destroy(&list);
    assert(list == NULL);
}

void test_list_delete(void)
{
    list = list_create();
    assert(list != NULL);
    assert(0 == list_available(list));

    int data[] = {10, 2, 8, 20};
    insert_into_list(list, data, ARRAY_SIZE(data));

    assert(!list_delete(NULL, 8));
    assert(!list_delete(list, 30));

    assert(list_delete(list, 8));
    assert(3 == list_available(list));

    assert(list_insert(list, 5));
    assert(4 == list_available(list));

    // Check if the list is still sorted
    int value = 0;

    assert(list_get_data(list, 1, &value));
    assert(2 == value);

    assert(list_get_data(list, 2, &value));
    assert(5 == value);

    assert(list_get_data(list, 3, &value));
    assert(10 == value);

    assert(list_get_data(list, 4, &value));
    assert(20 == value);

    ssize_t available = list_available(list);
    for (ssize_t i = available; i > 0; i--)
    {
        assert(list_get_data(list, i, &value));
        assert(list_delete(list, value));
        assert(i - 1 == list_available(list));
    }

    list_destroy(&list);
    assert(list == NULL);
}

void test_list_update(void)
{
    list = list_create();
    assert(list != NULL);
    assert(0 == list_available(list));

    int data[] = {10, 2, -8, 20};
    insert_into_list(list, data, ARRAY_SIZE(data));

    // Test for invalid parameters
    assert(!list_update(NULL, -8, 8));
    assert(!list_update(list, 30, 60));
    assert(!list_update(list, 2, -8));

    assert(list_update(list, -8, 8));

    // Check if the list is still sorted
    int value = 0;

    assert(list_get_data(list, 1, &value));
    assert(2 == value);

    assert(list_get_data(list, 2, &value));
    assert(8 == value);

    assert(list_get_data(list, 3, &value));
    assert(10 == value);

    assert(list_get_data(list, 4, &value));
    assert(20 == value);

    list_destroy(&list);
    assert(list == NULL);
}

int main(void)
{
    test_list_create();
    (void)printf("\nTesting create... Passed\n");

    test_list_insert();
    (void)printf("Testing insert... Passed\n");

    test_list_find();
    (void)printf("Testing find... Passed\n");

    test_list_delete();
    (void)printf("Testing delete... Passed\n");

    test_list_update();
    (void)printf("Testing update... Passed\n");

    (void)printf("-----------------------------\n");
    (void)printf("All tests Passed!\n\n");

    return 0;
}