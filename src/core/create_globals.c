#include "hsh.h"

static table_t *retrieve_env_variables(char **envp);
static char **create_path_list();

/**
 * create_globals - creates  the global varialbes ncessary for application
 * @argc: the number of arguments passed up from main
 * @argv: whatever those arguments were contained in array
 * @envp: the enviornmental variabls
*/
void create_globals(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	symbol_table = retrieve_env_variables(envp);

	path_list = create_path_list();
}

/**
 * retrieve_env_variables - creates symbol table places envs there
 * @envp: array containing envs passed up directly from main.
 *
 * Description: TBD
 * Return: Pointer to enviornmental variables in hastable
*/
static table_t *retrieve_env_variables(char **envp)
{
	char *variable, *current_val;

	unsigned int index;

	table_t *new_symbol_table = create_hash_table(255, STRING);

	for (index = 0; envp[index] != NULL; index++)
	{
		variable = take_left_string(envp[index], '=');
		current_val = take_right_string(envp[index], '=');

		new_string_node(new_symbol_table, variable, current_val);

		free(variable);
		free(current_val);
	}
	return (new_symbol_table);
}

/**
 * create_path_list - breaks up the contents of PATH variable
 * 
 * Return: the PATH variable broken up into array
*/
static char **create_path_list()
{
	char *path_string = NULL;
	char **path_list = NULL;

	if (symbol_table == NULL)
		return (NULL);

	path_string = _strdup(
		retrieve_string_value(symbol_table, "PATH")
	);

	path_list = tokenize_string(path_string, ":");
	if (path_list == NULL)
		return (NULL);

	free(path_string);

	return (path_list);
}
