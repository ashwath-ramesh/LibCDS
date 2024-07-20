# Queue

- Queue
- Ciruclar Queue
- Priority Queue

## Queue ADT

- Space for storing elements
- Front for deletion
- Rear - for insertion

## Queue operations

- enqueue
- dequeue
- isEmpty
- isFull
- first
- last
- others: display, number of elements, etc

## Implement using

- Array
- Linked List

## Implementation using Array

- Using 1 pointer
- Using 2 pointers - front and rear

### Using 1 pointer

- rear pointer: intially at -1 (before index 0).
- insertion: at rear. O(1)
- deletion: remove first element. Move all elements to front. O(n)

### Using 2 pointer

- 2 pointers: front & rear. Both at -1.
- insertion: increment rear pointer. move rear to next location. insert element. O(1)
- deletion: increment front pointer. delete element. O(1). Front pointer needs to be **BEFORE** the first element!

- isEmpty: when front pointer = rear pointer (anywhere in the queue array)
- isFull: when rear pointer = size of array - 1. (This mean front pointer could be either at -1 or somewhere in the middle ... )

### Drawbacks (queue using array)

- isFull: Full size of array is not used if rear = end of array & front != -1. We cannot reuse the space of deleted elements. Every array location can only be used once! Queue can be full and empty at same time.

### Solution (to drawbacks)

- Resetting pointers: if queue becomes empty (front & rear have same index), then reinitialize pointers to -1.
- Circular queues
