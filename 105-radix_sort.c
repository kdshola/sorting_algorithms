#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sort an array using counting sort
 * @array: array to sort
 * @size: array size
 * Return: nothing
 */
void _counting_sort(int *array, size_t size)
{
	static int exponent = 1;
	size_t i;
	int start, *count_array = NULL, *temp = NULL;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	count_array = calloc(size, sizeof(int));
	if (!count_array)
	{
		free(temp);
		return;
	}
	for (i = 0; i < size; i++)
		++count_array[(array[i] / exponent) % 10];
	for (i = 1; i < size; i++)
		count_array[i] += count_array[i - 1];
	for (start = size - 1; start >= 0; start--)
		temp[--count_array[(array[start] / exponent) % 10]] = array[start];
	for (i = 0; i < size; i++)
		array[i] = temp[i];
	free(count_array);
	free(temp);
	exponent *= 10;
}

/**
 * radix_sort - sorts an array using the radix sort algotithm (LSD)
 * @array: array to sort
 * @size: array size
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int largest, exp;
	size_t i;

	if (!array || !size)
		return;
	largest = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > largest)
			largest = array[i];
	}
	for (exp = 1; largest / exp > 0; exp *= 10)
	{
		_counting_sort(array, size);
		print_array(array, size);
	}
}
