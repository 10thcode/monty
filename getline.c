#include "monty.h"

/**
 * _getline - read line from a file descriptor
 * @lineptr: where the line read will be store
 * @fd: the file descriptor
 *
 * Return: number of bytes read if successfull,
 * EXIT_FAILURE otherwise
 */
ssize_t _getline(char **lineptr, int fd)
{
	ssize_t i = 0;
	char char_buf[1];
	char buffer[1024];
	ssize_t bytes_read;

	while (1)
	{
		bytes_read = read(fd, char_buf, 1);

		if (bytes_read == -1 || bytes_read == 0)
			return (-1);


		buffer[i] = char_buf[0];
		buffer[i + 1] = '\0';
		i++;

		if (char_buf[0] == '\n')
		{
			*lineptr = malloc(i + 1);

			if (*lineptr == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit_code = EXIT_FAILURE;
				return (-1);
			}

			strcpy(*lineptr, buffer);

			return (i);
		}
	}
}
