#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "builtins.h"
#include "hashtable.h"
#include "my_strings.h"

extern char **path;
extern int exit_status;
extern int line_num;
extern table_t *symbol_table;

int initalize_shell(int argc, char **argv, char **envp);
int deinitalize_shell(void);

void process_command(char *new_line);
void throw_error(int line, int error_type, char *param);

#endif
