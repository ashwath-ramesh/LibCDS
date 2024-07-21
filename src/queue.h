/*
Program: ./src/queue.h
Queue: Using (1) Arrays with 1 pointer (2) Arrays with 2 Pointers.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h> // For ssize_t

typedef enum
{
    QUEUE_SUCCESS = 0,
    QUEUE_NULL_POINTER = -1,
    QUEUE_FULL = -2,
    QUEUE_EMPTY = -3,
    QUEUE_MEMORY_ALLOC_FAILED = -4,
    QUEUE_POINTER_ERR = -5,
} queue_error_t;

typedef struct queue_arr1p
{
    void *array;
    ssize_t front;       // Front index.
    ssize_t rear;        // Rear index. `ssize_t` so it can be used with `size`
    size_t size;         // Size of the array
    size_t element_size; // Size of user-defined elements
} queue_t;

// Initialise the queue
queue_t *queue_init(size_t size, size_t element_size);

// Destroy the queue
void queue_destroy(queue_t *queue);

// Enqueue. Returns enum values above.
int queue_enqueue(queue_t *queue, void *element);

// Dequeue. Returns enum values above.
int queue_dequeue(queue_t *queue);

// Is Queue Empty?
bool queue_isEmpty(queue_t *queue);

// Is Queue Full?
bool queue_isFull(queue_t *queue);

// Peek: Value at front. Returns enum values above.
int queue_peek(queue_t *queue, void *element);

// Number of elements in the Queue
int queue_count_elements(queue_t *queue);

#endif // QUEUE_H