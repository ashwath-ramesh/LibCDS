cmake_minimum_required(VERSION 3.30)

project(LibCDS VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17) 
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(COMPILE_EXAMPLES "Compile examples" ON)

set(EXE_NAME_ARRAY_EXAMPLE exe_array_example)
set(LIB_NAME_LIBCDS_ARRAY lib_libcds_array)

add_subdirectory(src)
add_subdirectory(include)
IF (COMPILE_EXAMPLES)
    add_subdirectory(examples)
ENDIF()