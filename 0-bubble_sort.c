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
* bubble_sort -Function that sort an array of integer in ascending order
* @array: integers to sort
* @size: Array size
* Description: print array after swapping
*/
void bubble_sort(int *array, size_t size)
{
	size_t j, len = size;
	bool bubble = false;

	if (array == NULL || size < 2)
	return;

	while (bubble == false)
{
	bubble = true;
	for (j = 0; j < len - 1; j++)
{
	if (array[j] > array[j + 1])
{
	integer_swap(array + j, array + j + 1);
	print_array(array, size);
	bubble = false;
}
}
	len--;
}
}
