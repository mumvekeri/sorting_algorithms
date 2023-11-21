#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: pointer to the array of integers
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_merge(array, size, 1);
}

/**
 * bitonic_merge - merges two subarrays in ascending order
 * @array: pointer to the array of integers
 * @size: size of the array
 * @dir: direction of sorting, 1 for ascending, 0 for descending
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	size_t i, j, half;
	int temp;

	if (size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", size, size, (dir ? "UP" : "DOWN"));
		print_array(array, size);

		half = size / 2;
		for (i = 0, j = half; i < half; i++, j++)
		{
			if ((array[i] > array[j]) == dir)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				printf("Result [%lu/%lu] (%s):\n", size, size, (dir ? "UP" : "DOWN"));
				print_array(array, size);
			}
		}

		bitonic_merge(array, half, dir);
		bitonic_merge(array + half, half, dir);
	}
}
