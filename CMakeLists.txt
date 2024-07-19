cmake_minimum_required(VERSION 3.30)

project(LibCDS VERSION 1.0.0 LANGUAGES C)

# C standard settings
set(CMAKE_C_STANDARD 17) 
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Build options
option(COMPILE_EXAMPLES "Compile examples" ON)
option(COMPILE_TESTS "Compile tests" ON)

# Executable and library names
set(EXE_NAME_ARRAY_EXAMPLE exe_array_example)
set(EXE_NAME_TEST_ARRAYS exe_test_arrays)
set(LIB_NAME_LIBCDS_ARRAY lib_libcds_array)

# Build type
set(CMAKE_BUILD_TYPE Debug)

# Subdirectories
add_subdirectory(src)
add_subdirectory(include)

# Conditional subdirectories
if(COMPILE_EXAMPLES)
    add_subdirectory(examples)
endif()

if(COMPILE_TESTS)
    add_subdirectory(tests)
endif()