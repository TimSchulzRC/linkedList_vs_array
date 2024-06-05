//
// Created by Tim Schulz on 04.06.24.
//

#ifndef LINKEDLIST_VS_ARRAY_LINKED_LIST_H
#define LINKEDLIST_VS_ARRAY_LINKED_LIST_H

#endif //LINKEDLIST_VS_ARRAY_LINKED_LIST_H

typedef struct linked_list {
    struct linked_list *next;
    double value;
} linked_list;

linked_list* make_linked_list(double value);
void append_to_linked_list(linked_list** head, int value);
void free_linked_list(linked_list *head);
double get_from_linked_list(linked_list *head, int index);
void delete_from_linked_list(linked_list **head, int index);
void delete_last_from_linked_list(linked_list **head);
void delete_first_from_linked_list(linked_list **head);