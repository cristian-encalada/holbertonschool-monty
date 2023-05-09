#ifndef _MONTY_H_
#define _MONTY_H_

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

int op_add(int a, int b);
int (*get_op_func(char *s))(int, int);

#endif /* _MONTY_H_ */