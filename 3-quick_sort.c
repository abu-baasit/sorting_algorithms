#include "sort.h"

void integer_swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
* integer_swap - function that swap integers
* @a: first interger
* @b: second integer
*/
void integer_swap(int *a, int *b)
{
	int temp;
	 temp = *a;
	 *a = *b;
	 *b = temp;
}

/**
* lomuto_partition -Function that sort an array of integer in ascending order
* @array: integers to sort
* @size: Array size
* @right:starting index
* @left:ending index
* Return: return final index
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
				integer_swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		integer_swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort -Function that implement algorithm through recursion.
 * @array: Array of integers
 * @size: Size of the array.
 * @left: The starting index
 * @right: The ending index
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partition - 1);
		lomuto_sort(array, size, partition + 1, right);
	}
}

/**
 * quick_sort -Function that Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 * Description: Uses the Lomuto partition scheme.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
