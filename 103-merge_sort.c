#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void _merge_split(int *array, int *display, size_t left, size_t right);
void _merge(int *array, int *display, size_t left, size_t index, size_t right);
void copy_display_to_input(int *array, int *display, size_t size);

/**
 * merge_sort - recursive merge sort algorithm using top down merge strategy
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *display;

	if (array == NULL || size <= 1)
		return;
	display = malloc(sizeof(array[0]) * size);
	if (!display)
		return;
	copy_display_to_input(display, array, size);
	_merge_split(display, array, 0, size);
	free(display);
}

/**
 * _merge_split - recursively called subroutine to split array and merge after
 * @temp: temporary array to store intermediate sorted subarrays
 * @array: unsorted input array
 * @left: left index of subarray
 * @right: right index of subarray (non-inclusive)
 */
void _merge_split(int *temp, int *array, size_t left, size_t right)
{
	size_t index;

	if (right - left <= 1)
		return;
	index = (right + left) / 2;
	_merge_split(array, temp, left, index);
	_merge_split(array, temp, index, right);
	_merge(temp, array, left, index, right);
}

/**
 * _merge - merge subroutine to merge sorted subarrays
 * @array: input array
 * @display: temporary array to store intermediate sorted subarrays
 * @left: left index of subarray
 * @index: indexpoint between two subarrays
 * @right: right endpoint of subarrays (non-inclusive)
 */
void _merge(int *array, int *display, size_t left, size_t index, size_t right)
{
	size_t i, j, k, n = right - left;

	i = left;
	j = index;
	printf("Merging...\n");
	printf("[left]: ");
	print_array((const int *) array + left, index - left);
	printf("[right]: ");
	print_array((const int *) array + index, right - index);
	for (k = 0; k < n; k++)
	{
		if (i < index && (j >= right || array[i] <= array[j]))
		{
			display[k + left] = array[i];
			i++;
		}
		else
		{
			display[k + left] = array[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array((const int *) display + left, n);
}

/**
 * copy_display_to_input - copy `display` to `array` of length `size`
 * @array: input array
 * @display: array to copy from
 * @size: size of `array`
 */
void copy_display_to_input(int *array, int *display, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		array[i] = display[i];
}
