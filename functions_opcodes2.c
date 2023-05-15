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
 * add - adds the top two elements of the stack
 * @stack: double pointer to the first node of the stack
 * @line_number: number of line in the bytecode file
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handler(stack, line_number, 6);
	aux = *stack;
	*stack = (*stack)->next;

	(*stack)->n += aux->n;
	free(aux);
	(*stack)->prev = NULL;
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

/**
 * sub - subtracts the top element of the stack
 *		from the second top element of the stack
 * @stack: double pointer to the first node of the stack
 * @line_number: number of line in the bytecode file
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handler(stack, line_number, 7);

	aux = *stack;
	*stack = (*stack)->next;

	(*stack)->n -= aux->n;
	free(aux);
	(*stack)->prev = NULL;
}

/**
 * div - divides the second top element of the stack
 *				by the top element of the stack
 * @stack: double pointer to the first node of the stack
 * @line_number: number of line in the bytecode file
 *
 * Return: void
 */
void division(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handler(stack, line_number, 8);

	if ((*stack)->next == 0)
		error_handler(stack, line_number, 9);

	aux = *stack;
	*stack = (*stack)->next;

	(*stack)->n /= aux->n;
	free(aux);
	(*stack)->prev = NULL;
}
