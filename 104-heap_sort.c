#include "sort.h"

/**
 * swaps - swaps two elements in an array
 * @array: pointer to the array
 * @i: index of the first element
 * @j: index of the second element
 * @size: size of the array
 */
void swaps(int *array, size_t i, size_t j, size_t size)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

/**
 * sift_down - repairs the heap whose root element is at index start
 * @array: pointer to the array
 * @start: index of the root element
 * @end: index of the last element
 * @size: size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root, child, left, right;

	root = start;
	while (root * 2 + 1 <= end)
	{
		left = root * 2 + 1;
		right = root * 2 + 2;
		child = left;
		if (child + 1 <= end && array[child] < array[child + 1])
			child = right;
		if (array[root] < array[child])
		{
			swaps(array, root, child, size);
			root = child;
		}
		else
			return;
	}
}

/**
 * heapify - creates a max heap from an array
 * @array: pointer to the array
 * @size: size of the array
 */
void heapify(int *array, size_t size)
{
	size_t start;

	start = (size - 2) / 2;
	while (1)
	{
		sift_down(array, start, size - 1, size);
		if (start == 0)
			break;
		start--;
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using the
 * Heap sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swaps(array, 0, end, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
