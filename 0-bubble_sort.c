#include "sort.h"

void _swap(int *a, int *p);


/**
 * _swap - swaps the index of two values
 * @a: an array
 * @p: an array
 * Return: anything
 */

void _swap(int *a, int *p)
{
	int swap;

	swap = *a;
	*a = *p;
	*p = swap;
}

/**
 * bubble_sort - sorts sorts an array of integers
 * @array: the name of the array
 * @size: the lenght of the array
 * Return: anything
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, i = 0;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				_swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
