#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * @list: A double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *x, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	x = (*list)->next;

	while (x != NULL)
	{
		tmp = x;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			tmp->prev->next = tmp->next;

			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;

			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;

			if (tmp->prev == NULL)
				*list = tmp;

			print_list(*list);
		}

		x = x->next;
	}
}
