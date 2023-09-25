#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort algorithm
 * @array: array to sort
 * @size: array size
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (!array || size == 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			array[min_index] ^= array[i];
			array[i] ^= array[min_index];
			array[min_index] ^= array[i];
			print_array(array, size);
		}
	}
}
