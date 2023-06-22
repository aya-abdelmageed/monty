#include "monty.h"

/**
 * _pint - print the top of stack
 * @head: head to a stack
 * @line_number: number of line of opcode
 */

void _pint(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	h = *head;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", h->n);
}
