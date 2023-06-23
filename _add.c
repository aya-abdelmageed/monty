#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @head: pointer to stack
 * @line_number: number of lines
 */

void _add(stack_t **head, unsigned int line_number)
{
    int sum = 0, i = 0;
	stack_t *h = *head;

	while (h)
	{
		h = h->next;
		i++;
	}

	if (head == NULL || (*head)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

    sum = (*head)->n + (*head)->next->n;
	_pop(head, line_number);

	(*head)->n = sum;
}