#include "include/shellv2.h"

/**
 * back_a_directory - implements the command 'cd -'
*/
void back_a_directory()
{
    swap_symbol_values("PWD", "OLDPWD");
}

/**
 * list_all_env - implementation of the env command
*/
void list_all_env()
{
	size_t i = 0;
	symbol_t *current_symbol;

	if (!symbol_table)
		return;

	for (i = 0; i < symbol_table->max_length; i++)
	{
		current_symbol = symbol_table->entries[i];
		for (; current_symbol != NULL; current_symbol = current_symbol->next)
			printf("%s=%s\n", current_symbol->key, current_symbol->value);
	}
}

/**
 * _exit - quickest verson I could come up with of exit
*/
void _exit()
{
    deinitalize_shell();

    fflush(NULL);

    exit(EXIT_SUCCESS);
}
