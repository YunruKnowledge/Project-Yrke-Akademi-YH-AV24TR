/**
 * @file list.h
 *
 * @author Lazar Roksandic
 *
 * @brief Multi instance linked list
 * @version 0.1
 * @date 17-12-2024
 *
 * @copyright Copyright (c) 2024
 */
#ifndef LIST_H
#define LIST_H

#include <ostream>

struct list_t;

namespace List
{

    /**
     * @brief Function is used to create a new linked list
     *
     * @return Null if error occurs else pointer to the list
     */
    list_t *create(void);

    /**
     * @brief Insets a value to the linked list as a new node
     *
     * @param list A list to inset value to
     * @param value A value you want to inset
     * @return true if inseting a value is successful
     * @return false if inseting a value is not successful or list is null
     */
    bool insert(list_t *list, int value);

    /**
     * @brief Check if the value is in the linked list
     *
     * @param list A list you want to search in
     * @param value A value you want to check if it exist in the given list
     * @return true if there is a maching value in given linked list
     * @return false if there is no maching value in given linked list or list is null
     */
    bool search(list_t *list, int value);

    /**
     * @brief Remove the value you want from the linked list
     *
     * @param list A list you want to remove value from
     * @param value A value that you want to remove
     * @return true If value is successfully removed
     * @return false If the list is null, or if value doesn't exist in the list
     */
    bool remove(list_t *list, int value);

    /**
     * @brief Edit an old value with the new value
     *
     * @param list A list you want to edit
     * @param oldValue A value you want to edit
     * @param newValue A new value you want to replace old one with
     * @return true If you successfully edit the value
     * @return false If list is null or if old value doesn't exit in a list
     */
    bool edit(list_t *list, int oldValue, int newValue);

    /**
     * @brief Function is used to get the number of nodes inside the linked list
     *
     * @param list The list to get the number of the elements
     * @return Null if error occurs else number of nodes
     */
    int getAmountOfData(list_t *list);

    /**
     * @brief Function is used to clear all nodes from the given list
     *
     * @param list you want to clear
     */
    void clear(list_t *list);

    /**
     * @brief Function to destroy the given list
     *
     * @param list you want to destroy
     */
    void destroy(list_t *&list);

}

#endif // !LIST_H