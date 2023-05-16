#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 *		The last element of the stack becomes the top element of the stack
 * @stack: double pointer to the first node of the stack
 * @line_number: number of line in the bytecode file
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
	stack_t *last = *stack;
	stack_t *second_last = *stack;

	while (last->next != NULL) /* traverse stack until last element */
	last = last->next;

	while (second_last->next != last)
	second_last = second_last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	second_last->next = NULL; /* disconnect second_last from the next node */
	last->prev = NULL; /* disconnect last from the prev node */
	}
}

/**
 * push_queue - Add a new node at the end of a linked list
 * @stack: Pointer to pointer of first node
 * @line_number: Current line number
 */
void push_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *current;

	current = *stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		error_handler(stack, line_number, 2);

	new->n = global.data;
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		new->prev = current;
		current->next = new;
	}
}
