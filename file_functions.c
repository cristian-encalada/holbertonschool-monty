#include "monty.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: pointer to the name of the input file
 * Return: the actual number of characters per line
 *	- if filename is NULL return 0
 */
ssize_t read_file(const char *filename)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    if (filename == NULL)
	    return (0);

    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
