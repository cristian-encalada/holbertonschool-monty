#include "monty.h"
global_t global;
/**
 * main - Interpreter for Monty ByteCodes files
 * @argc: number of arguments
 * @argv: pointer to an array of arguments (strings)
 *
 * Return: EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	check_args(argc, argv);
	read_lines(&stack);

	free(global.lineptr);
	free_stack(stack);
	fclose(global.bytecodes);

	return (EXIT_SUCCESS);
}
