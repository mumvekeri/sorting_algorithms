#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

void bubble_sort(int *array, size_t size);
void swap(int *a, int *b);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap_int(int *a, int *b);
int partition(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_helper(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void counting_sort(int *array, size_t size);
void merge(int *array, size_t size, int *left, int *right, size_t middle);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
void swaps(int *array, size_t i, size_t j, size_t size);
void radix_sort(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);
int get_max(int *array, size_t size);

#endif /* _SORT_H_ */
