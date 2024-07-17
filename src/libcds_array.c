#include "libcds_array.h"
#include <stdlib.h>

bool libcds_is_valid_type(libcds_type_t type)
{
    return (type >= 0 && type < LIBCDS_TYPE_COUNT);
}

size_t libcds_get_type_size(libcds_type_t type)
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

libcds_array_t *libcds_array_init(libcds_type_t type, size_t size)
{
    if (!libcds_is_valid_type(type))
        return NULL; // Invalid type

    libcds_array_t *arr = malloc(sizeof(libcds_array_t));
    if (!arr)
        return NULL; // Memory allocation failed

    size_t element_size = libcds_get_type_size(type);
    arr->A = malloc(size * element_size);
    if (!arr->A)
        return NULL; // Memory allocation failed

    arr->type = type;
    arr->size = size;
    arr->length = 0;

    return arr;
}

void libcds_array_destroy(libcds_array_t *arr)
{
    if (arr != NULL)
    {
        free(arr->A);
        free(arr);
    }
}