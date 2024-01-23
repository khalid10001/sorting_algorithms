#include "sort.h"

/**
 * bubble_sort - Sorts an array using the bubble sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t a, b;

	if (!array || !size)
		return;

	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
