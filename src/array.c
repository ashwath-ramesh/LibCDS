/*
Program: src/array.c
*/

#include <stdlib.h>
#include <string.h>
#include "array.h"

// Initialization function
array_t *array_init(libcds_type_t type, size_t size)
{
    if (!_is_valid_type(type))
        return NULL; // Invalid type

    array_t *arr = malloc(sizeof(array_t));
    if (!arr)
        return NULL; // Memory allocation failed

    size_t element_size = _get_type_size(type);
    arr->A = malloc(size * element_size);
    if (!arr->A)
        return NULL; // Memory allocation failed

    arr->type = type;
    arr->size = size;
    arr->length = 0;

    return arr;
}

// Destruction function
void array_destroy(array_t *arr)
{
    if (arr != NULL)
    {
        free(arr->A);
        free(arr);
    }
}

// // Enum validation function
// bool _libcds_is_valid_type(libcds_type_t type)
// {
//     return (type >= 0 && type < LIBCDS_TYPE_COUNT);
// }

// // Get type size function
// size_t _libcds_get_type_size(libcds_type_t type)
// {
//     switch (type)
//     {
//     case LIBCDS_TYPE_INT:
//         return sizeof(int);
//     case LIBCDS_TYPE_CHAR:
//         return sizeof(char);
//     default:
//         return 0; // Invalid type
//     }
// }

// Append an element to the array
int array_append(array_t *arr, libcds_type_t type, void *element)
{
    if (!arr)
        return -1; // Invalid pointer

    if (!_is_valid_type(type))
        return -2; // Invalid type

    if (arr->type != type)
        return -4; // Type mismatch

    if (arr->length >= arr->size)
        return -3; // No more space in the array

    // TODO: any checks on element required?

    size_t element_size = _get_type_size(type);
    void *dest = (char *)arr->A + (arr->length * element_size);
    memcpy(dest, element, element_size);
    arr->length++;

    return 0;
}

// Insert an element at a specific index
int array_insert(array_t *arr, int index, void *element)
{
    if (!arr)
        return -1; // Invalid pointer

    if (arr->length >= arr->size)
        return -3; // No more space in the array

    // TODO: type checks to ensure that element type can be converted without loss of info.

    if (index < 0 || index > arr->length)
        return -5; // Index out of bounds

    // Shift elements to the right of the array
    size_t element_size = _get_type_size(arr->type);
    for (int i = arr->length; i > index; i--)
    {
        void *dest = (char *)arr->A + (i * element_size);
        void *src = (char *)arr->A + ((i - 1) * element_size);
        memcpy(dest, src, element_size);
    }

    // Insert element into the index
    void *dest = (char *)arr->A + (index * element_size);
    memcpy(dest, element, element_size);
    arr->length++;

    return 0;
}