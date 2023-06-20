#include "hsh.h"
/**
 * find_command - finds the command to be executed
 * @tokenized: the tokens from command line
 * @head: the head of the env linked list
 * Return: is void
 */

char *find_command(char **tokenized, env_t *head)
{
	int i;
	char *status, *path, *tok;
	char **output_list, **command;
	path_t *path_head;
	int oi;

	output_list = build_env_array(head);			 /* mallocs env array */
	output_list = fill_env_array(head, output_list); /* populates env array */
	oi = _strlen(*output_list);
	path = find_path(output_list);

	tok = strtok(path, ":"); /* makes PATH a linked list */
	for (i = 0; tok != NULL; i++)
	{
		path_llist(&path_head, tok);
		tok = strtok(NULL, ":");
	}
	status = parse_args(tokenized, path_head, head);
	if (_strcmp(status, "success"))
	{
		return (status);
	} /* checks for args, operators, separators */
	else if (_strcmp(status, "3"))
	{
		print_env(output_list, oi);
		return ("printed");
	}
	else
	{
		command = create_command(tokenized, path_head);
		/* fork, execve, wait, return here */
		status = execute_command(command, status);
		/* returns to check builtins */
		return (status);
	}
}
