#include <stddef.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in the list
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
 * tail_traverse_sort - Sorts a list of integers in ascending order
 * @head: head of the list
 * @list: pointer to the head of the list
 * @tail: tail of the current pass
 *
 * Return: new head
 */
listint_t *tail_traverse_sort(listint_t *head,
		listint_t *list, listint_t *tail)
{
	while (tail->prev && tail)
	{
		if (tail->n < tail->prev->n)
		{
			swap_nodes(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
			print_list(list);
		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}

/**
 * cocktail_sort_list - Sorts a list of integers in ascending order
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	int i = 0, j = 0;
	listint_t *head;
	listint_t *tail = NULL;
	listint_t *len;

	if (!list || !(*list) || !(*list)->next)
		return;

	head = *list;
	len = *list;

	while (len)
	{
		len = len->next;
		i++;
	}

	if (i < 2)
		return;

	while (j < i)
	{
		swapped = 0;
		while (head->next && head)
		{
			if (head->n > head->next->n)
			{
				swap_nodes(head, head->next);
				swapped++;
				if (head->prev->prev == NULL)
					*list = head->prev;
				print_list(*list);
			}
			else
				head = head->next;
			if (head->next == NULL)
				tail = head;
		}

		head = tail_traverse_sort(head, *list, tail);
		*list = head;
		j++;
	}
}
