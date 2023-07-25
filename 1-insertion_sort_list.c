#include <stddef.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr != NULL)
	{
		ptr = curr->prev;

		while (ptr != NULL && ptr->n > curr->n)
		{
			if (ptr->prev != NULL)
				ptr->prev->next = curr;
			else
				*list = curr;
			curr->prev = ptr->prev;
			ptr->prev = curr;
			ptr->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = ptr;
			curr->next = ptr;
			ptr = curr->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}
