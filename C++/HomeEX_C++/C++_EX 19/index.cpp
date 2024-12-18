#include <cassert>
#include <iostream>
#include "list.h"

using namespace std;
using namespace List;

int main(void)
{
    list_t *newList = create();

    assert(newList != NULL);
    assert(0 == getAmountOfData(newList));
    assert(!remove(newList, 0));

    assert(insert(newList, 10));
    assert(1 == getAmountOfData(newList));

    assert(insert(newList, 20));
    assert(2 == getAmountOfData(newList));

    assert(insert(newList, 30));
    assert(3 == getAmountOfData(newList));

    assert(search(newList, 10));
    assert(search(newList, 20));
    assert(search(newList, 30));
    assert(!search(newList, 15));

    assert(edit(newList, 20, 15));
    assert(!search(newList, 20));
    assert(search(newList, 15));

    assert(remove(newList, 10));
    assert(2 == getAmountOfData(newList));

    assert(remove(newList, 15));
    assert(1 == getAmountOfData(newList));

    destroy(newList);
    assert(newList == NULL);

    cout << "All test passed!" << endl;

    return 0;
}