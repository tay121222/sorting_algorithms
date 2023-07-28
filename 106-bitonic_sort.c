#include "sort.h"
#include <stdio.h>

/**
 * _swap - change two values in ascending or descending order
 * @arr: array
 * @item1: item one
 * @item2: item two
 * @order: 1: ascending order, 0 descending order
 */
void _swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}

/**
 * _merge - sort bitonic sequences recursively in both orders
 * @arr: array
 * @low: first element
 * @nelements: elements number
 * @order: 1: ascending order, 0 descending order
 */
void _merge(int arr[], int low, int nelements, int order)
{
	int mid, i;

	if (nelements > 1)
	{
		mid = nelements / 2;
		for (i = low; i < low + mid; i++)
			_swap(arr, i, i + mid, order);
		_merge(arr, low, mid, order);
		_merge(arr, low + mid, mid, order);
	}
}

/**
 * _sort - bitonic sort algorithm implementation
 * @arr: array
 * @low: first element
 * @nelements: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array length
 */
void _sort(int arr[], int low, int nelements, int order, int size)
{
	int mid;

	if (nelements > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelements, size);
			print_array(&arr[low], nelements);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelements, size);
			print_array(&arr[low], nelements);
		}
		mid = nelements / 2;
		_sort(arr, low, mid, 1, size);
		_sort(arr, low + mid, mid, 0, size);
		_merge(arr, low, nelements, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelements, size);
			print_array(&arr[low], nelements);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelements, size);
			print_array(&arr[low], nelements);
		}
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * @arr: array
 * @size: array length
 */
void bitonic_sort(int *arr, size_t size)
{
	int order = 1;

	if (!arr || size < 2)
		return;
	_sort(arr, 0, size, order, size);
}
