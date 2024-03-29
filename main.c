#include "main.h"
int exit_status;
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
	char **tokens = NULL;

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
		tokens = token_line(line);
		status = execute_line(tokens, envp, line);
		free(line);
		line = NULL;
		free(tokens);
		tokens = NULL;
		if (status == exit_status)
		{
			/** nothing*/
		}
	}
	return (0);
}
