#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: the doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *current;

	if (list == NULL)
		return;
	current = *list;
	while (current->next)
	{
		while (current->next && current->n > current->next->n)
		{
			tmp = current;
			if (current->prev)
				current->prev->next = tmp->next;
			current->next->prev = tmp->prev;
			current->prev = tmp->next;
			current->next = tmp->next->next;
			current->prev->next = tmp;
			if (current->next)
				current->next->prev = tmp;
			if (current->prev->prev == NULL)
				*list = current->prev;
			print_list(*list);
			current = *list;
			break;
			current = current->next;
		}
	}
}
