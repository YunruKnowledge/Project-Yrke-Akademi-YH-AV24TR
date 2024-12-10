
#include "exec_40_multinode.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void printDebug(const char *_string, bool _isStart);
void testCreate(list_t *_list);
void testChange(list_t *_list);
void testDelete(list_t *_list);
void testSearch(list_t *_list);
void testSearchNode(list_t *_list);
void testDestroy(list_t *_list);

int main(void) {
  list_t *_linked_list = nodeListCreate();

  printDebug("CREATE", true);
  testCreate(_linked_list);
  printDebug("CREATE", false);

  printDebug("CHANGE", true);
  testChange(_linked_list);
  printDebug("CHANGE", false);

  printDebug("DELETE", true);
  testDelete(_linked_list);
  printDebug("DELETE", false);

  printDebug("SEARCH VALUE", true);
  testSearch(_linked_list);
  printDebug("SEARCH VALUE", false);

  printDebug("DESTROY", true);
  testDestroy(_linked_list);
  printDebug("DESTROY", false);

  return 0;
}

static void printDebug(const char *_string, bool _isStart) {
  (void)printf("***DEBUG ");
  (void)printf("%s", _string);
  (void)printf(" TEST ");
  if (_isStart)
    (void)printf("START ***\n");
  else
    (void)printf("END ***\n\n");
}

void testCreate(list_t *_list) {
  for (size_t i = 0; i < 8; i++) {
    const size_t _temp = rand();
    assert(nodeListCreateNode(_list, _temp));
    (void)printf("Added %i", _temp);
    if (i < 7)
      (void)printf(", ");
  }
  assert(8 == nodeListGetCount(_list));
  (void)printf(" | Total - %i\n", nodeListGetCount(_list));
}

void testChange(list_t *_list) {
  int _temp = 0;
  nodeListChange(_list, 24, 2);
  nodeListSearchNode(_list, &_temp, 2);
  assert(_temp == 24);
  (void)printf("Read 2th node, value: %i\n", _temp);
}

void testDelete(list_t *_list) {
  (void)printf("Node amount: %i\n", nodeListGetCount(_list));
  (void)printf("Deleting 2th node.\n");
  nodeListDelete(_list, 2);

  (void)printf("Node amount: %i\n", nodeListGetCount(_list));
  assert(7 == nodeListGetCount(_list));

  int _temp = 0;
  nodeListSearchNode(_list, &_temp, 2);
  (void)printf("Read 2th node, value: %i\n", _temp);
}

void testSearch(list_t *_list) {
  for (size_t i = 0; i < 7; i++) {
    int _temp = 0;
    nodeListSearchNode(_list, &_temp, i);
    (void)printf("Read %ith node, value: %i\n", i, _temp);

    assert(i == nodeListSearchValue(_list, _temp));
    (void)printf("Find value %u, node: %u\n", _temp, i);
  }
}

void testDestroy(list_t *_list) {
  (void)printf("Node amount: %i\n", nodeListGetCount(_list));
  assert(7 == nodeListGetCount(_list));

  (void)printf("Freeing nodes...\n");
  nodeListFreeAll(&_list);
  assert(0 == nodeListGetCount(_list));
  (void)printf("Node amount: %i\n", nodeListGetCount(_list));

  int _temp = 0;
  nodeListSearchNode(_list, &_temp, 1);
  assert(0 == _temp);
  (void)printf("Read %ith node, value: %i\n", 1, _temp);
}