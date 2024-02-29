#include "main.h"
/**
 * read_line - reads the user's input and stores it into a buffer
 *
 * Return: the line read
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread = 0;

	nread = getline(&line, &bufsize, stdin);
	if (nread == -1)
	{
		exit(0);
	}

	return (line);
}
