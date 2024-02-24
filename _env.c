#include "main.h"
/**
 * m_env - prints the environment of the shell
 * @env: the environment variables to be printed
 *
 * Return: 1 on success
 */
int m_env(char **env)
{
	int p;

	for (p = 0; env[p] != NULL; p++)
	{
		printf("%s\n", env[p]);
	}

	return (1);
}
