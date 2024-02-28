#include "main.h"
/**
 * main - entry point
 * @ac: the argument count
 * @av: array of pointers to strings passed as arguments
 * @envp: array  of pointers to the environment variables
 *
 * Return: 0 if succesful
 */
int main(int ac, char **av, char **envp)
{
	char *prompt = "($) ";
	char *line = NULL;
	int status;
	int interactive;

	(void)ac;

	interactive = isatty(STDIN_FILENO);
	while (1)
	{
		if (interactive)
		{
			printf("%s", prompt);
			fflush(stdout);
		}
		if (interactive || av[1] == NULL)
		{
			line = read_line();
			if (!interactive && line == NULL)
			{
				break;
			}
		}
		else
		{
			break;
		}
		av = token_line(line);
		status = execute_line(av, envp);
		free(line);
		free(av);
		line = NULL;
		if (status == 0)
		{
			break;
		}
	}

	return (0);
}
