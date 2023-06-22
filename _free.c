#include "monty.h"

/**
* _free - frees a list
* @head: head of the stack
*/
void _free(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
