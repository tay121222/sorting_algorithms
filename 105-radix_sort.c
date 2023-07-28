#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_max - Returns the maximum element in the array
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Return: Maximum element in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Performs counting sort
 * @array: Pointer to the array
 * @size: Size of the array
 * @exp: The current digit's exponent (1, 10, 100, etc.)
 *
 * Return: void
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, *count, digit;
	size_t i;

	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * 10);

	if (!output || !count)
	{
		free(output);
		free(count);
		return;
	}

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (ssize_t)i >= 0; i--)
	{
		digit = (array[i] / exp) % 10;
		output[count[digit] - 1] = array[i];
		count[digit]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);

	free(output);
	free(count);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size <= 1)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_radix(array, size, exp);
}
