/*
Program: ./src/queue_arr1p.c
*/

#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "queue_arr1p.h"

// Initialise the queue
queue_arr1p_t *queue_arr1p_init(size_t size, size_t element_size)
{
    // Create a pointer to the queue in heap
    queue_arr1p_t *queue = calloc(1, sizeof(queue_arr1p_t));
    if (!queue)
        return NULL; // Memory alloc failed

    // Create the array of requested size that the queue pointer, points to.
    queue->array = calloc(size, element_size);
    if (!queue->array)
    {
        free(queue);
        return NULL;
    }

    queue->size = size;
    queue->rear = -1;
    queue->element_size = element_size;

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
int queue_arr1p_enq(queue_arr1p_t *queue, void *element)
{
    if (!queue)
        return QUEUE_NULL_POINTER;

    if (queue_arr1p_isFull(queue))
        return QUEUE_FULL;

    queue->rear++;
    void *dest = (char *)queue->array + (queue->rear * queue->element_size);
    memcpy(dest, element, queue->element_size);

    return QUEUE_SUCCESS;
}

// Dequeue
int queue_arr1p_deq(queue_arr1p_t *queue)
{
    if (!queue)
        return QUEUE_NULL_POINTER;

    // Check that queue is not empty
    if (queue_arr1p_isEmpty(queue))
        return QUEUE_EMPTY;

    // Dequeue
    for (int i = 0; i < queue->rear; i++)
    {
        void *dest = (char *)queue->array + (i * queue->element_size);
        void *src = (char *)queue->array + ((i + 1) * queue->element_size);
        memcpy(dest, src, queue->element_size);
    }
    queue->rear--;
    return QUEUE_SUCCESS;
}

// Is Queue Empty?
bool queue_arr1p_isEmpty(queue_arr1p_t *queue)
{
    if (!queue)
        return false;

    return (queue->rear == -1) ? true : false;
}

// Is Queue Full?
bool queue_arr1p_isFull(queue_arr1p_t *queue)
{
    if (!queue)
        return false;

    return (queue->rear == (ssize_t)(queue->size - 1)) ? true : false;
}

// Peek: Value at front
int queue_arr1p_peek(queue_arr1p_t *queue, void *element)
{
    if (!queue)
        return QUEUE_NULL_POINTER;

    // Check that queue is not empty
    if (queue_arr1p_isEmpty(queue))
        return QUEUE_EMPTY;

    // Copy the value at the front of the queue into the provided element pointer (since we dont know types we cant direcly return via function return)
    memcpy(element, queue->array, queue->element_size);

    return QUEUE_SUCCESS;
}

// Number of elements in the Queue
int queue_arr1p_cnt_elements(queue_arr1p_t *queue)
{
    if (!queue)
        return QUEUE_NULL_POINTER;

    return queue->rear + 1;
}