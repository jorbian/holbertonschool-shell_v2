#include "hashtable.h"

/**
 * retrieve_environmental_variables - creates symbol table places envs there
 * @envp: array containing envs passed up directly from main.
 *
 * Description: TBD
 * Return: Either EXIT_SUCESS '0' or EXIT_FAILURE '1'
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