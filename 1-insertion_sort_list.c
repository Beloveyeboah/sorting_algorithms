#include "sort.h"

void _swap_node(listint_t **list, listint_t **a, listint_t *b);

/**
 * _swap_node - swaps the nodes of the list
 * @list: the integer list
 * @a: the node a
 * @b: node b
 * Return: swap values
 */
void _swap_node(listint_t **list, listint_t **a, listint_t *b)
{

	(*a)->next = b->next;
	if (b->next != NULL)
		b->next->prev = *a;
	b->prev = (*a)->prev;
	b->next = *a;
	if ((*a)->prev != NULL)
	{
		(*a)->prev->next = b;
	}
	else
		*list = b;
	(*a)->prev = b;
	*a = b->prev;
}

/**
 * insertion_sort_list - uses insertion algorithm sorting
 * @list: the list to be sorted
 * Return: anything
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter;
	listint_t *insert;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			_swap_node(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
