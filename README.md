# Performance test linked list vs arraylist

This project demonstrates the performance differences between the linked list and the arraylist datastructures by
inserting random numbers at sorted positions and then removing all elements randomly.

## Results
From a theoretical standpoint the linked list is expected to perform better for insert and delete operations.
It only needs to traverse the list to a certain index once and can than insert or delete an element by just changing the 
links of the previous (and the inserted) element.
The arraylist on the other hand needs to shift every element after the given index one position
to the right or left to insert or delete an element, while having to reallocate memory every time the array gets bigger.

In practise thought the arraylist performs better than the linked list for insert and delete operations.
This is due to how both datastructures are stored in memory. The linked list is stored in a non-continuous way in memory
while the arraylist is stored in a continuous way. This means that the arraylist can make better use of the CPU's cache
what significantly improves performance. Getting the elements of the linked list at their different memory locations
causes a lot of cache misses what slows down traversing the list.