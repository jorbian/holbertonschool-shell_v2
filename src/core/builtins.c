#include "hsh.h"

/**
 * exit_sh - implementation of the 'exit' builtin command
 * @args: any arguments, if any that were passed to it
 *
*/
void exit_sh(char **args)
{
	fflush(NULL);

	free_string_array(args);

	deinitalize_shell();

	exit(0);
}

/**
 * change_dir - implementation of the 'cd' builtin command
 * @args: any arguments, if any that were passed to it
 *
*/
void change_dir(char **args)
{
	free_string_array(args);

	printf("THE 'cd' COMMAND WAS INVOKED!");
}

/**
 * set_var - implementation of the 'setenv' builtin command
 * @args: any arguments, if any that were passed to it
 *
*/
void set_var(char **args)
{
	free_string_array(args);

	printf("THE 'setenv' COMMAND WAS INVOKED!");
}

/**
 * unset_var - implementation of the 'unsetenv' builtin command
 * @args: any arguments, if any that were passed to it
 *
*/
void unset_var(char **args)
{
	free_string_array(args);

	printf("THE 'unsetenv' COMMAND WAS INVOKED!");
}

/**
 * list_envs - implementation of the 'env' builtin command
 * @args: any arguments, if any that were passed to it
 *
*/
void list_envs(char **args)
{
	(void)args;

	list_all_nodes(symbol_table);
}
