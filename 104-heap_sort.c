#include "sort.h"

void create_Heap(int *, size_t);
void move_Down(int *, size_t, size_t, size_t);
void heap_sort(int *, size_t);

/**
 * create_Heap - take unsorted array and convert
 *
 * @array: array to convert
 * @size: size of array
 */
void create_Heap(int *array, size_t size)
{
	size_t index;

	if (!array || size < 2)
		return;
	index = size / 2;
	do {
		index--;
		move_Down(array, index, size, size);
	} while (index);
}

/**
 * move_Down - move index at index `index` in `heap` into correct position
 * @heap: heap structure to sift
 * @index: index of index to sift
 * @end: last index to consider
 * @size: size of heap
 */
void move_Down(int *heap, size_t index, size_t end, size_t size)
{
	int temp;
	size_t right, left, length;

	left = 2 * index + 1;
	right = 2 * index + 2;
	length = index;

	if (left < end && heap[left] > heap[length])
		length = left;
	if (right < end && heap[right] > heap[length])
		length = right;
	if (length != index)
	{
		temp = heap[index];
		heap[index] = heap[length];
		heap[length] = temp;
		print_array(heap, size);
		move_Down(heap, length, end, size);
	}
}

/**
 * heap_sort - implementation of heap sort algorithm on `array`
 * @array: array to sort
 * @size: size of `array`
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (array == NULL || size < 2)
		return;
	create_Heap(array, size);
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		move_Down(array, 0, i, size);
	}
}
