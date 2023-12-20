#include "sort.h"
#include <stdio.h>

/**
 * swap - swap integers at positions in an array
 * @array: array to swap positions
 * @i: left index
 * @j: right index
 */
void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * partition - partition subarray of an array
 * @array: array to partition
 * @left: left end of subarray
 * @right: right end of subarray
 * @size: size of array
 * Return: index of pivot after it has been sorted
 */
int partition(int *array, int left, int right, size_t size)
{
	int i, j, temp;

	if (left >= right)
		return (left);
	swap(array, left, right);
	print_array(array, size);
	temp = array[left];
	i = left;
	j = right + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] <= temp && i < right);

		do {
			j--;
		} while (array[j] > temp && j > i);

		if (i == j)
		{
			swap(array, i - 1, left);
			print_array(array, size);
			return (i - 1);
		}
		if (i == right && temp < array[right])
		{
			swap(array, left, right - 1);
			print_array(array, size);
			return (right - 1);
		}
		if (i == right && temp > array[right])
		{
			swap(array, left, right);
			print_array(array, size);
			return (right);
		}
		swap(array, i, j);
		print_array(array, size);
	}
}

/**
 * _quick_Sort - recursively partition array until it is fully sorted
 * @array: array to sort
 * @left: left side of subarray for recursion
 * @right: right side of subarray for recursion
 * @size: size of array
 */
void _quick_Sort(int *array, int left, int right, size_t size)
{
	int i;

	if (left < right)
	{
		i = partition(array, left, right, size);
		_quick_Sort(array, left, i - 1, size);
		_quick_Sort(array, i + 1, right, size);
	}
}

/**
 * quick_sort_hoare - wrapper around recursive quicksort function
 * @array: array to sort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_quick_Sort(array, 0, (int)(size - 1), size);
}
