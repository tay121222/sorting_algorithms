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
	int swapped = 1;
	int i = 0;
	listint_t *head = *list;
	listint_t *tail = NULL;
	listint_t *tmp = NULL;
	listint_t *len = *list;

	if (!list || !(*list) || !((*list)->next))
		return;
	    
	while (len)
	{
		len = len->next;
		i++;
	}

	if (i < 2)
		return;

	while (swapped)
	{
		swapped = 0;
		tmp = head;

		while (tmp->next != tail)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_nodes(tmp, tmp->next);
				swapped = 1;
				if (tmp->prev == NULL)
					*list = tmp;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		tail = tmp;

		if (!swapped)
			break;

		while (tail->prev != NULL)
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
	}
}
