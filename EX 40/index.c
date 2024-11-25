#include <stdio.h>
#include <assert.h>
#include "list.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void insertIntoList(int *arr, size_t len);

void testListInsert(void);
void testListFind(void);
void testListRemove(void);
void testListUpdate(void);

int main(void)
{
    testListInsert();
    (void)printf("\nTesting insert... Passed\n");

    testListFind();
    (void)printf("Testing find... Passed\n");

    testListRemove();
    (void)printf("Testing remove... Passed\n");

    testListUpdate();
    (void)printf("Testing update... Passed\n");

    (void)printf("-----------------------------\n");
    (void)printf("All tests Passed!\n\n");

    return 0;
}

void insertIntoList(int *arr, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        assert(listInsert(arr[i]));
        assert(i + 1 == listAvalble());
    }
}

void testListInsert(void)
{
    int randomData[4] = {5, 1, 9, 36};
    insertIntoList(randomData, ARRAY_SIZE(randomData));

    int val = 0;

    assert(listGetData(1, &val));
    assert(5 == val);

    assert(listGetData(2, &val));
    assert(1 == val);

    assert(listGetData(3, &val));
    assert(9 == val);

    assert(listGetData(4, &val));
    assert(36 == val);

    // Fel test
    assert(!listGetData(0, &val));
    assert(!listGetData(10, &val));

    listDelete();
    assert(0 == listAvalble());
}

void testListFind(void)
{
    assert(!listFind(84));

    int randomData[3] = {64, 7, 40};
    insertIntoList(randomData, ARRAY_SIZE(randomData));

    assert(2 == listFind(7));
    assert(3 == listFind(40));
    assert(0 == listFind(84));

    listDelete();
    assert(0 == listAvalble());
}

void testListRemove(void)
{
    assert(!listRemove(33)); // fel test

    int randomData[4] = {5, 1, 9, 36};
    insertIntoList(randomData, ARRAY_SIZE(randomData));

    assert(!listRemove(0)); // fel test
    assert(listRemove(3));

    assert(3 == listAvalble());
    assert(0 == listFind(9));

    assert(listInsert(9));
    assert(4 == listAvalble());
    assert(4 == listFind(9));

    listDelete();
    assert(0 == listAvalble());
}

void testListUpdate(void)
{
    assert(!listUpdate(33, 1));

    int randomData[4] = {5, 1, 9, 36};
    insertIntoList(randomData, ARRAY_SIZE(randomData));

    assert(listUpdate(3, -9));
    assert(!listUpdate(5, 50)); // fel test

    int val = 0;
    assert(listGetData(1, &val));
    assert(5 == val);

    assert(listGetData(2, &val));
    assert(1 == val);

    assert(listGetData(3, &val));
    assert(-9 == val);

    assert(listGetData(4, &val));
    assert(36 == val);

    listDelete();
    assert(0 == listAvalble());
}