#include "monty.h"
/**
 * nop - The opcode nop doesn’t do anything
 * @stack: double pointer to the first node of the stack
 * @line_number: number of line in the bytecode file
 *
 * Return: void
 */


void nop(stack_t **stack, unsigned int line_number)
{
		(void)**stack;
		(void)line_number;
}

