#include "monty.h"

/**
 * push - push a new node at the beggining of the stack
 * @stack: double pointer to the first node of the stack
 * @line_number: number of line in the bytecode file
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		error_handler(stack, line_number, 2);

	new->n = global.data;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to the first node of the stack
 * @line_number: number of line in the bytecode file
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current)
	{
		printf("%i\n", current->n);
		current = current->next;
	}
}

/**
 * delete_node - deletes node at end
 * @head: head of the list
 */
void delete_node(stack_t **head)
{
	stack_t *aux = NULL;

	aux = *head;
	if (aux->next == NULL)
	{
		*head = NULL;
		free(aux);
	}
	else
	{
		*head = aux->next;
		(*head)->prev = NULL;
		free(aux);
	}
}

/**
 * free_stack - frees a stack_t stack (list)
 * @stack: pointer to the first node of the list
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}


