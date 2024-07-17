#include <stdio.h>
#include "libcds_array.h"

int main()
{
    libcds_array_t *my_arr = libcds_array_init(LIBCDS_TYPE_INT, 10);
    if (!my_arr)
    {
        printf("Failed to initialize array.\n");
        return 1;
    }

    printf("%u %zu %zu", my_arr->type, my_arr->size, my_arr->length);

    libcds_array_destroy(my_arr);

    return 0;
}
