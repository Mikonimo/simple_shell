#include "main.h"
/**
 * m_cd - changes from the current directory to the specified directory
 * @args: the directory to change to/ its path
 *
 * Return: 1 on success
 */
int m_cd(char **args)
{
	char *home;

	home = getenv("HOME");
	if (args[1] == NULL)
	{
		if (chdir(home) != 0)
		{
			perror("hsh");
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
			return (1);
		}
	}

	return (1);
}
