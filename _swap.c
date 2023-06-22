#include "monty.h"

/**
 * _swap - swap top of stack
 * @head: pointer to stack
 * @line_number: number of line opcode
 */

void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int tmp;

	h = *head;
	if (h == NULL || h->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = h->n;
	h->n = h->next->n;
	h->next->n = tmp;
}
