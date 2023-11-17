#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	node2->prev = node1->prev;

	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node2->next = node1;
	node1->prev = node2;

	if (node2->prev == NULL)
		*list = node2;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		insert = current->next;

		while (current->prev && current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			print_list(*list);
		}
		current = insert;
	}
}
