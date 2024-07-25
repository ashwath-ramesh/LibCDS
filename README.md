# LibCDS

Data structures library, implemented in Standard C.

## Data Structures

This is a (work-in-progress) library of simple and easy to use, data structures for the C language.
No libraries used, except for the Standard C library.

| Category    | Data Structure                                    | Operations                                                                                                          | Implemented | Interface | Implementation     |
| ----------- | ------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------- | ----------- | --------- | ------------------ |
| Basic       | [Array](docs/arrays.md)                           | Initialize, Append, Insert, Delete, Swap, Linear Search, Binary Search, Get, Set, Max, Min, Sum, Reverse1, Reverse2 | WIP         | `array.h` | `array.c`          |
| Basic       | 2D Array                                          | Initialize, Insert, Delete, Search, Traverse                                                                        |             |           |                    |
| Basic       | Linked List                                       | Initialize, Insert, Delete, Search, Traverse                                                                        |             |           |                    |
| Basic       | Circular Linked List                              | Initialize, Insert, Delete, Search, Traverse                                                                        |             |           |                    |
| Basic       | Doubly Linked List                                | Initialize, Insert, Delete, Search, Traverse                                                                        |             |           |                    |
| Basic       | Circular Doubly Linked List                       | Initialize, Insert, Delete, Search, Traverse                                                                        |             |           |                    |
| Stack       | Stack (Array)                                     | Push, Pop, Peek, IsEmpty, IsFull                                                                                    |             |           |                    |
| Stack       | Stack (Linked List)                               | Push, Pop, Peek, IsEmpty                                                                                            |             |           |                    |
| Queue       | [Queue (Using Array + 1 Pointer)](docs/queue.md)  | Enqueue, Dequeue, Front, Rear, IsEmpty, IsFull, Peek, Count Elements                                                | Done        | `queue.h` | `queue_arr1p.c`    |
| Queue       | [Queue (Using Array + 2 Pointers)](docs/queue.md) | Enqueue, Dequeue, Front, Rear, IsEmpty, IsFull, Peek, Count Elements                                                | Done        | `queue.h` | `queue_arr2p.c`    |
| Queue       | [Circular Queue](docs/queue.md)                   | Enqueue, Dequeue, Front, Rear, IsEmpty, IsFull, Peek, Count Elements                                                | Done        | `queue.h` | `queue_circular.c` |
| Queue       | [Double-ended Queue (Deque)](docs/queue.md)       | InsertFront, InsertRear, DeleteFront, DeleteRear, GetFront, GetRear, IsEmpty, IsFull                                |             |           |                    |
| Queue       | [Priority Queue](docs/queue.md)                   | Insert, DeleteMax/DeleteMin, GetMax/GetMin                                                                          |             |           |                    |
| Trees       | Binary Tree                                       | Initialize, Insert, Delete, Search, Traverse (In-order, Pre-order, Post-order)                                      |             |           |                    |
| Trees       | Binary Search Tree                                | Initialize, Insert, Delete, Search, Traverse                                                                        |             |           |                    |
| Trees       | AVL Tree                                          | Initialize, Insert, Delete, Search, Rotate, Balance                                                                 |             |           |                    |
| Trees       | Red-Black Tree                                    | Initialize, Insert, Delete, Search, Rotate, Recolor                                                                 |             |           |                    |
| Trees       | B-Tree                                            | Initialize, Insert, Delete, Search, Split, Merge                                                                    |             |           |                    |
| Trees       | B+ Tree                                           | Initialize, Insert, Delete, Search, Split, Merge                                                                    |             |           |                    |
| Trees       | Trie (Prefix Tree)                                | Initialize, Insert, Search, Delete, Prefix Search                                                                   |             |           |                    |
| Trees       | Heap (Min and Max)                                | Initialize, Insert, Delete, Heapify, GetMin/GetMax                                                                  |             |           |                    |
| Graphs      | Adjacency Matrix                                  | Initialize, AddEdge, RemoveEdge, GetNeighbors                                                                       |             |           |                    |
| Graphs      | Adjacency List                                    | Initialize, AddEdge, RemoveEdge, GetNeighbors                                                                       |             |           |                    |
| Graphs      | BFS Algorithm                                     | Traverse                                                                                                            |             |           |                    |
| Graphs      | DFS Algorithm                                     | Traverse                                                                                                            |             |           |                    |
| Graphs      | Dijkstra's Algorithm                              | FindShortestPath                                                                                                    |             |           |                    |
| Graphs      | Prim's Algorithm                                  | FindMinimumSpanningTree                                                                                             |             |           |                    |
| Graphs      | Kruskal's Algorithm                               | FindMinimumSpanningTree                                                                                             |             |           |                    |
| Hash Tables | Hash Table (Open Addressing)                      | Initialize, Insert, Delete, Search                                                                                  |             |           |                    |
| Hash Tables | Hash Table (Chaining)                             | Initialize, Insert, Delete, Search                                                                                  |             |           |                    |
| Advanced    | Segment Tree                                      | Initialize, Update, RangeQuery                                                                                      |             |           |                    |
| Advanced    | Fenwick Tree (Binary Indexed Tree)                | Initialize, Update, PrefixSum                                                                                       |             |           |                    |
| Advanced    | Disjoint Set (Union-Find)                         | MakeSet, Find, Union                                                                                                |             |           |                    |
| Matrices    | Dense Matrix                                      | Initialize, Add, Subtract, Multiply, Transpose                                                                      |             |           |                    |
| Matrices    | Sparse Matrix (Array)                             | Initialize, Add, Multiply, Transpose                                                                                |             |           |                    |
| Matrices    | Sparse Matrix (Linked List)                       | Initialize, Add, Multiply, Transpose                                                                                |             |           |                    |
| Matrices    | Special Matrices (Diagonal, Triangular, etc.)     | Initialize, Add, Multiply                                                                                           |             |           |                    |

## Prerequisites

- C compiler (e.g., gcc, clang)
- Make

## Building and Running Tests

1. Clone the repository:

   ```
   git clone https://github.com/ashwath-ramesh/LibCDS.git
   cd LibCDS
   ```

2. Build and run queue tests:
   ```
   make build_test_queues_arr1p
   make run_test_queues_arr1p
   ```

## Using LibCDS in Your Project

Work-in-progress

## Motivation

> _What I cannot create, I do not understand. - Richard Feynman_
