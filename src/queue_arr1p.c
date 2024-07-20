/*
Program: ./src/queue_arr1p.c
*/

#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "queue_arr1p.h"

// Initialise the queue
queue_arr1p_t *queue_arr1p_init(libcds_type_t type, size_t size)
{
    // Check type
    if (!_is_valid_type(type))
        return NULL; // Type invalid

    // Create a pointer to the queue in heap
    queue_arr1p_t *queue = calloc(1, sizeof(queue_arr1p_t));
    if (!queue)
        return NULL; // Memory alloc failed

    // Create the array of requested size that the queue pointer, points to.
    queue->array = calloc(size, _get_type_size(type));
    if (!queue->array)
        return NULL;

    queue->size = size;
    queue->rear = -1;

    return queue;
}

// Destroy the queue
void queue_arr1p_destroy(queue_arr1p_t *queue)
{
    if (queue != NULL)
    {
        free(queue->array);
        free(queue);
    }
}

// Enqueue
int queue_arr1p_enq(queue_arr1p_t *queue, libcds_type_t type, void *element)
{
    if (!queue)
        return -1;

    // Check if queue is full
    if (queue_arr1p_isFull(queue))
        return -2;

    // Enqueue
    queue->rear++;
    size_t element_size = _get_type_size(type);
    void *dest = (char *)queue->array + (queue->rear * element_size);
    memcpy(dest, element, element_size);

    return 0;
}

// Is Queue Full?
int queue_arr1p_isFull(queue_arr1p_t *queue)
{
    if (!queue)
        return -1;

    return (queue->rear == (queue->size - 1)) ? 1 : 0;
}