#include "sort.h"

int _max(int *array, int size);

/**
 * _max - find the maxinum value of array
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The max
 */
int _max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sorts  array of integers in ascending algo
 * @array: An array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sort, max, i, flag = 1;

	if (array == NULL || size < 2)
		return;
	while (flag == 1)
	{
		flag = 0;
		sort = malloc(sizeof(int) * size);
		if (sort == NULL)
			return;
		max = _max(array, size);
		count = malloc(sizeof(int) * (max + 1));
		if (count == NULL)
		{
			free(sort);
			return;
		}
		for (i = 0; i < (max + 1); i++)
			count[i] = 0;
		for (i = 0; i < (int)size; i++)
			count[array[i]] += 1;
		for (i = 0; i < (max + 1); i++)
			count[i] += count[i - 1];
		print_array(count, max + 1);
		for (i = 0; i < (int)size; i++)
		{
			sort[count[array[i]] - 1] = array[i];
			count[array[i]] -= 1;
		}
		for (i = 0; i < (int)size; i++)
			array[i] = sort[i];
		free(sort);
		free(count);
		if (flag == 0)
			break;
	}
}
