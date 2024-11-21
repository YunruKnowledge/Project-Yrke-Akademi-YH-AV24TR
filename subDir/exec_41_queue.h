/**
 * @file exec_41_queue.h
 * @author SkyThe (88000687+YunruKnowledge@users.noreply.github.com)
 * @brief Single instance queue module using a linked list to store
 * data of type int. 
 *
 * @version 1.0
 * @date 2024-11-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MODULE_EXEC41_QUEUE
#define MODULE_EXEC41_QUEUE

#include <stdbool.h>
#include <stdlib.h>

typedef struct QUEUE queue_t;

/**
 * @brief Allocates a queue, and returns it.
 *
 * @return queue_t* - `NULL` upon failure.
 */
queue_t *queueCreate(void);

/**
 * @brief Adds a value (as a node) to the queue.
 *
 * @param _queue Address of queue.
 * @param _value Value to put in queue.
 * @return `true` on success.
 */
bool queueAdd(queue_t *_queue, const int _value);

/**
 * @brief Reads the first node value and free from queue.
 *
 * @param _queue Address of queue.
 * @param _int_ptr Address to apply the value to.
 * @return `true` on success.
 */
bool queueRead(queue_t *_queue, int *_int_ptr);

/**
 * @brief List the amount of queued up nodes.
 *
 * @param _queue Address of queue.
 * @return size_t
 */
size_t queueCount(queue_t *_queue);

/**
 * @brief Free the queue from memory, including its nodes.
 *
 * @param _queue Address of queue.
 */
void queueFree(queue_t **_queue);

#endif