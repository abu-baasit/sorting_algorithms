#include "sort.h"

/**
 * nodeSwap - function that swap 2 nodes in linked list
 * @h:Pointer to the head
 * @n1:Pointer to the first node
 * @n2: Second node
 */
void nodeSwap(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
	n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
	(*n1)->prev->next = n2;
	else
	*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list -  function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @list: Pointer to the head
 * Description: Prints the list after swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			nodeSwap(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
