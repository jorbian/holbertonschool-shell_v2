#include "hsh.h"
/**
 * find_command - finds the command to be executed
 * @tokenized: the tokens from command line
 * @head: the head of the env linked list
 * Return: is void
 */

int find_command(char **tokenized)
{
	int i, status;
/*
	char *path, *tok;
	char **output_list;
	char *command_name;
	int oi;

	path = retrieve_string_value(symbol_table, "PATH");

	tok = strtok(path, ":"); /* makes PATH a linked list 
	for (i = 0; tok != NULL; i++)
	{
		path_llist(&path_head, tok);
		tok = strtok(NULL, ":");
	}

	status = parse_args(tokenized);
	if (status == SUCCESS)
		return (status);

	else if (status == ENV_LIST)
	{
		print_env(output_list, oi);
		return (status);
	}
	else
	{
		command_name = create_command(tokenized[0]);
		status = execute_command(command_name, tokenized, status);

		return (status);
	}
*/
}
