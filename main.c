#include "monty.h"

/**
 * main - Interpreter for Monty ByteCodes files
 * @argc: number of arguments
 * @argv: array that stores arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void) argc;
	ssize_t n;

	if (argc != 2)
	{
		dprintf(2, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	n = read_file(argv[1]);
	printf("\n(printed chars: %li)\n", n);

	/*	printf("%d\n", get_op_func(operator)(num1, num2)); */

	return (0);
}
