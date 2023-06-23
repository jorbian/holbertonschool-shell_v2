#include "hsh.h"

void my_exit(char **args)
{
    (void)args;

    int exit_status = EXIT_SUCCESS;

    fflush(NULL);

    delete_hash_table(symbol_table);

    free_string_array(path_list);

    exit(exit_status);
}
