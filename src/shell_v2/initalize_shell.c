#include "shellv2.h"

static int abort_initalization();
static table_t *retrieve_environmental_variables(char **envp);
static table_t *build_builtin_table();

int initalize_shell(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	symbol_table = retrieve_environmental_variables(envp);
	builtins = build_builtin_table();

	return (EXIT_SUCCESS);
}

/**
 * abort_initalization - immediately aborts initalization of shell
 * 
 * Return: Always returns EXIT_FAILURE, i.e. '1'
*/
static int abort_initalization()
{
	free_shell();

	return (EXIT_FAILURE);
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

static table_t *build_builtin_table()
{
	size_t i;

	char names_of_builtins[NUM_OF_BUILTINS][10] = NAMES_OF_BUILTINS;

	builtin_t function_ptrs[NUM_OF_BUILTINS] = FUNCTION_PTRS;

	table_t *new_builtin_table = create_hash_table(2, BUILTIN);

	for (i = 0; i < NUM_OF_BUILTINS; i++)
	{
		add_builtin(
			new_builtin_table,
			names_of_builtins[i],
			function_ptrs[i]
		);
	}
	return (new_builtin_table);
}
