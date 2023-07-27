#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * count_array - Constructs the counting array
 * @array: Pointer to input array
 * @size: Size of the array
 * @max: Maximum value in array
 *
 * Return: Pointer to counting array
 */
int *count_array(int *array, size_t size, int max)
{
	int *counting_array = malloc(sizeof(int) * (max + 1));
	int i;
	size_t j;

	if (counting_array == NULL)
		return (NULL);

	for (j = 0; j < size; j++)
	{
		counting_array[array[j]]++;
	}

	for (i = 1; i < max; i++)
	{
		counting_array[i + 1] += counting_array[i];
	}

	print_array(counting_array, max + 1);

	return (counting_array);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * @array: Pointer to input array
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, *counting_array, *sorted_array;
	size_t j;

	if (array == NULL || size <= 1)
		return;

	max = array[0];
	for (j = 0; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	counting_array = count_array(array, size, max);
	if (counting_array == NULL)
		return;

	sorted_array = malloc(sizeof(int) * size);
	for (j = 0; j < size; j++)
	{
		counting_array[array[j]]--;
		sorted_array[counting_array[array[j]]] = array[j];
	}

	for (j = 0; j < size; j++)
	{
		array[j] = sorted_array[j];
	}

	free(sorted_array);
	free(counting_array);
}
