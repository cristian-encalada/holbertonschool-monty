#include "monty.h"

/**
 * check_args - verify the number of arguments
 * @argc: numbers of arguments.
 * @argv: pointer to an array of arguments (strings)
 */
void check_args(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.bytecodes = fopen(argv[1], "r");
	if (!global.bytecodes)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * read_lines - reads a text file and tokenize each line
 * @stack: double pointer to the first node
 *
 * Return: void
 */
void read_lines(stack_t **stack)
{
	int read;
	unsigned int line_number;
	size_t n;

	read = line_number = n = 0;

	while ((read = getline(&global.lineptr, &n, global.bytecodes)) != EOF)
	{
		line_number++;
		tokenize_line(stack, line_number);
	}
}

/**
 * tokenize_line - tokenizes a line and performs necessary operations
 * @stack: double pointer to the first node
 * @line_number: line number being processed
 *
 * Return: void
 */
void tokenize_line(stack_t **stack, unsigned int line_number)
{
	global.token = strtok(global.lineptr, " \n");
	if (global.token[0] == '#')
		return;
	if (global.token == NULL)
		return;

	if (!strcmp(global.token, "push"))
	{
		global.token = strtok(NULL, " \n");
		if (global.token)
		{
			check_num(stack, line_number);
			global.data = atoi(global.token);
			push(stack, line_number);
			return;
		}
		else
			error_handler(stack, line_number, 0);
	}

	get_opcode(stack, line_number);
}

/**
 * check_num - Checks if string contains number
 * @stack: double pointer to the first node
 * @line_number: the line number in the file.
 */
void check_num(stack_t **stack, unsigned int line_number)
{
	int i;

	for (i = 0; global.token[i]; i++)
	{
		if (i == 0 && global.token[0] == '-')
			i++;
		if (global.token[i] < '0' || global.token[i] > '9')
			error_handler(stack, line_number, 0);
	}
}

/**
 * error_handler - handle different error messages
 * @stack: double pointer to the first node
 * @line_number: number of line in the bytecode file
 * @error_type: value according to the error type
 */
void error_handler(stack_t **stack, unsigned int line_number, int error_type)
{
	if (error_type == 0)
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
	else if (error_type == 1)
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, global.token);
	else if (error_type == 2)
		fprintf(stderr, "Error: malloc failed\n");
	else if (error_type == 3)
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	else if (error_type == 4)
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	else if (error_type == 5)
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	else if (error_type == 6)
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	else if (error_type == 7)
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	else if (error_type == 8)
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	else if (error_type == 9)
		fprintf(stderr, "L%d: division by zero\n", line_number);
	else if (error_type == 10)
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	else if (error_type == 11)
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	free(global.lineptr);
	free_stack(*stack);
	fclose(global.bytecodes);
	exit(EXIT_FAILURE);
}
