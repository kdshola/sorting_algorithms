#include "sort.h"

/**
 * swap - swaps two array elements
 * @x: first element
 * @y: second element
 * Return: nothing
 */
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * partition - sorts an array recursively using quicksort algoritm
 * @array: array to sort
 * @low: array lower bound
 * @high: arrays upper bound
 * @size: array size
 * Return: partition index
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1, j = high + 1;
	int pivot = array[high];

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (j);
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * sort - sorts an array recursively using quicksort algorithm
 * @array: array to sort
 * @low: array lower bound
 * @high: arrays upper bound
 * @size: array size
 * Return: nothing
 */
void sort(int *array, int low, int high, size_t size)
{
	int _partition;

	if (low < high)
	{
		_partition = partition(array, low, high, size);
		sort(array, low, _partition - 1, size);
		sort(array, _partition, high, size);
	}

}
/**
 * quick_sort_hoare - sorts an array recursively using quicksort algorithm
 * @array: array to sort
 * @size: array size
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || !size)
		return;
	sort(array, 0, size - 1, size);
}
