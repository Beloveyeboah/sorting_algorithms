#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **act);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **act);

/**
 * swap_node_ahead - Swaps the node of the array
 * @list: pointer
 * @tail: pointer to the tail.
 * @act: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **act)
{
	listint_t *tmp = (*act)->next;

	if ((*act)->prev != NULL)
		(*act)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*act)->prev;
	(*act)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *act;
	else
		*tail = *act;
	(*act)->prev = tmp;
	tmp->next = *act;
	*act = tmp;
}

/**
 * swap_node_behind - Swap a node in a list
 * @list: pointer to the head
 * @tail: pointer to the tail of the doubly-linked list.
 * @act: pointer to the current swapping element
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **act)
{
	listint_t *tmp = (*act)->prev;

	if ((*act)->next != NULL)
		(*act)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*act)->next;
	(*act)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *act;
	else
		*list = *act;
	(*act)->next = tmp;
	tmp->prev = *act;
	*act = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked
 * @list: pointer to the head
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool check = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (check == false)
	{
		check = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				check = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				check = false;
			}
		}
	}
}
