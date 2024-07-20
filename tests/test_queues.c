/*
Program: /tests/queues/test_queues.c
*/

#include <stdio.h>
#include "../src/queue_arr1p.h"
#include "logger.h"

int main()
{
    // Test Initialization
    queue_arr1p_t *queue = queue_arr1p_init(LIBCDS_TYPE_INT, 5);
    if (!queue)
    {
        log_message("ERROR", "Failed to initialize array.");
    }
    else
    {
        char message[100];
        sprintf(message, "Successfully initialized array. Type: %u, Size: %d", queue->type, queue->size);
        log_message("INFO", message);
    }

    // Check if queue is full
    if (queue_arr1p_isFull(queue))
        log_message("INFO", "Queue is full!");
    else
        log_message("INFO", "Queue is not full!");

    // Enqueue
    int element = 85;
    if (queue_arr1p_enq(queue, LIBCDS_TYPE_INT, &element) == 0)
    {
        char message[100];
        sprintf(message, "Element inserted! Value at rear: %d", *((int *)queue->array + (queue->rear)));
        log_message("INFO", message);
    }
    else
    {
        log_message("INFO", "Houston, we have a problem enque-ing!");
    }

    element = 95;
    if (queue_arr1p_enq(queue, LIBCDS_TYPE_INT, &element) == 0)
    {
        char message[100];
        sprintf(message, "Element inserted! Value at rear: %d", *((int *)queue->array + (queue->rear)));
        log_message("INFO", message);
    }
    else
    {
        log_message("INFO", "Houston, we have a problem enque-ing!");
    }

    // Dequeue
    if (queue_arr1p_deq(queue) == 0)
        log_message("INFO", "Element dequed");
    else
        log_message("INFO", "Houston, we have a problem deque-ing!");

    // Check if queue is full
    if (queue_arr1p_isEmpty(queue))
        log_message("INFO", "Queue is Empty!");
    else
    {
        char message[100];
        sprintf(message, "Queue is not Empty! Value at rear: %d", *((int *)queue->array + (queue->rear)));
        log_message("INFO", message);
    }

    // Dequeue
    if (queue_arr1p_deq(queue) == 0)
        log_message("INFO", "Element dequed");
    else
        log_message("INFO", "Houston, we have a problem deque-ing!");

    // Check if queue is full
    if (queue_arr1p_isEmpty(queue))
        log_message("INFO", "Queue is Empty!");
    else
    {
        log_message("INFO", "Queue is not Empty!");
        char message[100];
        sprintf(message, "Value at rear: %d", *((int *)queue->array + (queue->rear)));
        log_message("INFO", message);
    }

    // Destroy queue
    queue_arr1p_destroy(queue);

    return 0;
}