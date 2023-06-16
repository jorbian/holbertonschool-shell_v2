#include "include/symbol_table.h"
#include "include/shellv2.h"

/* I NORMALLY HATE GLOBALS BUT THIS IS STUFF THAT WOULD GO ON STRUCT */
table_t *symbol_table;
char **path_list;
char *line_buffer;

/**
 * initalize_shell - creates the symbol table and path list
 * @argc: passed up from main
 * @argv: passed up from main
 * @envp: passed up from main
 * 
 * Return: Either EXIT_SUCESS '0' or EXIT_FAILURE '1'
*/
int initalize_shell(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	int allocation_failure;

	//is_active = 1;

	allocation_failure = retrieve_environmental_variables(envp);
	if (allocation_failure)
		return (EXIT_FAILURE);

	allocation_failure = tokenize_path();
	if (allocation_failure)
	{
		delete_symbol_table();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * deinitalize_shell - deallocates global variables from memory
*/
void deinitalize_shell(void)
{
	delete_symbol_table();
	free_string_array(path_list);
}

/**
 * retrieve_environmental_variables - creates symbol table places envs there
 * @envp: array containing envs passed up directly from main.
 *
 * Description: TBD
 * Return: Either EXIT_SUCESS '0' or EXIT_FAILURE '1'
*/
static int retrieve_environmental_variables(char **envp)
{
	char *variable, *current_val;

	unsigned int index, malloc_fail;

	malloc_fail = create_symbol_table(255);

	if (malloc_fail)
		return (EXIT_FAILURE);

	for (index = 0; envp[index] != NULL; index++)
	{
		variable = take_left_string(envp[index], '=');
		current_val = take_right_string(envp[index], '=');

		new_symbol(variable, current_val);

		free(variable);
		free(current_val);
	}
	return (EXIT_SUCCESS);
}

/**
 * tokenize_path - turns the PATH variable into a traversable array
 *
 * Return: If there was a problem, '1' for Yes, '0' for No.
*/
int tokenize_path(void)
{
	char delim[] = {':', '=', '\n'};

	char *path_buffer;

	path_buffer = retrieve_symbol_value("PATH");
	if (path_buffer == NULL)
		return (EXIT_FAILURE);

	path_list = tokenize_string(path_buffer, delim);
	if (path_list == NULL)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
