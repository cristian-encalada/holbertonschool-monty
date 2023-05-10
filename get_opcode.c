#include "monty.h"

/**
 * get_opcode - selects the correct opcode to perform
 *	the operation read in the file
 * @stack: pointer to the stack
 * @str: input string for comparison
 * @line_cnt: number of lines in the file
 * Return: void
 */
/*int (*get_op_func(char *s))(int, int)*/
void get_opcode(stack_t **stack, char *str, unsigned int line_cnt)
{
	int i = 0;

/*
*	op_t ops[] = {
*			{"+", op_add},
*			{NULL, NULL}
*		};
*/
	instruction_t op[] = {
		{"push", push},
		{NULL, NULL}
	};

	/*while (ops[i].op != NULL)*/
	while (op[i].opcode)
	{
		/*
*		if (strcmp(ops[i].op, s) == 0)
*			return (ops[i].f);
*		i++;
		*/
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_cnt);
			return; /* if a match is found, run the function */
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, str);
	exit(EXIT_FAILURE);
	/*return (NULL);*/
}
