#include "monty.h"

/**
 * op_func -  returns the correct function for opcode
 * @s: the opcode
 * Return: fun or NULL
 */
instruct_f op_func(char *s)
{
	int i;

	instruction_t inst[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL},
	};

	i = 0;
	while (inst[i].f != NULL && strcmp(inst[i].opcode, s) != 0)
	{
		i++;
	}

	return (inst[i].f);
}

/**
 * is_num - checks the string
 * @s: string
 * Return: returns 1 or 0
 */
int is_num(char *s)
{
	unsigned int i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * parse_line - parses a line (opcode and argument)
 * @line: the line to be parsed
 * @head: the head of the stack
 * @line_number: the current line number
 * Return: returns the opcode or null on failure
 */

char *parse_line(char *line, stack_t **head, unsigned int line_number)
{
	char *op_code, *push, *a;
    (void)head;

    push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		a = strtok(NULL, "\n ");
		if (is_num(a) == 1 && a != NULL)
		{
			var.arg = atoi(a);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}

/**
 * read_file - reads a bytecode file and runs commands
 * @f: file
 * @head: pointer to the stack
 */
void read_file(char *f, stack_t **head)
{
	char *line;
	size_t i = 0;
	instruct_f s;
	int count_line = 1, read, check;

	var.file = fopen(f, "r");
	if (var.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", f);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&var_global.buffer, &i, var_global.file)) != -1)
	{
		line = parse_line(var.buffer, head, count_line);
		if (line == NULL || line[0] == '#')
		{
			count_line++;
			continue;
		}

        s = op_func(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", count_line, line);
			exit(EXIT_FAILURE);
		}

        s(head, count_line);
		count_line++;
	}
    free(var.buffer);

    check = fclose(var.file);
	if (check == -1)
		exit(-1);
}
