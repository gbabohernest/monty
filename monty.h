#ifndef __MONTY_H__
#define __MONTY_H__

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;

typedef void (*opcode_fun)(stack_t **, unsigned int);

void open_file(char *);
void read_file(FILE *);
int tokenize(char *, int, int);
void get_op_func(char *, char *, int, int);
void exec_op_fun(opcode_fun, char *, char *, int, int);

stack_t *init_node(int n);
void free_nodes(void);

void op_print_stack(stack_t **, unsigned int);
void op_add_to_stack(stack_t **, unsigned int);
#endif
