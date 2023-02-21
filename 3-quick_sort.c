#include "sort.h"

void q_s(int *array, int start, int end, size_t size);
int partition(int *array, int start, int end, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 * sort algorithm
 * @array: the array to be sorted
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;
	q_s(array, 0, size - 1, size);
}

/**
 * q_s - recurssion function sorting array using quick sort algorithm
 * @array: the array to be sorted
 * @start: first index of the array to be sorted
 * @end: last index of the array to be sorted
 * @size: size of the array
 */
void q_s(int *array, int start, int end, size_t size)
{
	int partition_index = 0;

	if (start < end)
	{
		partition_index = partition(array, start, end, size);
		q_s(array, start, partition_index - 1, size);
		q_s(array, partition_index + 1, end, size);
	}
}

/**
 * partition - partitions the array at the pivot where all elements left
 * of the pivot are smaller than the pivot
 * @array: the array to be sorted
 * @start: first index of the array to be sorted
 * @end: last index of the array to be sorted
 * @size: size of the array
 *
 * Return: index where the partition occurred
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot, i, partition_index, tmp = 0;

	pivot = array[end];
	partition_index = start;
	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			tmp = array[partition_index];
			array[partition_index] = array[i];
			array[i] = tmp;
			if (tmp != array[partition_index])
				print_array(array, size);
			partition_index++;
		}
	}
	tmp = array[partition_index];
	array[partition_index] = array[end];
	array[end] = tmp;
	if (tmp != array[partition_index])
		print_array(array, size);
	return (partition_index);
}
