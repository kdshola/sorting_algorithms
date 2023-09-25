#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sort an array using counting sort
 * @array: array to sort
 * @size: array size
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	size_t i, large_sz;
	int start, largest, *count_array = NULL, *temp = NULL;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	largest = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > largest)
			largest = array[i];
	}
	large_sz = largest + 1;
	count_array = calloc(large_sz, sizeof(int));
	if (!count_array)
	{
		free(temp);
		return;
	}
	for (i = 0; i < size; i++)
		++count_array[array[i]];
	for (i = 1; i < large_sz; i++)
		count_array[i] += count_array[i - 1];
	print_array(count_array, large_sz);
	for (start = size - 1; start >= 0; start--)
		temp[--count_array[array[start]]] = array[start];
	for (i = 0; i < size; i++)
		array[i] = temp[i];
	free(count_array);
	free(temp);
}
