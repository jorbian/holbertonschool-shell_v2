#include "shellv2.h"

void my_exit(char **args)
{
    (void)args;

    int exit_status = EXIT_SUCCESS;

    fflush(NULL);

    free_shell();

    exit(exit_status);
}