# Queue

| Criteria               | 1P Queue (1 Pointer Queue)                                                                        | 2P Queue (2 Pointers Queue)                                                                                | Circular Queue                                                                                                   |
| ---------------------- | ------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| Space Utilized         | Efficient (✓)                                                                                     | Less Efficient (X)                                                                                         | Efficient (✓)                                                                                                    |
| Implemented With       | Arrays                                                                                            | Linked List                                                                                                | Arrays                                                                                                           |
| Server Moves           | No (X)                                                                                            | Yes (✓)                                                                                                    | Yes (✓)                                                                                                          |
| Baggage Moves          | Yes (✓)                                                                                           | No (X)                                                                                                     | No (X)                                                                                                           |
| Space Complexity       | O(n) - Requires space proportional to the number of elements                                      | O(n) - Requires space proportional to the number of elements                                               | O(n) - Requires space proportional to the number of elements                                                     |
| Time Complexity        |                                                                                                   |                                                                                                            |                                                                                                                  |
| - Enqueue              | O(1) - Adding an element at the end is constant time                                              | O(1) - Adding an element is constant time with two pointers                                                | O(1) - Adding an element is constant time                                                                        |
| - Dequeue              | O(1) - Removing an element from the front is constant time                                        | O(1) - Removing an element is constant time with two pointers                                              | O(1) - Removing an element is constant time                                                                      |
| Ease of Implementation | Simple - Easy to implement using arrays                                                           | Moderate - Requires handling two pointers and linked list structures                                       | Moderate - Requires managing the circular nature                                                                 |
| Examples               | - Docks<br>- Goods-to-man packing process<br>- Conveyor belt systems<br>- Loading/unloading docks | - Robotic picking systems<br>- Forklift routes in a warehouse<br>- Order picking by humans moving to items | - Circular conveyor belts<br>- Carousel storage systems<br>- Automated guided vehicles (AGVs) in a circular path |

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
