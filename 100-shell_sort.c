#include "sort.h"

/**
 * shell_sort - shell sorting algorithm using insertion sort on subarrays
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t sort, i, j, k;
	int temp;

	for (sort = 1; sort < size; sort = 3 * sort + 1)
		;
	for (sort /= 3; sort > 0; sort /= 3)
	{
		for (i = 0; i < sort; i++)
		{
			j = i;
			while (j < size - sort)
			{
				if (array[j] > array[j + sort])
				{
					temp = array[j];
					array[j] = array[j + sort];
					array[j + sort] = temp;
					for (k = j; k >= sort; k -= sort)
					{
					if (array[k] < array[k - sort])
					{
					temp = array[k];
					array[k] = array[k - sort];
					array[k - sort] = temp;
					}
					else
					break;
					}
				}
				else
					j += sort;
			}
		}
		print_array(array, size);

	}
}
