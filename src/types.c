/*
Program: src/libcds_types.c
Purpose: xxx
*/

#include <stdbool.h>
#include <stddef.h>
#include "types.h"

// Enum validation function
bool _is_valid_type(libcds_type_t type)
{
    return (type >= 0 && type < LIBCDS_TYPE_COUNT);
}

// Get type size function
size_t _get_type_size(libcds_type_t type)
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
