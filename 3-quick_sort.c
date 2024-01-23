#include "sort.h"

/**
 * swap - a function swap two integer
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
 * lomuto_part - Performs Lomuto partition on an array.
 *
 * This function takes an array, its size, and the low and high indices,
 * and rearranges the elements such that elements smaller than the pivot
 * are on the left, and elements greater than the pivot are on the right.
 *
 * @array: Pointer to the array to be partitioned.
 * @size: Size of the array.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * Return: The index of the pivot after partitioning.
 */
size_t lomuto_part(int *array, size_t size, size_t low, size_t high)
{
	int *pivot;
	size_t x, y;
	pivot = array + high;
	for (x = y = low; y < high; y++)
	{
		if (array[y] < *pivot)
		{
			if (x < y)
			{
				swap(array + y, array + x);
				print_array(array, size);
			}
			x++;
		}
	}

	if (array[x] > *pivot)
	{
		swap(array + x, pivot);
		print_array(array, size);
	}

	return (x);
}

/**
 * quicksort - Sorts an array using the quicksort algorithm.
 *
 * This function recursively sorts an array of integers using the quicksort
 * algorithm. It selects a pivot element and partitions the array into two
 * sub-arrays such that elements less than the pivot are on the left, and
 * elements greater than the pivot are on the right. The process is repeated
 * for each sub-array until the entire array is sorted.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * @low: Starting index of the sub-array to be sorted.
 * @high: Ending index of the sub-array to be sorted.
 */
void quicksort(int *array, size_t size, size_t low, size_t high)
{
	if (low < high)
	{
		size_t pvt = lomuto_part(array, size, low, high);

		quicksort(array, size, low, pvt - 1);
		quicksort(array, size, pvt + 1, high);
	}
}

/*
 * quick_sort - Sorts an array of integers using the QuickSort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * This function sorts an array of integers in ascending order using the
 * QuickSort algorithm. It takes a pointer to the array and the size of
 * the array as parameters.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quicksort(array, size, 0, size - 1);
}
