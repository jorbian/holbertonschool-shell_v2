#include "hsh.h"

#define CURPWD 0
#define NEWPWD 1

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
	char *dirnames[2];

	dirnames[CURPWD] = _strdup(retrieve_value(symbol_table, "PWD"));

	if (args[1] != NULL)
	{
		if (args[1][0] == '-')
			dirnames[NEWPWD] = _strdup(
				retrieve_value(symbol_table, "OLDPWD")
			);
		else if (args[1][0] != '~')
			dirnames[NEWPWD] = _strdup(args[1]);
		else
			dirnames[NEWPWD] = _strdup(
				retrieve_value(symbol_table, "HOME")
		);
	}
	else
	{
		dirnames[NEWPWD] = _strdup(
			retrieve_value(symbol_table, "HOME")
		);
	}
	chdir(dirnames[NEWPWD]);

	modify_node(symbol_table, "PWD", dirnames[NEWPWD]);
	modify_node(symbol_table, "OLDPWD", dirnames[CURPWD]);
}

/**
 * set_var - implementation of the 'setenv' builtin command
 * @args: any arguments, if any that were passed to it
 *
*/
void set_var(char **args)
{
	create_new_node(symbol_table, args[1], args[2]);
}

/**
 * unset_var - implementation of the 'unsetenv' builtin command
 * @args: any arguments, if any that were passed to it
 *
*/
void unset_var(char **args)
{
	delete_node(symbol_table, args[1]);
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
