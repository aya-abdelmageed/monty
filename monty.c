#include "monty.h"

global_var var;
/**
 * main - function for monty prog
 * @c: the numbers of arguments
 * @v: opcode file (arguments)
 * Return: 0
 */

int main(int c, char **v)
{
	stack_t *st;

	st = NULL;

	if (c != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(v[1], &st);

	_free(st);
	return (0);
}
