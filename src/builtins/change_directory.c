#include "hsh.h"

/**
 * change_directory - implementation of cd as builtin command
 * 
 * Description: An outside facing wrapper to the rest of the program.
 * This function is there to handle special cases and direct traffic.

void change_directory(char **args)
{
    if ((args == NULL))
        to_home_dir();
    else if (args[0][0] == "-")
        to_previous_dir();
    else
        _change_directory(args[0]);
}

/**
 * change_directory - the real implementation of cd as builtin command
 * 
 * Description: This is where the magic actually happens once we've sorted out
 * what the new directory is actually supposed to be.

static int _change_directory(char *new_dir)
{
    char *old_directory;

    old_directory = _strdup(retrieve_string_value(symbol_table, "PWD"));

    free(old_directory);
}

static int to_previous_dir()
{
    _change_directory(
        retrieve_string_value(symbol_table, "OLDPWD")
    );
}

static int to_home_dir()
{
    _change_directory(
        retrieve_string_value(symbol_table, "HOME")
    );
}
*/