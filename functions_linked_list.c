#include "monty.h"

/*
* int op_add(int a, int b)
* {
*	return (a + b);
* }
*/
/**
 * add_node - adds a new node to the beginning of a stack_t stack
 * @head: pointer to the stack stack_t
 * @n: input integer
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}

	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}
