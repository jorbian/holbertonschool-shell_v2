#include "hsh.h"

/**
 * tokenizer - creates a token from input
 * @buffer: buffer from getchar
 * Return: our tokenized inputs
 */
char **tokenizer(char *buffer)
{
	char delimiter[] = {' ', '\n'};
	char *tok;
	char **token_array = NULL;
	int i;

	token_array = malloc(sizeof(char *) * 128);
	if (!token_array)
	{
		perror("token array not mallocd");
		return (NULL);
	}

	tok = strtok(buffer, delimiter);
	for (i = 0; tok != NULL; i++)
	{
		token_array[i] = tok;
		tok = strtok(NULL, delimiter);
	}

	for (i = 0; token_array[i] != NULL; i++)
	{
		printf("%s\n", token_array[i]);
	}
	return (token_array);
}
