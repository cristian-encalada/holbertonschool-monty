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
 * read_line - reads a text file and prints it to the POSIX standard output
 * @stack: double pointer to the first node
 *
 * Return: void
 */
void read_line(stack_t **stack)
{
	int len, dtype;
	unsigned int line_number;
	size_t n;

	len = dtype = line_number = n = 0;
	global.lineptr = NULL;
	while ((len = getline(&global.lineptr, &n, global.fp)) != EOF)
	{
		++line_number;
		global.token = strtok(global.lineptr, " \n");
		if (!global.token || global.token[0] == '#')
			continue;
		if (!strcmp(global.token, "stack"))
		{
			dtype = 0;
			continue;
		}
		else if (!strcmp(global.token, "queue"))
		{
			dtype = 1;
			continue;
		}
		if (!strcmp(global.token, "push"))
		{
			global.token = strtok(NULL, " \n");
			if (global.token)
			{
				parse_num(stack, line_number);
				global.data = atoi(global.token);
				if (!dtype)
					push(stack, line_number);
				else
					push_q(stack, line_number);
				continue;
			}
			else
				error_handle(stack, line_number, 0);
		}
		check_op(stack, line_number);
	}
}

/**
 * parse_num - Checks if string contains number
 * @stack: pointer to a pointer of first node
 * @line_number: the line number in the file.
 */
void parse_num(stack_t **stack, unsigned int line_number)
{
	int i;

	for (i = 0; global.token[i]; ++i)
	{
		if (i == 0 && global.token[0] == '-')
			++i;
		if (global.token[i] < '0' || global.token[i] > '9')
			error_handle(stack, line_number, 0);
	}
}
