/*
Program: ./src/queue_circular.c
*/

#include "queue.h"
#include <stdbool.h>
#include <stddef.h>
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
  queue->front = 0;
  queue->rear = 0;
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

// Enqueue. Returns enum values above.
int queue_enqueue(queue_t *queue, void *element) {
  if (!queue)
    return QUEUE_NULL_POINTER;

  if (queue_isFull(queue))
    return QUEUE_FULL;

  queue->rear = (queue->rear + 1) % (queue->size);
  void *dest = (char *)(queue->array) + (queue->rear * queue->element_size);
  memcpy(dest, element, queue->element_size);

  return QUEUE_SUCCESS;
}

// Dequeue. Returns enum values above.
int queue_dequeue(queue_t *queue) {

  if (!queue)
    return QUEUE_NULL_POINTER;

  if (queue_isEmpty(queue))
    return QUEUE_EMPTY;

  queue->front = (queue->front + 1) % (queue->size);

  return QUEUE_SUCCESS;
}

// Is Queue Empty?
bool queue_isEmpty(queue_t *queue) {
  if (queue->front == queue->rear)
    return true;

  return false;
}

// Is Queue Full?
bool queue_isFull(queue_t *queue) {
  if (queue->front == (ssize_t)((queue->rear + 1) % (queue->size)))
    return true;

  return false;
}