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
		error_handler(stack, line_number, 10);
	aux = *stack;
	*stack = (*stack)->next;

	(*stack)->n *= aux->n;
	free(aux);
	(*stack)->prev = NULL;
}

/**
 * mod - gives the rest of the division of the second top element of the stack
 *		by the top element of the stack
 * @stack: double pointer to the first node of the stack
 * @line_number: number of line in the bytecode file
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handler(stack, line_number, 11);

	if ((*stack)->n == 0)
		error_handler(stack, line_number, 9);

	aux = *stack;
	*stack = (*stack)->next;

	(*stack)->n %= aux->n;
	free(aux);
	(*stack)->prev = NULL;
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: double pointer to the first node of the stack
 * @line_number: number of line in the bytecode file
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		error_handler(stack, line_number, 13);
	printf("%c\n", (*stack)->n);
}
