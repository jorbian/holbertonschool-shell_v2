#ifndef SHELLV2_H
#define SHELLV2_H

#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "arrays.h"
#include "my_strings.h"
#include "symbol_table.h"

#define INPUT_BUFF 255

extern char **path_list;
extern char *line_buffer;
extern int is_active;

int initalize_shell(int argc, char **argv, char **envp);
int tokenize_path();
static int retrieve_environmental_variables(char **envp);
void deinitalize_shell(void);

char *take_input(void);
char **parse_statement(char *statement);
static char **has_args(char *statement);
static char **no_args(char *statement);

void back_a_directory();
void list_all_env();

#endif