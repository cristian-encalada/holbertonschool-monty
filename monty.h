#ifndef _MONTY_H_
#define _MONTY_H_

/* C standard lib headers */
#include <stdio.h>		/* to use fopen, fclose, getline, printf, fprintf */
#include <stdlib.h>		/* to use malloc, free, atoi, exit */
#include <string.h>		/* to use strcmp, strtok */


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


/**
 * struct globals_s - struct contains global variables
 * @data: value to initialize nodes
 * @bytecodes: a pointer to the file containing the bytecodes
 * @lineptr: lineptr to be used in getline
 * @token: a pointer to the next token (opcode)
*/
typedef struct global_s
{
	int data;
	FILE *bytecodes;
	char *lineptr, *token;
} global_t;

extern global_t global;


/* functions_opcodes.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

/* functions_opcodes2.c */
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void division(stack_t **stack, unsigned int line_number);

/* functions_opcodes3.c */
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/* get_opcode.c */
void get_opcode(stack_t **stack, unsigned int line_number);

/* monty_logic.c */
void check_args(int argc, char *argv[]);
void read_lines(stack_t **stack);
void tokenize_line(stack_t **stack, unsigned int line_number);
void check_num(stack_t **stack, unsigned int line_number);
void error_handler(stack_t **stack, unsigned int line_number, int error_type);

#endif /* _MONTY_H_ */
