#include <stdio.h>
#include "sort.h"

/**
 * _swap - Swaps two elements in an array
 * @array: Pointer to the array
 * @a: Index of the first element
 * @b: Index of the second element
 */
void _swap(int *array, ssize_t a, ssize_t b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}

/**
 * hoare_partition - Hoare partition scheme for Quick sort
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Size of the array
 *
 * Return: Index of the pivot element
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);

		_swap(array, i, j);
		print_array(array, size);
	}
}

/**
 * qs_recursive - Recursive function for Quick sort using Hoare partition
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Size of the array
 */
void qs_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);

		qs_recursive(array, low, pivot - 1, size);
		qs_recursive(array, pivot, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	qs_recursive(array, 0, size - 1, size);
}
