#include "main.h"
/**
 * get_path - returns the full path of a command
 * @arg: the command
 *
 * Return: the full path
 */
char *get_path(char *arg)
{
	char *path;
	char *path_cpy;
	char *dir;
	char *full_path;
	size_t bufsize = TOK_SIZE;

	path = getenv("PATH");
	if (path == NULL)
	{
		perror("hsh");
		exit(1);
	}
	path_cpy = strdup(path);
	dir = strtok(path_cpy, ":");
	while (dir != NULL)
	{
		full_path = malloc(bufsize * sizeof(char *));
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, arg);

		if (access(full_path, X_OK) == 0)
		{
			free(path_cpy);
			return (full_path);
		}
		else
		{
			free(full_path);
			dir = strtok(NULL, ":");
		}
	}
	if (access(arg, X_OK) == 0)
		return (arg);
	return (NULL);
}
