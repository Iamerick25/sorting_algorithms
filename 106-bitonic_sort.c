#include "sort.h"
#include <stdio.h>

void _bitonic_Merge(int *array, size_t low, size_t num, size_t dir);

/**
 * _bitonic_Sort - recursively split an array
 * @array: array to sort
 * @low: lower index of subarray
 * @num: number of elements to consider starting from `low`
 * @dir: direction of bitonic subsequence (1 is ascending, 0 is decreasing)
 * @size: size of `array`
 */
void _bitonic_Sort(int *array, size_t low, size_t num, size_t dir, size_t size)
{
	size_t i = num / 2;

	if (num > 1)
	{
		printf("%s [%lu/%lu] (%s):\n",
		       "Merging",
		       num, size,
		       dir ? "UP" : "DOWN");
		print_array(array + low, num);
		_bitonic_Sort(array, low, i, 1, size);
		_bitonic_Sort(array, low + i, i, 0, size);
		_bitonic_Merge(array, low, num, dir);
		printf("%s [%lu/%lu] (%s):\n",
		       "Result",
		       num, size,
		       dir ? "UP" : "DOWN");
		print_array(array + low, num);
	}
}

/**
 * _bitonic_Merge - merge subroutine to combine to bitonic sequences
 * @array: array on which to operate
 * @low: lower index of subarray
 * @num: number of elements in subarray to merge
 * @dir: direction of bitonic subsequence (1 is ascending, 0 is decreasing)
 */
void _bitonic_Merge(int *array, size_t low, size_t num, size_t dir)
{
	size_t i, j = num / 2;
	int count;

	if (num > 1)
	{
		for (i = low; i < low + j; i++)
		{
			if (!(dir ^ (array[i] > array[i + j])))
			{
				count = array[i];
				array[i] = array[i + j];
				array[i + j] = count;
			}
		}
		_bitonic_Merge(array, low, j, dir);
		_bitonic_Merge(array, low + j, j, dir);
	}
}

/**
 * bitonic_sort - recursive implementation of bitonic sort
 * @array: array to sort
 * @size: size of `array`
 */
void bitonic_sort(int *array, size_t size)
{
	_bitonic_Sort(array, 0, size, 1, size);
}
