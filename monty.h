#ifndef _MONTY_H_
#define _MONTY_H_

/*
 * Description: Header file containing prototypes for all functions
 */

/* C standard lib headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

/* opcode_functions.c */
int op_add(int a, int b);

/* get_opcode.c */
int (*get_op_func(char *s))(int, int);


/* file_functions.c */
ssize_t read_file(const char *filename);

#endif /* _MONTY_H_ */