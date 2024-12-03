/**
 * @file list.h
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief A multiple instance linked list module to store unique and sorted data elements of type int.
 *        The module shall provide:
 *          1) A function to create a linked list.
 *          2) A function to insert a new data element into a linked list
 *          3) A function to get the number of data elements stored in a linked list
 *          4) A function to delete a data element from a linked list
 *          5) A function to search for a specific value in a linked list
 *          6) A function to get data stored in the nth node of a linked list.
 *          7) A function to to change a data element stored in a list.
 *          8) A function to destroy a linked list
 *
 * @version 0.1
 * @date 2022-11-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

typedef struct list list_t;

/**
 * @brief This function is used to create a linked list.
 *
 * @return list_t* NULL if an error occurs else a pointer to the create empty list.
 */
list_t *list_create(void);

/**
 * @brief This function is used to insert a data element into a list.
 *
 * @param list A pointer to the list.
 * @param value The data to insert.
 * @return bool - false if an error occurs; otherwise true
 */
bool list_insert(list_t *list, int value);

/**
 * @brief This function returns number of the data elements stored in a list.
 *
 * @param list A pointer to the list.
 * @return ssize_t: -1 if the list is empty or list is NULL else number of the data elements
 */
ssize_t list_available(list_t *list);

/**
 * @brief This function is used to search for a specific data in a list.
 *
 * @param list A pointer to the list.
 * @param value The data to search for.
 * @return size_t - 0 if data is not in the list or the list is empty; otherwise position of the node which contains the data.
 */
size_t list_find(list_t *list, int value);

/**
 * @brief This function is used to get the data stored int the nth element of a list.
 *
 * @param list A pointer to the list.
 * @param n The nth node. n shall be a valid position and greater than 0
 * @param data Address of a placeholder to store the data in.
 * @return bool - false if an error occurs; otherwise true
 */
bool list_get_data(list_t *list, size_t n, int *data);

/**
 * @brief This function is used to delete a data element from a list
 *
 * @param list A pointer to the list.
 * @param value The value to delete
 * @return bool - false if an error occurs; otherwise true
 */
bool list_delete(list_t *list, int value);

/**
 * @brief This function is used to change a data element stored in a list.
 *
 * @param list A pointer to the list.
 * @param oval The old value.
 * @param nval The new value to store
 * @return bool - false if an error occurs; otherwise true
 */
bool list_update(list_t *list, int oval, int nval);

/**
 * @brief This function is used to destroy a list.
 *
 * @param list Address of a pointer to a list to destroy.
 */
void list_destroy(list_t **list);

#endif