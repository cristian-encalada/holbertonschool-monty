#include "monty.h"

/**
 * get_op_func - selects the correct function to perform
 *	the operation asked by the user
 * @s: operator passed as argument
 * Return: A pointer to the function that corresponds
 *	to the operator given as a parameter.
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op != NULL)
	{/* strcmp returns 0 if strings are equal */
		if (strcmp(ops[i].op, s) == 0)
			return (ops[i].f);
	i++;
	}
	return (NULL);
}
