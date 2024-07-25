/*
Program: /tests/utils/libcds_tests_logger.h
*/

#include <stdio.h>

// Logging function for structured output
void log_message(const char *level, const char *message) {
  printf("\n[%s] %s\n", level, message);
}
