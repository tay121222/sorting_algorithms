#include <stddef.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in the list
 * @list: Pointer to the head of the list
 * @a: Pointer to the first node to be swapped
 * @b: Pointer to the second node to be swapped
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - Sorts a list of integers in ascending order
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped, i;
	listint_t *head, *tail, *tmp, *len;

	if (!list || !*list)
		return;

	len = *list;
	for (i = 0; len; i++)
	{
		len = len->next;
	}
	if (i < 2)
		return;

	head = *list;
	for (i = 0; i < 2; i++)
	{
		swapped = 0;
		for (tmp = head; tmp->next != tail; tmp = tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_nodes(tmp, tmp->next);
				swapped++;
				if (tmp->prev == NULL)
					*list = tmp;
				print_list(*list);
			}
		}
		if (!swapped)
			break;

		tail = tmp;

		while (tail && tail->prev)
		{
			if (tail->n < tail->prev->n)
			{
				swap_nodes(tail->prev, tail);
				if (tail->prev == NULL)
					*list = tail;
				print_list(*list);
			}
			else
				tail = tail->prev;
			if (tail->prev == NULL)
				head = tail;
		}
		*list = head;
	}
}
