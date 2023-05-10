#include "monty.h"

/**
 * push - push element to the stack
 * @stack: pointer to the stack
 * @line_cnt: number of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	char *n = NULL;

	if ((isdigit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	if (add_node(stack, atoi(n)) == NULL)
	{
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - prints all the values on the stack, starting from the top of the stack
 * @stack: pointer to the stack
 * @line_cnt: number of lines
 *
 * Return: void
 */

/*
void pall(stack_t **stack, unsigned int line_cnt)
{
	(void) line_cnt;
	print_stack(*stack);
}
*/