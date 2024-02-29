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
	char *cmd;

	if (args[0] == NULL)
		return (1);
	if (strcmp(args[0], builtin_cmd1) == 0)
		return (m_cd(args));
	else if (strcmp(args[0], builtin_cmd2) == 0)
		return (m_env(envp));
	else if (strcmp(args[0], builtin_cmd3) == 0)
	{
		return (m_exit());
	}
	else
	{
		cmd = get_path(args[0]);
		if (cmd == NULL || access(cmd, X_OK) != 0)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			return (127);
		}
		else
		{
			pid = fork();
			if (pid < 0)
				perror("hsh");
			else if (pid == 0)
			{
				if (execve(cmd, args, envp) == -1)
				{
					perror("hsh");
					free(cmd);
				}
			}
			else
				waitpid(pid, &status, 0);
			if (cmd != *args)
				free(cmd);
		}
	}
	return (1);
}
