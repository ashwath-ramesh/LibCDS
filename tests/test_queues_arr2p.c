/*
Program: /tests/queues/test_queues_arr2p.c
*/

#include <stdio.h>
#include "../src/queue.h"
#include "logger.h"

void log_queue_status(queue_t *queue, const char *action)
{
    char message[100];
    sprintf(message, "%s - Queue size: %zu, element_size: %zu, isFull: %d, isEmpty: %d", action, queue->size, queue->element_size, queue_isFull(queue), queue_isEmpty(queue));
    log_message("INFO", message);
}

void enqueue_elements(queue_t *queue, int *elements, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (queue_enqueue(queue, &elements[i]) == 0)
        {
            char message[100];
            sprintf(message, "Element inserted! Value at rear: %d", *((int *)queue->array + queue->rear));
            log_message("INFO", message);
        }
        else
        {
            log_message("ERROR", "Failed to enqueue element.");
        }
    }
}

void dequeue_elements(queue_t *queue, int count)
{
    for (int i = 0; i < count; i++)
    {
        int front_element;
        if (queue_peek(queue, &front_element) == 0)
        {
            if (queue_dequeue(queue) == 0)
            {
                char message[100];
                if (queue_isEmpty(queue))
                {
                    sprintf(message, "Value at front was: %d. Element dequeued. Queue is now empty.", front_element);
                }
                else
                {
                    sprintf(message, "Value at front was: %d. Element dequeued.", front_element);
                }
                log_message("INFO", message);
            }
            else
            {
                log_message("ERROR", "Failed to dequeue element.");
            }
        }
        else
        {
            log_message("ERROR", "Failed to peek front element.");
        }
    }
}

int main()
{
    // Test Initialization
    queue_t *queue = queue_init(5, sizeof(int));
    if (!queue)
    {
        log_message("ERROR", "Failed to initialize array.");
        return 1;
    }
    else
    {
        log_queue_status(queue, "Initialized array");
    }

    // Enqueue elements
    int elements[7] = {15, 25, 35, 45, 55, 65, 75};
    enqueue_elements(queue, elements, 7);

    // Dequeue elements
    dequeue_elements(queue, 5);

    // Final status check
    log_queue_status(queue, "Final status");

    // Destroy queue
    queue_destroy(queue);

    return 0;
}