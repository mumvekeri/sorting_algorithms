#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev = node1->prev;
	listint_t *next = node2->next;

	if (prev)
		prev->next = node2;
	else
        *list = node2;
	if (next)
		next->prev = node1;
	node2->prev = prev;
	node2->next = node1;
	node1->prev = node2;
	node1->next = next;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int swapped = 1;

	if (!list || !*list)
		return;

	while (swapped)
	{
		swapped = 0;
		curr = *list;
		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
	}
}
