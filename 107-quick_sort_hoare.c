#include <stdio.h>
#include <stdlib.h>

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm with Hoare partition scheme
 * @array: pointer to the array of integers
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sort(array, 0, size - 1, size);
}

/**
 * hoare_sort - sorts a partition of an array using Hoare scheme
 * @array: pointer to the array of integers
 * @low: the lowest index of the partition
 * @high: the highest index of the partition
 * @size: the size of the array
 */
void hoare_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		hoare_sort(array, low, pivot, size);
		hoare_sort(array, pivot + 1, high, size);
	}
}

/**
 * hoare_partition - partitions an array using Hoare scheme
 * @array: pointer to the array of integers
 * @low: the lowest index of the partition
 * @high: the highest index of the partition
 * @size: the size of the array
 * Return: the final partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low - 1;
	j = high + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
		else
		{
			return (j);
		}
	}
}

/**
 * print_array - prints an array of integers
 * @array: pointer to the array of integers
 * @size: the size of the array
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("[");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("]\n");
}
