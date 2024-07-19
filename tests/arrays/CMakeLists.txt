add_executable(${EXE_NAME_TEST_ARRAYS} "test_arrays.c")
target_link_libraries(${EXE_NAME_TEST_ARRAYS} PUBLIC ${LIB_NAME_LIBCDS_ARRAY})