#include "monty.h"

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
