#include <stdlib.h>
#include "sort.h"
#define NUMDIGIT 10

/**
 * max_value - find the max value in an array
 * @array: array to check
 * @size: size of `array`
 *
 * Return: number of significant digits of max value in `array`
 */
size_t max_value(int *array, size_t size)
{
	size_t i, base;
	int max = array[0];

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	for (base = 0; max > 0; max /= 10)
		base++;
	return (base);
}

/**
 * radix_sort - sorts data using Radix and prints it out
 * @array: data to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t digit, div, base, i, tmp, j, count[NUMDIGIT];
	int *output;

	if (array == NULL || size < 2)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	for (i = 0; i < NUMDIGIT; i++)
		count[i] = 0;
	base = max_value(array, size);
	for (j = 0, div = 1; j < base; j++, div *= 10)
	{
		for (i = 0; i < size; i++)
		{
			digit = (array[i] / div) % 10;
			count[digit]++;
		}
		for (i = 1; i < NUMDIGIT; i++)
		{
			tmp = count[i - 1];
			count[i] = tmp + count[i];
		}
		for (i = size; i > 0; i--)
		{
			digit = (array[i - 1] / div) % 10;
			output[count[digit] - 1] = array[i - 1];
			count[digit]--;
		}
		for (i = 0; i < size; i++)
			array[i] = output[i];
		for (i = 0; i < NUMDIGIT; i++)
			count[i] = 0;
		print_array(array, size);
	}
	free(output);
}
