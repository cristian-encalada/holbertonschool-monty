#include "monty.h"

/**
 * read_file - reads a text file and prints it to the POSIX standard output
 * @filename: pointer to the name of the input file
 * Return: the actual number of characters per line
 *	- if filename is NULL return 0
 */
ssize_t read_file(const char *filename)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		printf("Retrieved line of length %lu:\n", read);
		printf("%s", line);
	}

	fclose(file);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
