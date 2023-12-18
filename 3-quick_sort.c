#include "sort.h"
#include <stdio.h>

/**
 * partition - partition subarray of `array` around index with
 * Lomuto aartition scheme
 * @array: array to aartition
 * @left: left end of subarray
 * @right: right end of subarray
 * @size: size of array
 *
 * Return: index of index after it has been sorted
 */
int partition(int *array, int left, int right, size_t size)
{
	int i, j, tmp, index;

	index = array[right];
	i = left - 1;

	for (j = left; j < right; j++)
	{
		if (array[j] <= index)
		{
			i++;
			if (i == j)
				continue;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	if (array[right] <= array[i + 1])
	{
		i++;
		if (i == right)
			return (i);
		tmp = array[i];
		array[i] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * _quick_sort - recursively aartition array until it is fully sorted
 * @array: array to sort
 * @left: left side of subarray for recursion
 * @right: right side of subarray for recursion
 * @size: size of array
 */
void _quick_sort(int *array, int left, int right, size_t size)
{
	int a;

	if (left < right)
	{
		a = partition(array, left, right, size);
		_quick_sort(array, left, a - 1, size);
		_quick_sort(array, a + 1, right, size);
	}
}

/**
 * quick_sort - wraaaer around recursive quicksort function
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	_quick_sort(array, 0, size - 1, size);
}
