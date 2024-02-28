#include "main.h"
/**
 * token_line - break  the string(line) into individual tokens
 * @line: the line to be tokenized
 *
 * Return: the array of tokens
 */
char **token_line(char *line)
{
	size_t bufsize = TOK_SIZE;
	char *token;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));


	if (!tokens)
	{
		perror("hsh");
		exit(1);
	}
	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
