#include <stddef.h>
#include <stdlib.h>
#include "include/array_list.h"

//
// Created by Tim Schulz on 04.06.24.
//

array_list *make_array_list(size_t initial_size) {
    array_list *list = malloc(sizeof(array_list));
    list->elements = malloc(initial_size* sizeof(double));
    list->size = 0;
    return list;
}

void free_array_list(array_list *list) {
    free(list->elements);
    free(list);
}

void append_to_array_list(array_list *list, double value) {
    list->size++;
    void* p = realloc(list->elements, list->size * sizeof(double));
    if(p == nullptr) abort();
    list->elements = p;
    list->elements[list->size-1] = value;
}

void insert_into_array_list(array_list *list, int index, double value) {
    list->size++;
    void* p = realloc(list->elements, list->size * sizeof(double));
    if(p == nullptr) abort();
    list->elements = p;
    for (size_t i = list->size - 1; i > index; i--) {
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[index] = value;
}

void delete_from_array_list(array_list *list, int index) {
    for (size_t i = index; i < list->size - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
}
