#include "monty.h"

/**
 * _div - divides the second top element by the top element of the stack
 * @head: pointer to a stack
 * @line_number: number of line opcode
 */
void _div(stack_t **head, unsigned int line_number)
{
	int div = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*head)->n;
		_pop(head, line_number);
		(*head)->n /= div;
	}
}
