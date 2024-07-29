/*
Program: include/array.h
*/

#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef enum {
  ARRAY_SUCCESS = 0,
  ARRAY_ERROR_INVALID_POINTER = -1,
  ARRAY_ERROR_INVALID_TYPE = -2,
  ARRAY_ERROR_FULL = -3,
  ARRAY_ERROR_TYPE_MISMATCH = -4,
  ARRAY_ERROR_INDEX_OUT_OF_BOUNDS = -5
} array_return_code_t;

// Structure definition
typedef struct array {
  void *A;             // Pointer to the array
  size_t size;         // Total size of the array
  size_t length;       // Number of elements currently in the array
  size_t element_size; // Size of user-defined elements
} array_t;

// Initialization function
array_t *array_init(size_t size, size_t element_size);

// Destruction function
void array_destroy(array_t *arr);

// Append an element to the array
int array_append(array_t *arr, void *element);

// Insert an element at a specific index
int array_insert(array_t *arr, int index, void *element);

#endif // ARRAY_H