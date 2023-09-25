#include "sort.h"

void _swap(int *a, int *b);

/**
 * _swap - swaps index of an element
 * @a: value at previous index
 * @b: value at next index
 * Return: the swap values
 */
void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array using the Selection sort algorithm
 * @size: the size of array
 * @array: name of the array
 * Return: sorted list
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t mini;
	int flag = 1;

	if (array == NULL || size < 2)
		return;

	while (flag == 1)
	{
		flag = 0;
		for (i = 0; i < size - 1; i++)
		{
			mini = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[mini])
				{
					mini = j;
				}
			}
			if (mini != i)
			{
				_swap(&array[i], &array[mini]);
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
