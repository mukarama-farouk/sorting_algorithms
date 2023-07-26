#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @array: array
 * @a: first element of the array
 * @b: secong element of the array
 *
 * Return: no return
 */
void swap(int *array, size_t a, size_t b)
{
	int ptr;

	if (array)
	{
		ptr = array[a];
		array[a] = array[b];
		array[b] = ptr;
	}
}


/**
 * quick_sort_range_lomuto - Sorts a sub array using the
 * quick sort algorithm and Lomuto's partition scheme.
 * @array: The array containing the sub-array.
 * @a: The starting position of the sub-array.
 * @b: The ending position of the sub-array.
 * @size: The length of the array.
 */
void quick_sort_lomuto(int *array, size_t a, size_t b, size_t size)
{
	size_t i, j;
	int pivot;

	if ((a >= b) || (array == NULL))
		return;
	pivot = array[b];
	i = a;
	for (j = a; j < b; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != b)
	{
		swap(array, i, b);
		print_array(array, size);
	}
	if (i - a > 1)
		quick_sort_lomuto(array, a, i - 1, size);
	if (b - i > 1)
		quick_sort_lomuto(array, i + 1, b, size);
}


/**
 * quick_sort -  sorts an array of integers in ascending order
 * @array: array
 * @size: size of array
 *
 * Return : No return
 */
void quick_sort(int *array, size_t size)
{
	if (array)

		quick_sort_lomuto(array, 0, size - 1, size);
}
