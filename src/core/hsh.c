#include "hsh.h"

table_t *symbol_table;
char **path_list;

/**
 * main - The start of the shell including infinite loop
 *
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * @env: user environment at program start
 * Return: 0
 */

int main(int argc, char *argv[], char **env)
{

	int interactive = isatty(STDIN_FILENO);
	size_t bytes = 0;
	char *buffer;
	char **tokenized;

	symbol_table = retrieve_environmental_variables(argc, argv, env);

	path_list = create_path_list();

	list_string_array(path_list);

	delete_hash_table(symbol_table);

	free_string_array(path_list);

	return (0);
}
