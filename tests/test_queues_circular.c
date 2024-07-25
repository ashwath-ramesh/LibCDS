
/*
Program: /tests/queues/test_queues_circular.c

IMPORTANT: Circular Queue Capacity

In a circular queue implementation:
- If the queue array has size N, the maximum number of elements that can be
stored is N-1.
- The queue is considered full when it contains N-1 elements.
- The front pointer always points to an empty position, reserving one array
index.
- Front and rear pointers start at index 0 and only share the same index again
when the queue becomes empty.

This design allows distinction between full and empty states, preventing
ambiguity in queue operations.
*/

#include "../src/queue.h"
#include "logger.h"
#include <assert.h>
#include <stdio.h>

void log_queue_status(queue_t *queue, const char *action) {
  char message[100];
  sprintf(message,
          "%s - Queue size: %zu, element_size: %zu, isFull: %d, isEmpty: %d",
          action, queue->size, queue->element_size, queue_isFull(queue),
          queue_isEmpty(queue));
  log_message("INFO", message);

  // Display elements in the queue
  printf("\nElements in the queue: ");
  if (!queue_isEmpty(queue)) {
    ssize_t i = queue->front;
    do {
      i = (i + 1) % queue->size;
      printf("%d ", *((int *)queue->array + i));
    } while (i != queue->rear);
  }
  printf("\n");
}

void test_basic_operations() {
  printf("\n--- Test Case 1: Basic Operations ---\n");
  queue_t *queue = queue_init(5, sizeof(int));
  assert(queue != NULL);

  int elements[] = {10, 20, 30, 40, 50, 60};

  // Enqueue: 10, 20, 30
  for (int i = 0; i < 3; i++) {
    assert(queue_enqueue(queue, &elements[i]) == 0);
  }
  log_queue_status(queue, "After enqueuing 10, 20, 30");

  // Dequeue
  assert(queue_dequeue(queue) == 0);
  log_queue_status(queue, "After dequeuing");

  // Enqueue: 40, 50
  for (int i = 3; i < 5; i++) {
    assert(queue_enqueue(queue, &elements[i]) == 0);
  }
  log_queue_status(queue, "After enqueuing 40, 50");

  // Dequeue
  assert(queue_dequeue(queue) == 0);
  log_queue_status(queue, "After dequeuing");

  // Enqueue: 60
  assert(queue_enqueue(queue, &elements[5]) == 0);
  log_queue_status(queue, "After enqueuing 60");

  assert(queue_isFull(queue));
  assert(!queue_isEmpty(queue));

  queue_destroy(queue);
}

void test_fill_to_capacity() {
  printf("\n--- Test Case 2: Fill to Capacity ---\n");
  queue_t *queue = queue_init(3, sizeof(int));
  assert(queue != NULL);

  int elements[] = {1, 2, 3};

  // Enqueue: 1, 2
  for (int i = 0; i < 2; i++) {
    assert(queue_enqueue(queue, &elements[i]) == 0);
  }
  log_queue_status(queue, "After enqueuing 1, 2");

  // Queue should be full now
  assert(queue_isFull(queue));

  // Try to enqueue: 3
  assert(queue_enqueue(queue, &elements[2]) == QUEUE_FULL);
  log_queue_status(queue, "After trying to enqueue 3");

  // Queue should still be full
  assert(queue_isFull(queue));

  queue_destroy(queue);
}

void test_empty_queue_operations() {
  printf("\n--- Test Case 3: Empty Queue Operations ---\n");
  queue_t *queue = queue_init(4, sizeof(int));
  assert(queue != NULL);

  // Try to dequeue from an empty queue
  assert(queue_dequeue(queue) == QUEUE_EMPTY);
  log_queue_status(queue, "After trying to dequeue from empty queue");

  // Enqueue: 100
  int element = 100;
  assert(queue_enqueue(queue, &element) == 0);
  log_queue_status(queue, "After enqueuing 100");

  // Dequeue
  assert(queue_dequeue(queue) == 0);
  log_queue_status(queue, "After dequeuing");

  // Try to dequeue again
  assert(queue_dequeue(queue) == QUEUE_EMPTY);
  log_queue_status(queue, "After trying to dequeue from empty queue");

  assert(queue_isEmpty(queue));

  queue_destroy(queue);
}

void test_wraparound_behavior() {
  printf("\n--- Test Case 4: Wraparound Behavior ---\n");
  queue_t *queue = queue_init(3, sizeof(int));
  assert(queue != NULL);

  int elements[] = {5, 10, 15, 20};

  // Enqueue: 5, 10
  for (int i = 0; i < 2; i++) {
    assert(queue_enqueue(queue, &elements[i]) == 0);
  }
  log_queue_status(queue, "After enqueuing 5, 10");

  // Queue should be full now
  assert(queue_isFull(queue));

  // Dequeue once
  assert(queue_dequeue(queue) == 0);
  log_queue_status(queue, "After dequeuing once");

  // Enqueue: 15
  assert(queue_enqueue(queue, &elements[2]) == 0);
  log_queue_status(queue, "After enqueuing 15");

  // Queue should be full again
  assert(queue_isFull(queue));

  // Dequeue once more
  assert(queue_dequeue(queue) == 0);
  log_queue_status(queue, "After dequeuing again");

  // Enqueue: 20
  assert(queue_enqueue(queue, &elements[3]) == 0);
  log_queue_status(queue, "After enqueuing 20");

  // Queue should be full once more
  assert(queue_isFull(queue));

  // Check if front and rear pointers are correct
  // Note: The exact values may depend on your implementation
  // These assertions might need adjustment based on your specific
  // implementation
  assert(queue->front == 2);
  assert(queue->rear == 1);

  queue_destroy(queue);
}

void test_alternating_operations() {
  printf("\n--- Test Case 5: Alternating Operations ---\n");
  queue_t *queue = queue_init(2, sizeof(int));
  assert(queue != NULL);

  int elements[] = {1, 2, 3, 4};

  // Enqueue: 1
  assert(queue_enqueue(queue, &elements[0]) == 0);
  log_queue_status(queue, "After enqueuing 1");
  assert(queue_isFull(queue));

  // Dequeue
  assert(queue_dequeue(queue) == 0);
  log_queue_status(queue, "After dequeuing");
  assert(queue_isEmpty(queue));

  // Enqueue: 2
  assert(queue_enqueue(queue, &elements[1]) == 0);
  log_queue_status(queue, "After enqueuing 2");
  assert(queue_isFull(queue));

  // Try to enqueue: 3 (should fail)
  assert(queue_enqueue(queue, &elements[2]) == QUEUE_FULL);
  log_queue_status(queue, "After trying to enqueue 3");
  assert(queue_isFull(queue));

  // Dequeue
  assert(queue_dequeue(queue) == 0);
  log_queue_status(queue, "After dequeuing");
  assert(queue_isEmpty(queue));

  // Enqueue: 4
  assert(queue_enqueue(queue, &elements[3]) == 0);
  log_queue_status(queue, "After enqueuing 4");
  assert(queue_isFull(queue));

  // Dequeue
  assert(queue_dequeue(queue) == 0);
  log_queue_status(queue, "After dequeuing");
  assert(queue_isEmpty(queue));

  // Try to dequeue from empty queue
  assert(queue_dequeue(queue) == QUEUE_EMPTY);
  log_queue_status(queue, "After trying to dequeue from empty queue");
  assert(queue_isEmpty(queue));

  queue_destroy(queue);
}

int main() {
  test_basic_operations();
  test_fill_to_capacity();
  test_empty_queue_operations();
  test_wraparound_behavior();
  test_alternating_operations();

  printf("\nAll tests completed successfully!\n");
  return 0;
}