#ifndef _MONTY_H_
#define _MONTY_H_

/*
 * Description: Header file containing prototypes for all functions
 */

/* C standard lib headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>		/* to use strcmp */
#include <stddef.h>		/* to use NULL macro*/
#include <ctype.h>		/* to use isdigit*/

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
/*
	char *op;
	int (*f)(int a, int b);
*/
} instruction_t;

/* functions in functions_opcodes.c */
/*int op_add(int a, int b);*/
stack_t *add_node(stack_t **head, const int n);
void push(stack_t **stack, unsigned int line_cnt);



/* funtions in get_opcode.c */
/* int (*get_op_func(char *s))(int, int); */
void opcode(stack_t **stack, char *str, unsigned int line_cnt);


/* functions in functions_files.c */
ssize_t read_file(const char *filename);

#endif /* _MONTY_H_ */