/*
Program: src/array.c
*/

#include "array.h"
#include <stdlib.h>
#include <string.h>

// Initialization function
array_t *array_init(size_t size, size_t element_size) {

  array_t *arr = malloc(sizeof(array_t));
  if (!arr)
    return NULL; // Memory allocation failed

  arr->A = malloc(size * element_size);
  if (!arr->A)
    return NULL; // Memory allocation failed

  arr->size = size;
  arr->length = 0;
  arr->element_size = element_size;

  return arr;
}

// Destruction function
void array_destroy(array_t *arr) {
  if (arr != NULL) {
    free(arr->A);
    free(arr);
  }
}

// Append an element to the array
int array_append(array_t *arr, void *element) {
  if (!arr)
    return ARRAY_ERROR_INVALID_POINTER; // Invalid pointer

  if (arr->length >= arr->size)
    return ARRAY_ERROR_FULL; // No more space in the array

  void *dest = (char *)arr->A + (arr->length * arr->element_size);
  memcpy(dest, element, arr->element_size);
  arr->length++;

  return 0;
}

// Insert an element at a specific index
int array_insert(array_t *arr, int index, void *element) {
  if (!arr)
    return ARRAY_ERROR_INVALID_POINTER; // Invalid pointer

  if (arr->length >= arr->size)
    return ARRAY_ERROR_FULL; // No more space in the array

  if (index < 0 || (size_t)index > arr->length)
    return ARRAY_ERROR_INDEX_OUT_OF_BOUNDS; // Index out of bounds

  // Shift elements to the right of the array
  for (int i = arr->length; i > index; i--) {
    void *dest = (char *)arr->A + (i * arr->element_size);
    void *src = (char *)arr->A + ((i - 1) * arr->element_size);
    memcpy(dest, src, arr->element_size);
  }

  // Insert element into the index
  void *dest = (char *)arr->A + (index * arr->element_size);
  memcpy(dest, element, arr->element_size);
  arr->length++;

  return 0;
}