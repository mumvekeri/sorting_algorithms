#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two elements
 * @a: pointer to the first element
 * @b: pointer to the second element
 */
void swap(int *a, int *b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}
