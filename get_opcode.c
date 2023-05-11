#include "monty.h"

/**
 * get_opcode - selects the correct opcode to perform
 *				the operation read in the file
 * @stack: pointer to the stack
 * @str: input string for comparison
 * @line_cnt: number of lines in the file
 *
 * Return: void
 */
void get_opcode(stack_t **stack, char *str, unsigned int line_cnt)
{
	int i;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode; i++)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_cnt);
			break; /* if a match is found, run the function */
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, str);
	exit(EXIT_FAILURE);
}
