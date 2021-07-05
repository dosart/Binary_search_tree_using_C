cmake_minimum_required(VERSION 3.19)
project(Binary_search_tree C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_compile_options(
        -Werror

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wenum-compare
        -Wfloat-equal
        -Wredundant-decls
        -Wsign-conversion
)


add_executable(Binary_search_tree tests/main.c src/binary_tree.c include/binary_tree.h tests/tests.c tests/tests.h include/stack.h src/stack.c)