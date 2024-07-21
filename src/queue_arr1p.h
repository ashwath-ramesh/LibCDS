/*
Program: ./src/queue_arr1p.h
Queue: Using Arrays & 1 pointer.
*/

#ifndef QUEUE_ARR1P_H
#define QUEUE_ARR1P_H

#include <stddef.h>
#include <stdbool.h>

typedef enum
{
    QUEUE_SUCCESS = 0,
    QUEUE_NULL_POINTER = -1,
    QUEUE_FULL = -2,
    QUEUE_EMPTY = -3,
    QUEUE_MEMORY_ALLOC_FAILED = -4,
} queue_error_t;

typedef struct queue_arr1p
{
    void *array;
    ssize_t rear;        // Rear index. `ssize_t` so that it can be used with `size`
    size_t size;         // Size of the array
    size_t element_size; // Size of user-defined elements
} queue_arr1p_t;

// Initialise the queue
queue_arr1p_t *queue_arr1p_init(size_t size, size_t element_size);

// Destroy the queue
void queue_arr1p_destroy(queue_arr1p_t *queue);

// Enqueue. Returns enum values above.
int queue_arr1p_enq(queue_arr1p_t *queue, void *element);

// Dequeue. Returns enum values above.
int queue_arr1p_deq(queue_arr1p_t *queue);

// Is Queue Empty?
bool queue_arr1p_isEmpty(queue_arr1p_t *queue);

// Is Queue Full?
bool queue_arr1p_isFull(queue_arr1p_t *queue);

// Peek: Value at front. Returns enum values above.
int queue_arr1p_peek(queue_arr1p_t *queue, void *element);

// Number of elements in the Queue
int queue_arr1p_cnt_elements(queue_arr1p_t *queue);

#endif