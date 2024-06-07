#include <stdio.h>
#include "lib/include/array_list.h"
#include "lib/include/linked_list.h"
#include <time.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL));

    int elements_to_insert= 100000;

    struct timespec start, end;

    // benchmark arraylist
    clock_gettime(CLOCK_MONOTONIC, &start);

    array_list* al = make_array_list(0);

    // insert random numbers into the array list at sorted positions
    for (int i = 0; i < elements_to_insert; i++) {
        double new_value = rand() % elements_to_insert;
        int currentIndex = 0;
        double currentElement = al->elements[currentIndex];
        while (currentElement < new_value && currentIndex < al->size) {
            currentIndex++;
            currentElement = al->elements[currentIndex];
        }
        insert_into_array_list(al, currentIndex, new_value);
    }

    // delete all numbers from the array list randomly
    for (int i = 0; i < elements_to_insert; i++) {
        delete_from_array_list(al, rand() % al->size);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time for arraylist: %.9f seconds\n", elapsed_time);


    // benchmark linkedlist
    clock_gettime(CLOCK_MONOTONIC, &start);

    double first_value = rand() % elements_to_insert;
    linked_list* ll = make_linked_list(first_value);

    for(int i = 0; i < elements_to_insert - 1; i++){
        double new_value = rand() % elements_to_insert;

        linked_list* temp = ll;
        int counter = 0;
        while(new_value > temp->value && temp->next != nullptr){
            temp = temp->next;
            counter++;
        }
        insert_into_linked_list(&ll, counter, new_value);
    }

    for (int i = 0; i < elements_to_insert - 1; i++) {
        delete_from_linked_list_at_index(&ll, rand() % (elements_to_insert - i));
    }


    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time for linked list: %.9f seconds\n", elapsed_time);

    // free memory
    free_array_list(al);
    free_linked_list(ll);

    return 0;
}
