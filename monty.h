#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int arg;

/* bytecode file */

/**
 * struct global_var - opcode and its function
 * @file: the opcode
 * @arg: function to handle the opcode
 * @buffer: pointer to opcoode and its function
 */
typedef struct global_var
{
	FILE *file;
	int arg;
	char *buffer;
} global_var;

extern global_var var;


typedef void (*instruct_f)(stack_t **head, unsigned int line_number);
instruct_f op_func(char *s);
char *parse_line(char *line, stack_t **head, unsigned int line_number);
int is_num(char *s);
void read_file(char *f, stack_t **head);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void _free(stack_t *head);
void _nop(stack_t **head, unsigned int line_number);
void _push(stack_t **head, unsigned int line_number);
void _pall(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);
void _pchar(stack_t **head, unsigned int line_number);
void _rotl(stack_t **head, unsigned int line_number);
void _rotr(stack_t **head, unsigned int line_number);

#endif
