#include "sort.h"
/**
 * bubble_sort - a bubble sort algorithm.
 * @array: the array to be sorted.
 * @size: the array size.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped, tmp;

	if (array == NULL || size < 2)
		return;
	for (j = 0; j < size - 1; j++)
	{
		swapped = 0;
		for (i = 0; i < size - j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}
