#include "sort.h"

void swap(int *a, int *b);

/**
 * shell_sort -  sorts an array of integers using the Shell
 * sort algorithm, using the Knuth sequence
 * @array: the arrray integer
 * @size: the length of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int flag = 1;

	if (array == NULL || size < 2)
		return;
	while (flag == 1)
	{
		flag = 0;
		for (gap = 1; gap < (size / 3);)
			gap = gap * 3 + 1;
		for (; gap >= 1; gap /= 3)
		{
			for (i = gap; i < size; i++)
			{
				j = i;
				while (j >= gap && array[j - gap] > array[j])
				{
					swap(array + j, array + (j - gap));
					j -= gap;
				}
			}
			print_array(array, size);
		}
		if (flag == 0)
			break;
	}
}


/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
