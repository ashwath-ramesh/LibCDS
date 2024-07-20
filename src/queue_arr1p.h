/*
Program: ./src/queue_arr1p.h
Queue: Using Arrays & 1 pointer.
*/

#ifndef QUEUE_ARR1P_H
#define QUEUE_ARR1P_H

#include <stddef.h>
#include "types.h"

typedef struct libcds_queue_arr1p
{
    void *array;
    int rear;
    int size;
    libcds_type_t type;
} queue_arr1p_t;

// Initialise the queue
queue_arr1p_t *queue_arr1p_init(libcds_type_t type, size_t size);

// Destroy the queue
void queue_arr1p_destroy(queue_arr1p_t *queue);

// Enqueue
int queue_arr1p_enq(queue_arr1p_t *queue, libcds_type_t type, void *element);

// Dequeue
int queue_arr1p_deq(queue_arr1p_t *queue);

// Is Queue Empty?
int queue_arr1p_isEmpty(queue_arr1p_t *queue);

// Is Queue Full?
int queue_arr1p_isFull(queue_arr1p_t *queue);

// Number of elements in the Queue
int queue_arr1p_cnt_elements(queue_arr1p_t *queue);

#endif