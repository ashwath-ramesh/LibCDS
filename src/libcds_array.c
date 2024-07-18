/*
Program: src/libcds_array.c
*/

#include "libcds_array.h"
#include <stdlib.h>
#include <string.h>

// Initialization function
libcds_array_t *libcds_array_init(libcds_type_t type, size_t size)
{
    if (!_libcds_is_valid_type(type))
        return NULL; // Invalid type

    libcds_array_t *arr = malloc(sizeof(libcds_array_t));
    if (!arr)
        return NULL; // Memory allocation failed

    size_t element_size = _libcds_get_type_size(type);
    arr->A = malloc(size * element_size);
    if (!arr->A)
        return NULL; // Memory allocation failed

    arr->type = type;
    arr->size = size;
    arr->length = 0;

    return arr;
}

// Destruction function
void libcds_array_destroy(libcds_array_t *arr)
{
    if (arr != NULL)
    {
        free(arr->A);
        free(arr);
    }
}

// Enum validation function
bool _libcds_is_valid_type(libcds_type_t type)
{
    return (type >= 0 && type < LIBCDS_TYPE_COUNT);
}

// Get type size function
size_t _libcds_get_type_size(libcds_type_t type)
{
    switch (type)
    {
    case LIBCDS_TYPE_INT:
        return sizeof(int);
    case LIBCDS_TYPE_CHAR:
        return sizeof(char);
    default:
        return 0; // Invalid type
    }
}

// Append an element to the array
int append(libcds_array_t *arr, libcds_type_t type, void *element)
{
    if (!arr)
        return -1; // Invalid pointer

    if (!_libcds_is_valid_type(type))
        return -2; // Invalid type

    if (arr->type != type)
        return -4; // Type mismatch

    if (arr->length >= arr->size)
        return -3; // No more space in the array

    size_t element_size = _libcds_get_type_size(type);
    void *dest = (char *)arr->A + (arr->length * element_size);
    memcpy(dest, element, element_size);
    arr->length++;

    return 0;
}