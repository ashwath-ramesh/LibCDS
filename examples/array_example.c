/*
Program: examples/array_example.c
*/

#include <stdio.h>
#include "libcds_array.h"

void display(libcds_array_t *arr)
{
    printf("\nElements of array are:\n");
    for (size_t i = 0; i < arr->length; i++)
    {
        if (arr->type == LIBCDS_TYPE_INT)
        {
            printf("%d ", ((int *)arr->A)[i]);
        }
        else if (arr->type == LIBCDS_TYPE_CHAR)
        {
            printf("%c ", ((char *)arr->A)[i]);
        }
    }
    printf("\n");
}

int main()
{
    // Initialize array
    libcds_array_t *my_arr = libcds_array_init(LIBCDS_TYPE_INT, 10);
    if (!my_arr)
    {
        printf("Failed to initialize array.\n");
        return 1;
    }

    printf("Array type: %u Array Size: %zu Array Length: %zu\n", my_arr->type, my_arr->size, my_arr->length);
    printf("Successfully initialized array.\n");

    // Append an element to the array
    int x = 42;
    int result = append(my_arr, LIBCDS_TYPE_INT, &x);
    if (result != 0)
    {
        printf("Failed to append element to the array. Error code: %d\n", result);
        libcds_array_destroy(my_arr);
        return 1;
    }
    printf("Successfully appended an int to the array.\n");

    display(my_arr);

    // Destroy array
    libcds_array_destroy(my_arr);

    return 0;
}
