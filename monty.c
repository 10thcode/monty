#include "monty.h"

void execute(char *lineptr, stack_t **stack, unsigned int line_number);
int exit_code = EXIT_SUCCESS;

/**
 * main - program entry point
 *
 * @ac: argument count
 * @av: argument list
 *
 * Return: Always return EXIT_SUCCESS
 */
int main(int ac, char *av[])
{
	stack_t *stack = NULL;
	int fd, bytes_read;
	unsigned int line_number = 1;
	char *filename, *lineptr = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return(EXIT_FAILURE);
	}

	filename = av[1];
	fd  = open(filename, O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return(EXIT_FAILURE);
	}

	bytes_read = _getline(&lineptr, fd);

	while (bytes_read != -1)
	{
		execute(lineptr, &stack, line_number);
		free(lineptr);
		if (exit_code == EXIT_FAILURE)
			break;
		bytes_read = _getline(&lineptr, fd);
		line_number++;
	}

	free_stack(stack);
	close(fd);

	return (exit_code);
}
