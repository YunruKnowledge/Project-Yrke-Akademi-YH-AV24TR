/**
 * @file list.h
 * @author Lazar Roksandic (roksandiclazar@gmail.com)
 * @brief Uniq Uncopyble, Movable Lined list for
 *        storing and restoring items of type int.
 * @version 0.1
 * @date 2025-01-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef LIST_H
#define LIST_H

class List
{
    struct Node
    {
        Node *next;
        int item;
    };

    Node *top;
    int elem_num;

public:
    /**
     * @brief Construct a new List object
     * 
     */
    List() : top{nullptr}, elem_num{0} {}

    /**
     * @brief Make the List uncopyble on initialization
     * 
     */
    List(const List &) = delete;

    /**
     * @brief Make the List uncopyble using operator
     * 
     * @return List& 
     */
    List &operator=(const List &) = delete;

    /**
     * @brief Make List movable
     * 
     * @param that is a list you want to move
     */
    List(List &&that) noexcept : top{that.top}, elem_num{that.elem_num} { that.clear(); }

    /**
     * @brief Make List movable
     * 
     * @param that is a list you want to move
     * @return List& moved values 
     */
    List &operator=(List &&that) noexcept
    {
        clear();

        elem_num = that.elem_num;
        top = that.top;

        that.clear();

        return *this;
    }

    /**
     * @brief Destroy the List object
     * 
     */
    ~List() {}

public:
    /**
     * @brief Function to stor items in the list
     *
     * @param item you want to store
     * @return true if you successfully stored the item
     * @return false if you couldn't store the item
     */
    bool insert(int item);

    /**
     * @brief Function to modify old items from the list
     * 
     * @param oldItem you want to modify
     * @param newItem you want to insert in the place of the old
     * @return true if you successfully modify old item
     * @return false if you couldn't modify old item
     */
    bool modify(int oldItem, int newItem);

    /**
     * @brief Function to remove item form the list
     * 
     * @param item you want to remove
     * @return true if you successfully removed the item
     * @return false if you couldn't remove the item
     */
    bool remove(int item);

    /**
     * @brief Function to search for the value
     * 
     * @param item you want to search for
     * @return int place where it is
     */
    int search(int item);

    /**
     * @brief Get the Size of the list
     * 
     * @return int size
     */
    int getSize(void) { return elem_num; }

    /**
     * @brief Sort the list
     * 
     */
    void sort(void);

    /**
     * @brief Swap to values
     * 
     * @param a to swap with b
     * @param b to swap with a
     */
    void swap(Node *a, Node *b);

    /**
     * @brief Function to print the list
     * 
     */
    void print(void);

    /**
     * @brief Function to clear the list
     * 
     */
    void clear(void);
};

#endif