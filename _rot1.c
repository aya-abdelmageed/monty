#include "monty.h"
/**
  *_rotl- rotates the stack to the top
  *@head: head of a stack
  *@line_number: line_number
  *Return: nothing
 */
void _rotl(stack_t **head,  unsigned int line_number)
{
	stack_t *run = *head, *sec;
	(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	sec = (*head)->next;
	sec->prev = NULL;

	while (run->next != NULL)
	{
		run = run->next;
	}

	run->next = *head;
	(*head)->next = NULL;
	(*head)->prev = run;
	(*head) = sec;
}
