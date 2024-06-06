#include <stdio.h>
#include "lib/include/array_list.h"
#include "lib/include/linked_list.h"
#include <time.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL));

    int elements_to_append = 100000;

    struct timespec start, end;



    array_list* al = make_array_list(0);

    // benchmark appending elements to arraylist
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < elements_to_append; i++) {
        append_to_array_list(al, i);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed_time = (end.tv_sec - start.tv_sec) +
                          (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time appending elements to arraylist: %.9f seconds\n", elapsed_time);

    // benchmark appending elements to linkedlist
    clock_gettime(CLOCK_MONOTONIC, &start);
    linked_list* ll = make_linked_list(0);
    for (int i = 1; i < elements_to_append; i++) {
        append_to_linked_list(&ll, i);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time appending elements to linkedlist: %.9f seconds\n", elapsed_time);

    printf("\n");

    // benchmark printing center element from arraylist
    clock_gettime(CLOCK_MONOTONIC, &start);
    printf("Center element from arraylist: %f\n", al->elements[5000]);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                          (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time printing center element from arraylist: %.9f seconds\n", elapsed_time);

    // benchmark printing center element from linkedlist
    clock_gettime(CLOCK_MONOTONIC, &start);
    printf("Center element from linkedlist: %f\n", get_from_linked_list(ll, 5000));
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time printing center element from linkedlist: %.9f seconds\n", elapsed_time);

    printf("\n");

    // benchmark changing random value in arraylist 10000 times
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 10000; i++) {
        al->elements[rand() % al->size] = 1.1;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time changing random value in arraylist 10000 times: %.9f seconds\n", elapsed_time);

    // benchmark changing random value in linkedlist 10000 times
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 10000; i++) {
        get_from_linked_list(ll, rand() % elements_to_append);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time changing random value in linkedlist 10000 times: %.9f seconds\n", elapsed_time);

    printf("\n");

    // benchmark deleting 1 element from arraylist
    clock_gettime(CLOCK_MONOTONIC, &start);
    delete_from_array_list(al, 5000);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                          (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time deleting center element from arraylist: %.9f seconds\n", elapsed_time);

    // benchmark deleting 1 element from linkedlist
    clock_gettime(CLOCK_MONOTONIC, &start);
    delete_from_linked_list(&ll, 5000);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time deleting center element from linkedlist: %.9f seconds\n", elapsed_time);

    printf("\n");

    // benchmark deleting last element from arraylist
    clock_gettime(CLOCK_MONOTONIC, &start);
    delete_from_array_list(al, al->size-1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time deleting last element from arraylist: %.9f seconds\n", elapsed_time);

    // benchmark deleting last element from linkedlist
    clock_gettime(CLOCK_MONOTONIC, &start);
    delete_last_from_linked_list(&ll);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time deleting last element from linkedlist: %.9f seconds\n", elapsed_time);

    printf("\n");

    // benchmark deleting first element from arraylist
    clock_gettime(CLOCK_MONOTONIC, &start);
    delete_from_array_list(al, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time deleting first element from arraylist: %.9f seconds\n", elapsed_time);

    // benchmark deleting first element from linkedlist
    clock_gettime(CLOCK_MONOTONIC, &start);
    delete_first_from_linked_list(&ll);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time deleting first element from linkedlist: %.9f seconds\n", elapsed_time);


    printf("\n\n");


    array_list* al2 = make_array_list(0);
    for (int i = 0; i < elements_to_append; i++) {
        append_to_array_list(al2, i);
    }

    linked_list* ll2 = make_linked_list(0);
    for (int i = 1; i < elements_to_append; i++) {
        append_to_linked_list(&ll2, i);
    }

    // benchmark deleting all elements from arraylist randomly
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < elements_to_append; i++) {
        delete_from_array_list(al2, rand() % al2->size);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time randomly deleting all elements from arraylist randomly: %.9f seconds\n", elapsed_time);

    // benchmark deleting all elements from linkedlist randomly
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < elements_to_append -1; i++) {
        delete_from_linked_list_at_index(&ll2, rand() % (elements_to_append - i));
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time randomly deleting all elements from linkedlist randomly: %.9f seconds\n", elapsed_time);

    printf("\n\nArraylist: ");
    printf("%zu",al2->size);

    int counter = 0;
    while(ll2->next != nullptr){
        counter++;
        ll2 = ll2->next;
    }

    printf("\n\nLinkedList: ");
    printf("%d",counter);

    // free memory
    free_array_list(al);
    free_linked_list(ll);
    free_array_list(al2);
    free_linked_list(ll2);

    return 0;
}
