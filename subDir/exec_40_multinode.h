#ifndef MODULE_EXEC40_MULTINODE
#define MODULE_EXEC40_MULTINODE

#include <stdbool.h>
#include <stdio.h>

typedef struct LIST list_t;

/**
 * @brief Create a linked list.
 * 
 * @return list_t* 
 */
list_t *nodeListCreate(void);

/**
 * @brief Create a node.
 * 
 * @param _list Adress of list.
 * @param _value The value the node will have.
 * @return `true` if successful.
 */
bool nodeListCreateNode(list_t *_list, const int _value);

/**
 * @brief Changes a node's value
 * 
 * @param _list Adress of list.
 * @param _value The value applied to the node.
 * @param _index Index of node position in list.
 * @return `true` if successful.
 */
bool nodeListChange(list_t *_list, const int _value, size_t _index);

/**
 * @brief Free a node based on an index.
 * 
 * @param _list Adress of list.
 * @param _index Index of node position in list.
 * @return `true` if successful.
 */
bool nodeListDelete(list_t *_list, const size_t _index);

/**
 * @brief Searches which node has the provided value.
 * 
 * @param _list Adress of list.
 * @param _value To match with a node's value
 * @return size_t - index of the node.
 */
size_t nodeListSearchValue(list_t *_list, const int _value);

/**
 * @brief Apply the value of a node to a pointer based on an index.
 * 
 * @param _list Adress of list.
 * @param _interger A pointer to apply the value to.
 * @param _index Index of node position in list.
 * @return `true` if successful
 */
bool nodeListSearchNode(list_t *_list, int *_interger, const size_t _index);

/**
 * @brief Gets the count of the amount of nodes in memory.
 *
 * @param _list Adress of list.
 * @return The count in `size_t`
 */
size_t nodeListGetCount(list_t *_list);

/**
 * @brief Frees all the nodes from memory.
 *
 * @param _list Adress of list.
 */
void nodeListFreeAll(list_t **_list);

#endif