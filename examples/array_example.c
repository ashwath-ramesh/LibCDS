// /*
// Program: examples/array_example.c
// */

// #include <stdio.h>
// #include "libcds_array.h"

// void display(libcds_array_t *arr)
// {
//     printf("\nElements of array are:\n");
//     for (size_t i = 0; i < arr->length; i++)
//     {
//         if (arr->type == LIBCDS_TYPE_INT)
//         {
//             printf("%d ", ((int *)arr->A)[i]);
//         }
//         else if (arr->type == LIBCDS_TYPE_CHAR)
//         {
//             printf("%c ", ((char *)arr->A)[i]);
//         }
//     }
//     printf("\n");
// }

// int main()
// {
//     // Initialize array
//     libcds_array_t *my_arr = libcds_array_init(LIBCDS_TYPE_INT, 10);
//     if (!my_arr)
//     {
//         printf("Failed to initialize array.\n");
//         return 1;
//     }

//     printf("Array type: %u Array Size: %zu Array Length: %zu\n", my_arr->type, my_arr->size, my_arr->length);
//     printf("Successfully initialized array.\n");

//     // Append an element to the array
//     int x = 42;
//     int result = append(my_arr, LIBCDS_TYPE_INT, &x);
//     if (result != 0)
//     {
//         printf("Failed to append element to the array. Error code: %d\n", result);
//         libcds_array_destroy(my_arr);
//         return 1;
//     }
//     printf("Successfully appended an int to the array.\n");

//     display(my_arr);

//     // Destroy array
//     libcds_array_destroy(my_arr);

//     return 0;
// }

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

void test_int_array()
{
    libcds_array_t *int_arr = libcds_array_init(LIBCDS_TYPE_INT, 10);
    if (!int_arr)
    {
        printf("Failed to initialize integer array.\n");
        return;
    }
    printf("Successfully initialized integer array. Type: %u, Size: %zu, Length: %zu\n", int_arr->type, int_arr->size, int_arr->length);

    for (int i = 0; i < 10; i++)
    {
        int result = libcds_array_append(int_arr, LIBCDS_TYPE_INT, &i);
        if (result != 0)
        {
            printf("Failed to append element %d to the integer array. Error code: %d\n", i, result);
            libcds_array_destroy(int_arr);
            return;
        }
    }
    printf("Successfully appended elements to the integer array.\n");
    display(int_arr);

    int overflow = 11;
    int result = libcds_array_append(int_arr, LIBCDS_TYPE_INT, &overflow);
    if (result == -3)
    {
        printf("Correctly identified that the integer array is full.\n");
    }
    else
    {
        printf("Error: Expected -3 but got %d\n", result);
    }

    libcds_array_destroy(int_arr);
}

void test_char_array()
{
    libcds_array_t *char_arr = libcds_array_init(LIBCDS_TYPE_CHAR, 5);
    if (!char_arr)
    {
        printf("Failed to initialize character array.\n");
        return;
    }
    printf("Successfully initialized character array. Type: %u, Size: %zu, Length: %zu\n", char_arr->type, char_arr->size, char_arr->length);

    char chars[] = {'a', 'b', 'c', 'd', 'e'};
    for (int i = 0; i < 5; i++)
    {
        int result = libcds_array_append(char_arr, LIBCDS_TYPE_CHAR, &chars[i]);
        if (result != 0)
        {
            printf("Failed to append element %c to the character array. Error code: %d\n", chars[i], result);
            libcds_array_destroy(char_arr);
            return;
        }
    }
    printf("Successfully appended elements to the character array.\n");
    display(char_arr);

    int invalid = 42;
    int result = libcds_array_append(char_arr, LIBCDS_TYPE_INT, &invalid);
    if (result == -4)
    {
        printf("Correctly identified type mismatch for character array.\n");
    }
    else
    {
        printf("Error: Expected -4 but got %d\n", result);
    }

    libcds_array_destroy(char_arr);
}

int main()
{
    test_int_array();
    test_char_array();
    return 0;
}
