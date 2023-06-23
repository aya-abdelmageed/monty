#include "monty.h"

/**
 * _sub - sub the top two elements of the stack
 * @head: pointer to stack
 * @line_number: number of lines
 */

void _sub(stack_t **head, unsigned int line_number)
{
    int sub = 0, nodes = 0;
    stack_t *h = *head;

	while (h)
	{
		h = h->next;
		nodes++;
	}

	if (head == NULL || (*head)->next == NULL || nodes <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*head)->next->n - (*head)->n;
	_pop(head, line_number);

	(*head)->n = sub;
}