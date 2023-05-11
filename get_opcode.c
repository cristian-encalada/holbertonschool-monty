#include "monty.h"

/**
 * get_opcode - selects the correct opcode to perform
 *				the operation read in the bytecode file
 * @stack: double pointer to the first node of the stack
 * @line_number: number of line in the bytecode file
 *
 * Return: void
 */
void get_opcode(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (!strcmp(global.token, opcodes[i].opcode))
		{
			global.token = strtok(NULL, " \n");
			opcodes[i].f(stack, line_number);
			break;
		}
	}
	if (opcodes[i].opcode == NULL)
		error_handler(stack, line_number, 1);
}
