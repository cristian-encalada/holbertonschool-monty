#ifndef _MONTY_H_
#define _MONTY_H_

/* C standard lib headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>		/* to use strcmp */
#include <stddef.h>		/* to use NULL macro*/

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
 * struct globals_s - struct contains global variables.
 * @data: value to initialize nodes.
 * @fp: a file pointer.
 * @lineptr: pointer to a dynamic buffer.
 * @token: a pointer to the next token.
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
void delete_node(stack_t **head);
void free_stack(stack_t *stack);

/* get_opcode.c */
void get_opcode(stack_t **stack, unsigned int line_number);

/* monty_logic.c */
void check_args(int argc, char *argv[]);
void read_lines(stack_t **stack);
void tokenize_line(stack_t **stack, unsigned int line_number);
void check_num(stack_t **stack, unsigned int line_number);
void error_handler(stack_t **stack, unsigned int line_number, int error_type);

#endif /* _MONTY_H_ */
