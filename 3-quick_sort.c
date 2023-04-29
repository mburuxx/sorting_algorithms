#include "sort.h"

/**
 * quick_sort - Function that sorts an array of integers in
 * ascending order using the Quick sort alg.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - helper function to quick sort array integers.
 * @array: Array to be sorted.
 * @low: Lowest index
 * @high: highest index.
 * @size: size of the array.
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * partition - function that implements Lomuto partition scheme.
 * @array: Array to be sorted.
 * @low: Lowest index.
 * @high: highest index.
 * @size: Size of array.
 *
 * Return: i.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp, tmp;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	print_array(array, size);

	return (i);
}
