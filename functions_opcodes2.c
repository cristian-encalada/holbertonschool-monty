#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the first node of the stack
 * @line_number: number of line in the bytecode file
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	int num;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handler(stack, line_number, 5);

	num = (*stack)->n;
	aux = (*stack)->next;

	(*stack)->n = aux->n;
	aux->n = num;
}

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

