#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

/**
 * swap - swaps two elements
 * @a: pointer to the first element
 * @b: pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp;

	if (a == NULL || b == NULL)
		return;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: pointer to the array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, last;
	bool swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0, last = size - 1; i < last; i++)
	{
		swapped = false;

		for (j = 0; j < last - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
				last = j;

				print_array(array, size);
			}
		}
		if (swapped == false)
			break;
	}
}
