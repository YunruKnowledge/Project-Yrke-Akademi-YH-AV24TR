#ifndef MODULE_EXEC40_MULTINODE
#define MODULE_EXEC40_MULTINODE

#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Create a node.
 * 
 * @param _value The value the node will have.
 * @return `true` if successful.
 */
bool nodeListCreate(const int _value);

/**
 * @brief Changes a node's value
 * 
 * @param _value The value applied to the node.
 * @param _index Index of node position in list.
 * @return `true` if successful.
 */
bool nodeListChange(const int _value, size_t _index);

/**
 * @brief Free a node based on an index.
 * 
 * @param _index Index of node position in list.
 * @return `true` if successful.
 */
bool nodeListDelete(const size_t _index);

/**
 * @brief Searches which node has the provided value.
 * 
 * @param _value To match with a node's value
 * @return size_t - index of the node.
 */
size_t nodeListSearchValue(const int _value);

/**
 * @brief Apply the value of a node to a pointer based on an index.
 * 
 * @param _interger A pointer to apply the value to.
 * @param _index Index of node position in list.
 * @return `true` if successful
 */
bool nodeListSearchNode(int *_interger, const size_t _index);

/**
 * @brief Gets the count of the amount of nodes in memory.
 *
 * @return size_t
 */
size_t nodeListGetCount(void);

/**
 * @brief Frees all the nodes from memory.
 *
 */
void nodeListFreeAll(void);

#endif