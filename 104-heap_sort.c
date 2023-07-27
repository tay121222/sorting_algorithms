#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sift_down - Sift down the element at index start
 * @array: Pointer to the array
 * @size_init: Original size of the array
 * @size: Current size of the heap
 * @start: Index of the element to sift down
 */
void sift_down(int *array, size_t size_init, size_t size, size_t start)
{
	int temp;
	size_t i, branch1, branch2;

	while (start < size / 2)
	{
		branch1 = start * 2 + 1;
		branch2 = branch1 + 1;

		if (branch2 < size && array[branch2] > array[branch1])
			i = branch2;
		else
			i = branch1;

		if (array[i] <= array[start])
			break;

		temp = array[start];
		array[start] = array[i];
		array[i] = temp;
		print_array(array, size_init);

		start = i;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (!array || size <= 1)
		return;

	for (i = size / 2; (ssize_t)i > 0; i--)
		sift_down(array, size, size, i - 1);

	for (i = 0; i < size - 1; i++)
	{
		temp = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = temp;
		print_array(array, size);
		sift_down(array, size, size - i - 1, 0);
	}
}
