//
// Created by Tim Schulz on 04.06.24.
//

#include <stdlib.h>
#include "include/linked_list.h"

linked_list* make_linked_list(double value){
    struct linked_list *list = malloc(sizeof(linked_list));
    list->value = value;
    list->next = nullptr;
    return list;
}

void append_to_linked_list(linked_list** head, int value){
    linked_list* n = make_linked_list(value);
    if (*head == nullptr) {
        *head = n;
        return;
    }

    linked_list* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = n;
}

double get_from_linked_list(linked_list *head, int index){
    linked_list* temp = head;
    for (size_t i = 0; i < index; i++) {
        if (temp == nullptr) return 0;
        temp = temp->next;
    }
    return temp->value;
}

void delete_from_linked_list(linked_list **head, double key){
    linked_list* temp = *head;
    linked_list* prev = nullptr;

    if (temp != nullptr && temp->value == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != nullptr && temp->value != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    prev->next = temp->next;
    free(temp);
}

void delete_from_linked_list_at_index(linked_list** head, int index){
    linked_list* temp = *head;
    double value = get_from_linked_list(temp, index);
    delete_from_linked_list(head,value);
}

void delete_last_from_linked_list(linked_list **head){
    linked_list* temp = *head;
    linked_list* prev = nullptr;

    if (temp == nullptr) return;

    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == nullptr) {
        free(temp);
        *head = nullptr;
    } else {
        prev->next = nullptr;
        free(temp);
    }
}

void delete_first_from_linked_list(linked_list **head){
    linked_list* temp = *head;
    if (temp == nullptr) return;
    *head = temp->next;
    free(temp);
}

void free_linked_list(linked_list *head){
    linked_list* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        free(temp);
    }
}