#include "sort.h"

/**
 * cocktail_sort_list - sorts a list using the cocktail shaker algorithm
 * @list: list to sort
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list);
{
	size_t i = 0, j, swapped;

	if (size == 0 || array == NULL)
		return;
	do {
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				array[j] ^= array[j + 1];
				array[j + 1] ^= array[j];
				array[j] ^= array[j + 1];
				swapped = 1;
				print_array(array, size);
			}
		}
		i++;
	} while (swapped);
}
