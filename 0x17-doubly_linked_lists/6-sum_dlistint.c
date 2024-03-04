#include "lists.h"
/**
 * sum_dlistint - Returns the sum of the data (n)
 * @head: head arg for the list
 * Return: sum of the list elements. 0 if no list
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
