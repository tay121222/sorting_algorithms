#include <stddef.h>
#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: first integer to swap with b
 * @b: second integer to swap with a
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Performs Lomuto partition scheme for Quick sort
 * @array: The array to be sorted
 * @a: Index of the a element in the partition
 * @b: Index of the b element in the partition
 * @size: size of array
 *
 * Return: The index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int a, int b, size_t size)
{
	int pivot = array[b];
	int i = a - 1, j;

	for (j = a; j <= b - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != b)
	{
		swap(&array[i + 1], &array[b]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_lomuto - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @a: Index of the a element in the partition
 * @b: Index of the b element in the partition
 * @size: size of array
 */
void quick_sort_lomuto(int *array, int a, int b, size_t size)
{
	int pivot_idx;

	if (a < b)
	{
		pivot_idx = lomuto_partition(array, a, b, size);
		quick_sort_lomuto(array, a, pivot_idx - 1, size);
		quick_sort_lomuto(array, pivot_idx + 1, b, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_lomuto(array, 0, size - 1, size);
}
