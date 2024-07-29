/*
Program: /tests/arrays/test_arrays.c
*/

#include "../src/array.h"
#include "logger.h"
#include <assert.h>
#include <stdio.h>

void log_array_status(array_t *arr, const char *action) {
  char message[100];
  sprintf(message, "%s - Array size: %zu, length: %zu, element_size: %zu",
          action, arr->size, arr->length, arr->element_size);
  log_message("INFO", message);

  printf("Elements in the array: ");
  for (size_t i = 0; i < arr->length; i++) {
    switch (arr->element_size) {
    case sizeof(char):
      printf("'%c' ", *((char *)arr->A + i));
      break;
    case sizeof(int):
      printf("%d ", *((int *)arr->A + i));
      break;
    case sizeof(double):
      printf("%.2f ", *((double *)arr->A + i));
      break;
    default:
      printf("0x");
      for (size_t j = 0; j < arr->element_size; j++) {
        printf("%02X", *((unsigned char *)arr->A + i * arr->element_size + j));
      }
      printf(" ");
    }
  }
  printf("\n");
}

void test_array_init() {
  printf("\n--- Test Case 1: Array Initialization ---\n");
  array_t *arr = array_init(5, sizeof(int));
  assert(arr != NULL);
  assert(arr->size == 5);
  assert(arr->length == 0);
  assert(arr->element_size == sizeof(int));
  log_array_status(arr, "After initialization");
  array_destroy(arr);

  // Test with different element size
  arr = array_init(3, sizeof(double));
  assert(arr != NULL);
  assert(arr->size == 3);
  assert(arr->length == 0);
  assert(arr->element_size == sizeof(double));
  log_message("INFO", "Initialization with double elements successful");
  array_destroy(arr);
}

void test_array_append() {
  printf("\n--- Test Case 2: Array Append ---\n");
  array_t *arr = array_init(3, sizeof(int));
  assert(arr != NULL);

  int elements[] = {10, 20, 30, 40};

  // Append elements
  for (int i = 0; i < 3; i++) {
    assert(array_append(arr, &elements[i]) == 0);
    log_array_status(arr, "After appending");
  }

  // Try to append when full
  assert(array_append(arr, &elements[3]) == ARRAY_ERROR_FULL);
  log_array_status(arr, "After trying to append to full array");

  array_destroy(arr);
}

void test_array_insert() {
  printf("\n--- Test Case 3: Array Insert ---\n");
  array_t *arr = array_init(5, sizeof(char));
  assert(arr != NULL);

  char elements[] = {'A', 'B', 'C', 'D', 'E', 'F'};

  // Insert elements
  assert(array_insert(arr, 0, &elements[0]) == 0); // Insert 'A' at index 0
  log_array_status(arr, "After inserting 'A' at index 0");

  assert(array_insert(arr, 1, &elements[1]) == 0); // Insert 'B' at index 1
  log_array_status(arr, "After inserting 'B' at index 1");

  assert(array_insert(arr, 1, &elements[2]) == 0); // Insert 'C' at index 1
  log_array_status(arr, "After inserting 'C' at index 1");

  assert(array_insert(arr, 3, &elements[3]) == 0); // Insert 'D' at index 3
  log_array_status(arr, "After inserting 'D' at index 3");

  // Try to insert at invalid index
  assert(array_insert(arr, 10, &elements[4]) ==
         ARRAY_ERROR_INDEX_OUT_OF_BOUNDS);
  log_array_status(arr, "After trying to insert at invalid index");

  // Try to insert when full
  assert(array_insert(arr, 2, &elements[4]) == 0); // Insert 'E' at index 2
  log_array_status(arr, "After inserting 'E' at index 2");

  assert(array_insert(arr, 0, &elements[5]) == ARRAY_ERROR_FULL);
  log_array_status(arr, "After trying to insert when full");

  array_destroy(arr);
}

void test_edge_cases() {
  printf("\n--- Test Case 4: Edge Cases ---\n");

  // Test with size 0
  array_t *arr = array_init(0, sizeof(int));
  assert(arr != NULL);
  assert(arr->size == 0);
  assert(arr->length == 0);
  log_array_status(arr, "Array with size 0");

  int element = 10;
  assert(array_append(arr, &element) == ARRAY_ERROR_FULL);
  log_array_status(arr, "After trying to append to size 0 array");

  array_destroy(arr);

  // Test with NULL array
  int dummy = 0;
  assert(array_append(NULL, &dummy) == ARRAY_ERROR_INVALID_POINTER);
  assert(array_insert(NULL, 0, &dummy) == ARRAY_ERROR_INVALID_POINTER);
  log_message("INFO", "NULL array checks passed");

  // Test with very large element size
  arr = array_init(1, 1024 * 1024); // 1 MB element size
  assert(arr != NULL);
  log_message("INFO", "Initialization with very large element size successful");
  array_destroy(arr);
}

int main() {
  test_array_init();
  test_array_append();
  test_array_insert();
  test_edge_cases();

  printf("\nAll tests completed successfully!\n");
  return 0;
}