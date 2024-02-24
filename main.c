#include "main.h"
/**
 * main - entry point
 * @ac: the argument count
 * @av: array of pointers to strings passed as arguments
 *
 * Return: 0 if succesful
 */
int main(int ac, char **av)
{
	char *prompt = "($) ";
	char *line;
	int status;

	(void)ac;

	while (1)
	{
		printf("%s", prompt);
		line = read_line();
		av = token_line(line);
		status = execute_line(av);
		if (status == 0)
		{
			return (0);
		}
	}
	free(line);
	free(av);

	return (0);
}
