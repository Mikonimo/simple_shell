#include "main.h"
/**
 * execute_line - executes the arguments tokenized from the line
 * @args: the arguements to be executed
 * @envp: the environment variables
 *
 * Return: the status, success or failure
 */
int execute_line(char **args, char **envp)
{
	pid_t pid;
	int status;
	char *builtin_cmd1 = "cd";
	char *builtin_cmd2 = "env";
	char *builtin_cmd3 = "exit";

	if (args[0] == NULL)
		return (1);
	if (strcmp(args[0], builtin_cmd1) == 0)
	{
		return (m_cd(args));
	}
	else if (strcmp(args[0], builtin_cmd2) == 0)
	{
		return (m_env(envp));
	}
	else if (strcmp(args[0], builtin_cmd3) == 0)
	{
		return (m_exit());
	}
	else
	{
		pid = fork();
		if (pid < 0)
			perror("hsh");
		else if (pid == 0)
		{
			if (execve(get_path(args[0]), args, envp) == -1)
				perror("hsh");
		}
		else
			waitpid(pid, &status, 2);
	}
	return (1);
}
