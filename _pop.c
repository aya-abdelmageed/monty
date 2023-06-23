#include "monty.h"

/**
 * _pop - remove element of alist
 *@head: pointer to first node of a stack
 *@line_number: integer
 *Return: nothing
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *h = *head;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

    *head = h->next;
	if (*head != NULL)
		(*head)->prev = NULL;

    free(h);
}