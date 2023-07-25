#include "sort.h"
#include <stdio.h>


/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array
 * @size: size of the array
 *
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	size_t i, step, idx;
	int tmp;

	for (step = 0; step < size - 1; step++)
	{
		idx = step;
		for (i = step + 1; i < size; i++)
		{
			if (array[i] < array[idx])
				idx = i;
		}

		if (idx != step)
		{
			tmp = array[step];
			array[step] = array[idx];
			array[idx] = tmp;
			print_array(array, size);
		}
	}
}
