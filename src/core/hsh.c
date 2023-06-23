#include "hsh.h"

table_t *symbol_table;
char **path_list;

/**
 * main - The start of the shell including infinite loop
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * @env: user environment at program start
 * 
 * Return: 0
 */
int main(int argc, char *argv[], char **envp)
{
	int interactive = isatty(STDIN_FILENO);

	create_globals(argc, argv, envp);

	return (0);
}
