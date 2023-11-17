#include "sort.h"

/**
 * swap_int - swaps the values of two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap_int(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * Author: Chidochashe Mumvekeri
 * Date: 17/11/2023
 *
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	
	if (array == NULL || size < 2)
		return;
	
	for (i = 0; i < (size - 1); i++)
	{
		min_index = i;
		
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			swap_int(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
