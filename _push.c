#include "monty.h"

/**
 * _push - push to a stack
 * @head: head to a stack
 * @line_number: number of line opcode occurs on
 */
void _push(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = malloc(sizeof(stack_t));
	if (h == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	h->n = var.arg;
	h->next = *head;
	h->prev = NULL;
	if (*head != NULL)
		(*head)->prev = h;
	*head = h;
}
