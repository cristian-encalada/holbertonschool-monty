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
		error_handle(stack, line_number, 2);

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
 * @line_number: the line number in the file
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	print_stack(*stack);
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
 * free_dlist - frees a doubly linked list
 * @head: pointer to head of list
 */
void free_dlist(stack_t **head)
{
	if (!head)
		return;

	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}


