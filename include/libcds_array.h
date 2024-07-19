/*
Program: include/libcds_array.h
*/

#ifndef LIBCDS_ARRAY_H
#define LIBCDS_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

// Enum to define the type of elements in the array
typedef enum
{
    LIBCDS_TYPE_INT,
    LIBCDS_TYPE_CHAR,
    LIBCDS_TYPE_COUNT,
} libcds_type_t;

// Structure definition
typedef struct libcds_array
{
    void *A;            // Pointer to the array
    size_t size;        // Total size of the array
    size_t length;      // Number of elements currently in the array
    libcds_type_t type; // Type of elements in the array
} libcds_array_t;

// Initialization function
libcds_array_t *libcds_array_init(libcds_type_t type, size_t size);

// Destruction function
void libcds_array_destroy(libcds_array_t *arr);

// Append an element to the array
int libcds_array_append(libcds_array_t *arr, libcds_type_t type, void *element);

// Enum validation function
bool _libcds_is_valid_type(libcds_type_t type);

// Get type size function
size_t _libcds_get_type_size(libcds_type_t type);

#endif // LIBCDS_ARRAY_H