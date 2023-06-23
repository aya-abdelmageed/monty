#include "monty.h"

/**
 * _mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number of opcode
 * Return: nothing
*/
void _mul(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
	}

    tmp = (*head)->n;
	_pop(head, line_number);
	(*head)->n *= tmp;
}
