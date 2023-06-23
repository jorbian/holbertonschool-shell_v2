#ifndef BUILTINS_H
#define BUILTINS_H

#include <unistd.h>

#include "hashtable.h"

#define NUM_OF_BUILTINS 2
#define NAMES_OF_BUILTINS {"env", "exit"}
#define FUNCTION_PTRS {print_env, my_exit}

void print_env(char **args);
void my_exit(char **args);

int add_builtin(table_t *builtin_table, const char *key, const void *value);
builtin_t find_builtin(table_t *symbol_table, const char *key);

#endif
