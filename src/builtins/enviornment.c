#include "hsh.h"

/**
 * print_env - implementation of the 'env' builtin command
 * @args: a null value character pointer or empty array
*/
void print_env(char **args)
{
    (void)args;

    list_all_string_nodes(symbol_table);
}
