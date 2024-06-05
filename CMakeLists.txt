cmake_minimum_required(VERSION 3.28)
project(linkedList_vs_array C)

set(CMAKE_C_STANDARD 23)

add_executable(linkedList_vs_array main.c
        lib/linked_list.c
        lib/array_list.c
        lib/include/array_list.h
        lib/include/linked_list.h)
