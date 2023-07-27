#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_compare - Compares and merges two sub-arrays into a new array
 * @array: The integer array to sort
 * @start: The start index of the first sub-array
 * @mid: The index separating the two sub-arrays
 * @stop: The stop index of the second sub-array
 * @new: The output array to store the merged elements
 */
void merge_compare(int *array, size_t start, size_t mid, size_t stop, int *new)
{
	size_t i = start, j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);

	for (k = start; k < stop; k++)
	{
		if (i < mid && (j >= stop || array[i] <= array[j]))
		{
			new[k] = array[i++];
		}
		else
		{
			new[k] = array[j++];
		}
	}

	printf("[Done]: ");
	print_array(new + start, stop - start);
}

/**
 * merge_sort_top_down - Sorts an array recursively
 * @array: The integer array to sort
 * @start: The start index of the current sub-array
 * @stop: The stop index of the current sub-array
 * @new: The temp array to hold the sorted elements
 *
 * Return: void
 */
void merge_sort_top_down(int *array, size_t start, size_t stop, int *new)
{
	size_t mid;

	if (stop - start < 2)
	{
		return;
	}

	mid = (start + stop) / 2;
	merge_sort_top_down(new, start, mid, array);
	merge_sort_top_down(new, mid, stop, array);
	merge_compare(new, start, mid, stop, array);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: Pointer to input array
 * @size: Size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *new;
	size_t i;

	if (!array || size < 2)
		return;

	new = malloc(sizeof(int) * size);
	if (!new)
		return;

	for (i = 0; i < size; i++)
		new[i] = array[i];

	merge_sort_top_down(array, 0, size, new);
	free(new);
}
