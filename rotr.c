#include "monty.h"
/**
  *_rotr- rotates the stack to the bottom
  *@head: head of a stack
  *@line_number: line_number opcode
  *Return: nothing
 */

void _rotr(stack_t **head, unsigned int line_number)
{
    stack_t *t = *head;
    int x = 0;
    (void)line_number;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (t->next)
		t = t->next;

	x = t->n;
	while (t->prev)
	{
		t = t->prev;
		t->next->n = t->n;
	}

	t->n = x;
}
