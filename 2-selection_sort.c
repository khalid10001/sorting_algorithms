#include "sort.h"

/**
 * swap - a function swap two ints
 * @x: int pointer
 * @y: int pointer
 */
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the first element of the array
 * @size: The number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, z;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		z = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[z])
			{
				z = y;
			}
		}

		if (z != x)
		{
			swap(&array[x], &array[z]);
			print_array(array, size);
		}
	}
}
