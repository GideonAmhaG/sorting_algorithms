#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm
 * @array: the array to be sorted
 * @size: number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, i_min;

	for (i = 0; i < size - 1; i++)
	{
		i_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i_min])
				i_min = j;
		}
		tmp = array[i];
		array[i] = array[i_min];
		array[i_min] = tmp;
		print_array(array, size);
	}
}
