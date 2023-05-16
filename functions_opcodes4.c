#include "monty.h"

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
