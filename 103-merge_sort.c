#include "sort.h"

/**
 * merge - Function that merges the divided array.
 * @array: Array to be sorted.
 * @left: left half of the array.
 * @mid: median of array.
 * @right: right half of the array.
 */
void merge(int *array, int left, int mid, int right)
{
	int i, j, k, n1, n2, *lefthalf, *righthalf;

	n1 = mid - left + 1;
	n2 = right - mid;
	lefthalf = (int *) malloc(n1 * sizeof(int));
	righthalf = (int *) malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
	{
		lefthalf[i] = array[left + i];
	}
	for (j = 0; j < n2; j++)
	{
		righthalf[j] = array[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;

	printf("Merging...\n");
	printf("[left]: ");

	for (i = 0; i < n1; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", lefthalf[i]);
	}
	printf("\n");

	printf("[right]: ");

	for (j = 0; j < n2; j++)
	{
		if (j > 0)
			printf(", ");
		printf("%d", righthalf[j]);
	}
	printf("\n");

	i = 0;
	j = 0;
	k = left;


	while (i < n1 && j < n2)
	{
		if (lefthalf[i] <= righthalf[j])
		{
			array[k] = lefthalf[i];
			i++;
		}
		else
		{
			array[k] = righthalf[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = lefthalf[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = righthalf[j];
		j++;
		k++;
	}

	printf("[Done]: ");

	for (i = left; i <= right; i++)
	{
		if (i > left)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");


	free(lefthalf);
	free(righthalf);
}


/**
 * merge_sort_helper - helper function to sort the array.
 * @array: array to be sorted.
 * @left: left side of the array.
 * @right: right side of the array.
 */
void merge_sort_helper(int *array, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		merge_sort_helper(array, left, mid);
		merge_sort_helper(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}


/**
 * merge_sort - function to sort array using merge sort alg.
 * @array: array to be sorted.
 * @size: size of the array.
 */
void merge_sort(int *array, size_t size)
{
	merge_sort_helper(array, 0, size - 1);
}
