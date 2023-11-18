#include "sort.h"

/**
 * get_max - gets the maximum element in an array
 * @array: pointer to the array
 * @size: size of the array
 * Return: the maximum element
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort_radix - sorts an array of integers in
 * ascending order using the
 * Counting sort algorithm for a specific digit
 * @array: pointer to the array
 * @size: size of the array
 * @exp: exponent of 10 to sort by
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, *count;
	size_t i, digit;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	count = malloc(sizeof(int) * 10);
	if (!count)
	{
		free(output);
		return;
	}
	for (i = 0; i < 10; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit] += 1;
	}
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size; i > 0; i--)
	{
		digit = (array[i - 1] / exp) % 10;
		output[count[digit] - 1] = array[i - 1];
		count[digit] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(count);
}

/**
 * radix_sort - sorts an array of integers in ascending order using the
 * Radix sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;
	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
