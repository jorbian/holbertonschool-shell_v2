#include "hsh.h"

static char **create_command_path(const char *path_variable);
static table_t *retrieve_environmental_variables(char **envp);

/**
 * initalize_shell - allocates memory for global variables
 * @argc: passed up directly from main
 * @argv: passed up directly from main
 * @envp: the enviornmental variables.
 *
 * Return: Whether or not there was a problem allocating memory --
 * '1,' i.e. EXIT_FAILURE for 'yes,' or '0' (EXIT_SUCCESS) for 'no.'
*/
int initalize_shell(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	environ = envp;

	symbol_table = retrieve_environmental_variables(envp);
	if (symbol_table == NULL)
		return (EXIT_FAILURE);

	path = create_command_path(retrieve_value(symbol_table, "PATH"));
	if (path == NULL)
		return (deinitalize_shell());

	return (EXIT_SUCCESS);
}

/**
 * create_command_path - splits the PATH variable into walkable array to parse
 * @path_variable: PATH variable as a single string
 *
 * Return: That string split into array based on where ":" appears
*/
static char **create_command_path(const char *path_variable)
{
	char **split_path = NULL;

	char *copy_to_shred = _strdup(path_variable);

	split_path = tokenize_string(copy_to_shred, ":");

	if (split_path == NULL)
		return (NULL);

	free(copy_to_shred);

	return (split_path);
}

/**
 * retrieve_environmental_variables - creates symbol table places envs there
 * @envp: array containing envs passed up directly from main.
 *
 * Description: TBD
 * Return: Pointer to enviornmental variables in hastable
*/
static table_t *retrieve_environmental_variables(char **envp)
{
	char *variable, *current_val;

	unsigned int index;

	table_t *new_symbol_table = create_hash_table(255);

	for (index = 0; envp[index] != NULL; index++)
	{
		variable = take_left_string(envp[index], '=');
		current_val = take_right_string(envp[index], '=');

		create_new_node(new_symbol_table, variable, current_val);

		free(variable);
		free(current_val);
	}
	return (new_symbol_table);
}

/**
 * deinitalize_shell - deallocates memory for global variables
 *
 * Return: Whether or not it was sucess full --
*/
int deinitalize_shell(void)
{
	if (symbol_table != NULL)
		delete_hash_table(symbol_table);

	if (path != NULL)
		free_string_array(path);

	return (TRUE);
}
