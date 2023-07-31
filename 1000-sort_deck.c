#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

/**
 * _strcmp - Compares Strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: Difference of String
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * compare_cards - Custom comparison function for qsort
 * @a: Pointer to the first card node
 * @b: Pointer to the second card node
 *
 * Return: - value if a < b, + value if a > b
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *((const deck_node_t **)a);
	const deck_node_t *node_b = *((const deck_node_t **)b);
	int value_diff;
	int i, a_value = 0, b_value = 0;
	static const char *const values[] = {"Ace", "2", "3", "4",
		"5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
	{
		if (_strcmp(node_a->card->value, values[i]) == 0)
		{
			a_value = i + 1;
			break;
		}
	}
	for (i = 0; i < 13; i++)
	{
		if (_strcmp(node_b->card->value, values[i]) == 0)
		{
			b_value = i + 1;
			break;
		}
	}
	value_diff = a_value - b_value;
	if (value_diff != 0)
		return (value_diff);

	return (node_a->card->kind - node_b->card->kind);
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t i;
	deck_node_t *current = *deck;
	deck_node_t **nodes_array = malloc(sizeof(deck_node_t *) * 52);

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
	{
		free(nodes_array);
		return;
	}

	if (nodes_array == NULL)
		return;

	i = 0;

	while (current != NULL)
	{
		nodes_array[i] = current;
		current = current->next;
		i++;
	}

	qsort(nodes_array, 52, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < 51; i++)
	{
		nodes_array[i]->next = nodes_array[i + 1];
		nodes_array[i + 1]->prev = nodes_array[i];
	}

	nodes_array[0]->prev = NULL;
	nodes_array[51]->next = NULL;
	*deck = nodes_array[0];

	free(nodes_array);
}
