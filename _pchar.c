#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @line_number: line_number
 * Return: nothing
*/
void _pchar(stack_t **head, unsigned int line_number)
{
	stack_t *hh;

	hh = *head;
	if (!hh)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(var.file);
		free(var.buffer);
		_free(*head);
		exit(EXIT_FAILURE);
	}
	if (hh->n > 127 || hh->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(var.file);
		free(var.buffer);
		_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", hh->n);
}
