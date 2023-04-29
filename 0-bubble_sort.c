#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of integers
 * in ascending order using Bubble sort algorithm.
 * @array: The array of integers.
 * @size: Number of elements in @array.
 *
 * Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i;
	bool swapping;

	swapping = true;

	while (swapping == true)
	{
		swapping = false;

		for (i = 0; i < size; i++)
		{
			if (i > 0 && array[i - 1] > array[i])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				swapping = true;
				print_array(array, size);
			}
		}
	}
}
