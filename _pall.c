#include "monty.h"

/**
 * _pall - print all function
 * @head: head to a stack
 * @line_number: number of line opcode occurs on
 */

void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
    (void)line_number;

    h = *head;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}