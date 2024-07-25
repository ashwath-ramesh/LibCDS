/*
Program: ./src/queue_arr2p.c
*/

#include "queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialise the queue
queue_t *queue_init(size_t size, size_t element_size) {
  // Create a pointer to the queue in heap
  queue_t *queue = calloc(1, sizeof(queue_t));
  if (!queue)
    return NULL; // Memory alloc failed

  // Create the array of requested size that the queue pointer, points to.
  queue->array = calloc(size, element_size);
  if (!queue->array) {
    free(queue);
    return NULL;
  }

  queue->size = size;
  queue->front = -1; // Initialized but unused in 1P implementation.
  queue->rear = -1;
  queue->element_size = element_size;

  return queue;
}

// Destroy the queue
void queue_destroy(queue_t *queue) {
  if (queue != NULL) {
    free(queue->array);
    free(queue);
  }
}

// Enqueue
int queue_enqueue(queue_t *queue, void *element) {
  if (!queue)
    return QUEUE_NULL_POINTER;

  if (queue_isFull(queue))
    return QUEUE_FULL;

  queue->rear++;
  void *dest = (char *)queue->array + (queue->rear * queue->element_size);
  memcpy(dest, element, queue->element_size);

  return QUEUE_SUCCESS;
}

// Dequeue
int queue_dequeue(queue_t *queue) {
  if (!queue)
    return QUEUE_NULL_POINTER;

  // Check that queue is not empty
  if (queue_isEmpty(queue))
    return QUEUE_EMPTY;

  queue->front++;
  return QUEUE_SUCCESS;
}

// Is Queue Empty?
bool queue_isEmpty(queue_t *queue) {
  if (!queue)
    return false;

  if (queue->rear == -1)
    return true;
  else if (queue->front == queue->rear)
    return true;

  return false;
}

// Is Queue Full?
bool queue_isFull(queue_t *queue) {
  if (!queue)
    return false;

  return (queue->rear == (ssize_t)(queue->size - 1)) ? true : false;
}

// Peek: Value at front
int queue_peek(queue_t *queue, void *element) {
  if (!queue)
    return QUEUE_NULL_POINTER;

  // Check that queue is not empty
  if (queue_isEmpty(queue))
    return QUEUE_EMPTY;

  // Copy the value at the front of the queue into the provided element pointer
  // (since we dont know types we cant direcly return via function return)
  void *src = (char *)queue->array + ((queue->front + 1) * queue->element_size);
  memcpy(element, src, queue->element_size);

  return QUEUE_SUCCESS;
}

// Number of elements in the Queue
int queue_count_elements(queue_t *queue) {
  if (!queue)
    return QUEUE_NULL_POINTER;

  if (queue->front > queue->rear)
    return QUEUE_POINTER_ERR;

  if (queue->front == -1)
    return queue->rear + 1;
  else if ((queue->front + 1) == (ssize_t)(queue->size))
    return 0;
  else if (queue->front < queue->rear)
    return queue->rear - queue->front;
  else
    return 0;
}