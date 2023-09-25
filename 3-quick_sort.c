#include "sort.h"

void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void quick_lomuto_wrapper(int *array, size_t  size, int low, int high);


/**
 * quick_lomuto_wrapper - wraps the sort
 * @array: the integer array
 * @low: the low elements the array
 * @high: the higher elements
 * @size: the size of the array
 * Return: sort
 */
void quick_lomuto_wrapper(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, size, low, high);
		quick_lomuto_wrapper(array, size, low, pivot - 1);
		quick_lomuto_wrapper(array, size, pivot + 1, high);
	}
}

/**
 * lomuto_partition - partion the array
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * swap - swaps the index of the elements
 * @a: the previous index
 * @b: the next index
 * Return: swaps values
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}




/**
 * quick_sort - sorts integers using the Quick sort algorithm
 * @array: the integer array
 * @size: size of the arrray
 * Return: sortrd list
 */
void quick_sort(int *array, size_t size)
{
	int flag = 1;

	if (array == NULL || size < 2)
		return;
	while (flag == 1)
	{
		flag = 0;
		quick_lomuto_wrapper(array, size, 0, size - 1);
		if (flag == 0)
			break;
	}
}
