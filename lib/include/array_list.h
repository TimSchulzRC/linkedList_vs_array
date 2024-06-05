//
// Created by Tim Schulz on 04.06.24.
//

#ifndef LINKEDLIST_VS_ARRAY_ARRAY_LIST_H
#define LINKEDLIST_VS_ARRAY_ARRAY_LIST_H

#endif //LINKEDLIST_VS_ARRAY_ARRAY_LIST_H

typedef struct array_list {
    double *elements;
    size_t size;
} array_list;

array_list *make_array_list(size_t initial_capacity);
void free_array_list(array_list *list);
void append_to_array_list(array_list *list, double value);
void delete_from_array_list(array_list *list, int index);