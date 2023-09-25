#include "sort.h"

/**
 * insertion_sort_list - sorts a list in ascending order using insertion sort
 * @list: list to sort
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = *list, *swap;

	if (!list || *list == NULL)
		return;
	while (temp)
	{
		while (temp->next && (temp->n > temp->next->n))
		{
			swap = temp->next;
			swap->prev = temp->prev;
			temp->next = swap->next;
			if (swap->next)
			{
				swap->next->prev = temp;
			}
			if (temp->prev)
			{
				temp->prev->next = swap;
			}
			temp->prev = swap;
			swap->next = temp;
			if (!swap->prev)
				*list = swap;
			else
				temp = swap->prev;
			print_list(*list);
		}
		temp = temp->next;
	}
}
