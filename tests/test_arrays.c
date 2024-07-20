/*
Program: /tests/arrays/test_arrays.c
*/

#include <stdio.h>
#include "../src/array.h"

// Logging function for structured output
void log_message(const char *level, const char *message)
{
    printf("[%s] %s\n", level, message);
}

// Display function
void display(array_t *arr)
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

// Test initialization
array_t *test_init_array(int type, size_t size)
{
    array_t *arr = array_init(type, size);
    if (!arr)
    {
        log_message("ERROR", "Failed to initialize array.");
    }
    else
    {
        char message[100];
        sprintf(message, "Successfully initialized array. Type: %u, Size: %zu, Length: %zu", arr->type, arr->size, arr->length);
        log_message("INFO", message);
    }
    return arr;
}

// Test appending elements
int test_append_elements(array_t *arr, void *elements, size_t count, size_t element_size)
{
    for (size_t i = 0; i < count; i++)
    {
        int result = array_append(arr, arr->type, (char *)elements + i * element_size);
        if (result != 0)
        {
            char message[100];
            sprintf(message, "Failed to append element at index %zu. Error code: %d", i, result);
            log_message("ERROR", message);
            return result;
        }
    }
    log_message("INFO", "Successfully appended elements to the array.");
    return 0;
}

// Test overflow handling
void test_overflow(array_t *arr, void *element)
{
    int result = array_append(arr, arr->type, element);
    if (result == -3)
    {
        log_message("INFO", "Correctly identified that the array is full.");
    }
    else
    {
        char message[100];
        sprintf(message, "Error: Expected -3 but got %d", result);
        log_message("ERROR", message);
    }
}

// Test type mismatch handling
void test_type_mismatch(array_t *arr, int type, void *element)
{
    int result = array_append(arr, type, element);
    if (result == -4)
    {
        log_message("INFO", "Correctly identified type mismatch for array.");
    }
    else
    {
        char message[100];
        sprintf(message, "Error: Expected -4 but got %d", result);
        log_message("ERROR", message);
    }
}

// Test integer array initialization
array_t *test_int_array_init()
{
    return test_init_array(LIBCDS_TYPE_INT, 10);
}

// Test integer array appending
void test_int_array_append(array_t *int_arr)
{
    int elements[10];
    for (int i = 0; i < 10; i++)
        elements[i] = i;
    if (test_append_elements(int_arr, elements, 10, sizeof(int)) != 0)
        return;
    display(int_arr);
}

// Test integer array overflow
void test_int_array_overflow(array_t *int_arr)
{
    int overflow = 11;
    test_overflow(int_arr, &overflow);
}

// Test character array initialization
array_t *test_char_array_init()
{
    return test_init_array(LIBCDS_TYPE_CHAR, 5);
}

// Test character array appending
void test_char_array_append(array_t *char_arr)
{
    char elements[] = {'a', 'b', 'c', 'd', 'e'};
    if (test_append_elements(char_arr, elements, 5, sizeof(char)) != 0)
        return;
    display(char_arr);
}

// Test character array type mismatch
void test_char_array_type_mismatch(array_t *char_arr)
{
    int invalid = 42;
    test_type_mismatch(char_arr, LIBCDS_TYPE_INT, &invalid);
}

// Test integer array
void test_int_array()
{
    array_t *int_arr = test_int_array_init();
    if (!int_arr)
        return;
    test_int_array_append(int_arr);
    test_int_array_overflow(int_arr);
    array_destroy(int_arr);
}

// Test character array
void test_char_array()
{
    array_t *char_arr = test_char_array_init();
    if (!char_arr)
        return;
    test_char_array_append(char_arr);
    test_char_array_type_mismatch(char_arr);
    array_destroy(char_arr);
}

int main()
{
    log_message("INFO", "---Starting integer array tests...");
    test_int_array();
    log_message("INFO", "Finished integer array tests.");

    log_message("INFO", "---Starting character array tests...");
    test_char_array();
    log_message("INFO", "Finished character array tests.");

    return 0;
}