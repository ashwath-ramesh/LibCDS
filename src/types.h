/*
Program: include/libcds_types.h
Purpose: Define a fixed set of types that can be used to create various data structures such as arrays, queues.
*/

#ifndef LIBCDS_TYPES_H
#define LIBCDS_TYPES_H

#include <stdbool.h>
#include <stddef.h>

// Enum to define the type of elements in the array
typedef enum
{
    LIBCDS_TYPE_INT,
    LIBCDS_TYPE_CHAR,
    LIBCDS_TYPE_COUNT,
} libcds_type_t;

// Enum validation function
bool _is_valid_type(libcds_type_t type);

// Get type size function
size_t _get_type_size(libcds_type_t type);

#endif // LIBCDS_TYPES_H