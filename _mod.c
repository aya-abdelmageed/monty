#include "monty.h"

/**
 * _mod - the rest of the division of the 2nd top element by the top element
 * @head: stack head
 * @line_number: number of line opcode occurs on
 */
void _mod(stack_t **head, unsigned int line_number)
{
	int mod = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = (*head)->n;
		_pop(head, line_number);
		(*head)->n %= mod;
	}
}
