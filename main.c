#include "monty.h"

/**
 * main - Interpreter for Monty ByteCodes files
 * @argc: number of arguments (command line)
 * @argv: array that stores arguments (command line)
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int num1, num2;
	char *operator;
	(void) argc;

	if (argc != 4)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	num1 = atoi(argv[1]);
	operator = argv[2];
	num2 = atoi(argv[3]);

	if (get_op_func(argv[2]) == NULL)
	{
		printf("Error, incorrect # of arguments \n");
		exit(99);
	}
	if (num2 == 0 && (*operator == '/' || *operator == '%'))
	{
		printf("Error, bad operator\n");
		exit(100);
	}
	printf("%d\n", get_op_func(operator)(num1, num2));

	return (0);
}