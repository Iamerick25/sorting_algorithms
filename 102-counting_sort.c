#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void print_array_long(const size_t *, size_t);

/**
 * countining_sort - indexing sort
 * @array: array to evaluate
 * @size: size of array
 * Return: None
 */
void counting_sort(int *array, size_t size)
{
	int input = 0, *output;
	size_t i, j, temp = 0, *index;

	if (array == NULL || size <= 1)
		return;
	input = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > input)
			input = array[i];
	j = (size_t)input;
	index = malloc(sizeof(size_t) * (j + 1));
	if (index == NULL)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(index);
		return;
	}
	for (i = 0; i <= j; i++)
		index[i] = 0;
	for (i = 0; i < size; i++)
		output[i] = 0;
	for (i = 0; i < size ; i++)
		index[array[i]]++;
	for (i = 1; i <= j; i++)
	{
		temp = index[i - 1];
		index[i] = temp + index[i];
	}
	print_array_long((const size_t *)index, j + 1);
	for (i = 0; i < size; i++)
	{
		output[index[array[i]] - 1] = array[i];
		index[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(index);
	free(output);
}

/**
 * print_array_long - prints array of size_t
 * @arr: array to print
 * @size: size of `arr`
 */
void print_array_long(const size_t *arr, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%lu", arr[i]);
	}
	putchar('\n');
}
