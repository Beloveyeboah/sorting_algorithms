#include "sort.h"

/**
 * bubble_sort - function that sort's array using buble sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t temp, i, j;
	int flag = 1;

	if (array == NULL || size < 2)
		return;

	while (flag == 1)
	{
		flag = 0;
		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - 1 - i; j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					flag = 1;
					print_array(array, size);
				}
			}
		}
		if (flag == 0)
			break;
	}
}
