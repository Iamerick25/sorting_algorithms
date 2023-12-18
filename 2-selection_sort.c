#include "sort.h"

/**
 * selection_sort - Selection sort algorithm
 *
 * @array: array of integers to sort
 * @size: size of array
 *
 *Return: None
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index;
	int tmp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index])
				index = j;
		}
		if (array[index] != array[i])
		{
			tmp = array[index];
			array[index] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
