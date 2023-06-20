#include "shellv2.h"

table_t *symbol_table;
table_t *builtins;

int main(int argc, char **argv, char **envp)
{
    char **foo = NULL;

    builtin_t test;

    initalize_shell(argc, argv, envp);

    test = find_builtin(builtins, "env");

    test(foo);

    free_shell();

    return (0);
}
