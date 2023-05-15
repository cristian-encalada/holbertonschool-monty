#include "monty.h"

/**
 * mul - multiplies the second top element of the stack
 *		with the top element of the stack
 * @stack: double pointer to the first node of the stack
 * @line_number: number of line in the bytecode file
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handler(stack, line_number, 6);
	aux = *stack;
	*stack = (*stack)->next;

	(*stack)->n *= aux->n;
	free(aux);
	(*stack)->prev = NULL;
}
