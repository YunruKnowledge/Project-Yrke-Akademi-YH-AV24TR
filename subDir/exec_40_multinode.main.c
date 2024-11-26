
#include "exec_40_multinode.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void printDebug(const char *_string, bool _isStart);
void testCreate(void);
void testChange(void);
void testDelete(void);
void testSearch(void);
void testSearchNode(void);
void testDestroy(void);

int main(void) {
  printDebug("CREATE", true);
  testCreate();
  printDebug("CREATE", false);

  printDebug("CHANGE", true);
  testChange();
  printDebug("CHANGE", false);

  printDebug("DELETE", true);
  testDelete();
  printDebug("DELETE", false);

  printDebug("SEARCH VALUE", true);
  testSearch();
  printDebug("SEARCH VALUE", false);

  printDebug("DESTROY", true);
  testDestroy();
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

void testCreate(void) {
  for (size_t i = 0; i < 8; i++) {
    const size_t _temp = rand();
    assert(nodeListCreate(_temp));
    (void)printf("Added %i", _temp);
    if (i < 7)
      (void)printf(", ");
  }
  assert(8 == nodeListGetCount());
  (void)printf(" | Total - %i\n", nodeListGetCount());
}

void testChange(void) {
  int _temp = 0;
  nodeListChange(24, 2);
  nodeListSearchNode(&_temp, 2);
  assert(_temp == 24);
  (void)printf("Read 2th node, value: %i\n", _temp);
}

void testDelete(void) {
  (void)printf("Node amount: %i\n", nodeListGetCount());
  (void)printf("Deleting 2th node.\n");
  nodeListDelete(2);

  (void)printf("Node amount: %i\n", nodeListGetCount());
  assert(7 == nodeListGetCount());

  int _temp = 0;
  nodeListSearchNode(&_temp, 2);
  (void)printf("Read 2th node, value: %i\n", _temp);
}

void testSearch(void) {
  for (size_t i = 0; i < 7; i++) {
    int _temp = 0;
    nodeListSearchNode(&_temp, i);
    (void)printf("Read %ith node, value: %i\n", i, _temp);

    assert(i == nodeListSearchValue(_temp));
    (void)printf("Find value %u, node: %u\n", _temp, i);
  }
}

void testDestroy(void) {
  (void)printf("Node amount: %i\n", nodeListGetCount());
  assert(7 == nodeListGetCount());

  (void)printf("Freeing nodes...\n");
  nodeListFreeAll();
  assert(0 == nodeListGetCount());
  (void)printf("Node amount: %i\n", nodeListGetCount());

  int _temp = 0;
  nodeListSearchNode(&_temp, 1);
  assert(0 == _temp);
  (void)printf("Read %ith node, value: %i\n", 1, _temp);
}