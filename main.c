#include "monty.h"

/**
 * main - Interpreter for Monty ByteCodes files
 * @argc: number of arguments
 * @argv: array that stores arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int num1, num2;
	char *operator;
	(void) argc;
	ssize_t n;

	if (argc != 2)
	{
		dprintf(2, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	n = read_file(argv[1]);
	printf("\n(printed chars: %li)\n", n);

	num1 = atoi(argv[1]);
	operator = argv[2];
	num2 = atoi(argv[3]);

	printf("%d\n", get_op_func(operator)(num1, num2));

	return (0);
}
