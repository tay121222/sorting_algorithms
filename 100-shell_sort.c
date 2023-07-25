#include <stddef.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		size_t i, j;
		int temp;

		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
