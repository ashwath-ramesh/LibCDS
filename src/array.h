/*
Program: include/libcds_array.h
*/

#ifndef LIBCDS_ARRAY_H
#define LIBCDS_ARRAY_H

#include <stddef.h>
#include <stdbool.h>
#include "types.h"

// Structure definition
typedef struct array
{
    void *A;            // Pointer to the array
    size_t size;        // Total size of the array
    size_t length;      // Number of elements currently in the array
    libcds_type_t type; // Type of elements in the array
} array_t;

// Initialization function
array_t *array_init(libcds_type_t type, size_t size);

// Destruction function
void array_destroy(array_t *arr);

// Append an element to the array
int array_append(array_t *arr, libcds_type_t type, void *element);

// Insert an element at a specific index
int array_insert(array_t *arr, int index, void *element);

#endif // LIBCDS_ARRAY_H