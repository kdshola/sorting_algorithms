#include "sort.h"

/**
 * bubble_sort - sorts an array using the bubble sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
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
