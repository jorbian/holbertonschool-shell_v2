#ifndef SHELLV2_H
#define SHELLV2_H

#include "my_strings.h"
#include "arrays.h"
#include "hashtable.h"
#include "builtins.h"

#define PROMPT "($) "

extern table_t *symbol_table;
extern table_t *builtins;

int initalize_shell(int argc, char **argv, char **envp);
void free_shell();

void parse_and_execute_input(char *user_input);
void open_repl();

#endif
