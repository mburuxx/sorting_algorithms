#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a doubly linked list
 * of integers in ascending order using insertion sort alg.
 * @list: list to be sorted.
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->prev;

		while (temp != NULL && temp->n > current->n)
		{
			temp->next = current->next;

			if (current->next != NULL)
				current->next->prev = temp;

			current->next = temp;
			current->prev = temp->prev;

			if (temp->prev != NULL)
				temp->prev->next = current;
			temp->prev = current;

			if (current->prev == NULL)
				*list = current;
			/* print list after swapping */
			print_list(*list);

			temp = current->prev;
		}
		current = current->next;
	}
}
