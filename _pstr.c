#include "monty.h"

/**
 * _pstr - prints the string of stack elements followed by a new line
 * @head: stack head
 * @line_number: line numbers of opcode
 * Return: nothing
*/
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *t;
	int x = 0;
	(void)line_number;

	t = *head;
	while (t)
	{
        x = t->n;
        if (x > 127 || x <= 0)
			break;

        printf("%c", x);
		t = t->next;
	}
	printf("\n");
}
