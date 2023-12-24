#include "sort.h"

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
* selection_sort -function that sorts an array of integers
* in ascending order using the Selection sort algorithm
* @array: integers to sort
* @size: Array size
* Description: print array after swapping
*/
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t k, m;

	if (array == NULL || size < 2)
		return;

	for (k = 0; k < size - 1; k++)
	{
		min = array + k;
		for (m = k + 1; m < size; m++)
			min = (array[m] < *min) ? (array + m) : min;

		if ((array + k) != min)
		{
			integer_swap(array + k, min);
			print_array(array, size);
		}
	}
}
