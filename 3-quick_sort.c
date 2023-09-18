#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array to take in
 * @start: start of array;
 * @end: end of array
 * @size: full size of array
 * Return: position of pivot
 */
int lomuto_partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int i = start - 1;
	int j;
	int temp;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[end])
	{
		temp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quickSort - quick sorts with recursion
 * @array: array to sort through
 * @start: start of array or subarray
 * @end: end of array or subarray
 * @size: size of full array
 */
void quickSort(int *array, int start, int end, int size)
{
	int piv;

	if (start < end)
	{
		piv = lomuto_partition(array, start, end, size);
		quickSort(array, start, piv - 1, size);
		quickSort(array, piv + 1, end, size);
	}
}

/**
 * quick_sort - quick sorts an array
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
