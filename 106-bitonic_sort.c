#include "sort.h"

void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, int up);
void bitonic_compare(int *array, size_t size, int up);
void swap(int *array, int i, int j);

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	bitonic_merge(array, size, 1);
}

/**
 * bitonic_merge - recursively sorts a
 * bitonic sequence in ascending order
 * @array: pointer to the array to sort
 * @size: size of the array
 * @up: direction of sorting, 1 for up, 0 for down
 */
void bitonic_merge(int *array, size_t size, int up)
{
	if (size > 1)
	{
		size_t k = size / 2;

		printf("Merging [%lu/%lu] (%s):\n", size, size,
				(up ? "UP" : "DOWN"));
		print_array(array, size);
		bitonic_merge(array, k, 1);
		bitonic_merge(array + k, k, 0);
		bitonic_compare(array, size, up);
		printf("Result [%lu/%lu] (%s):\n", size, size,
				(up ? "UP" : "DOWN"));
		print_array(array, size);
	}
}

/**
 * bitonic_compare - compares and swaps elements in a bitonic sequence
 * @array: pointer to the array to sort
 * @size: size of the array
 * @up: direction of sorting, 1 for up, 0 for down
 */
void bitonic_compare(int *array, size_t size, int up)
{
	size_t k = size / 2;
	size_t i;

	for (i = 0; i < k; i++)
	{
		if ((up && array[i] > array[i + k]) || (!up && array[i] <
					array[i + k]))
		{
			swap(array, i, i + k);
			printf("Swapping [%d] and [%d]\n", array[i],
					array[i + k]);
		}
	}
	if (k > 1)
	{
		bitonic_compare(array, k, up);
		bitonic_compare(array + k, k, up);
	}
}

/**
 * swap - swaps two elements in an array
 * @array: pointer to the array
 * @i: index of the first element
 * @j: index of the second element
 */
void swap(int *array, int i, int j)
{
	int tmp = array[i];

	array[i] = array[j];
	array[j] = tmp;
}
