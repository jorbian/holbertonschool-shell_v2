#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "envs.h"
#include "hashtable.h"
#include "my_strings.h"

enum status_codes_t {
    FAILURE,
    SUCCESS,
    COMMAND_NOT_FOUND,
    EXIT,
    DIR_CHANGE,
    ENV_UPDATE,
    VAR_DELETE,
    ENV_LIST
};

extern table_t *symbol_table;
extern char **path_list;

table_t *retrieve_environmental_variables(int argc, char **argv, char **envp);
char **create_path_list();

/*separator/operator functions*/
int check_built_ins(char **tokenized);
char **tokenizer(char *buffer);
int parse_args(char **tokenized);

/* COMMAND EXECUTION FUNCTIONS */
void prompt(void);
int find_command(char **tokenized);
char *find_path(char **output_list);
char *create_command(char *filename);
int execute_command(char *command_name, char **args, int status);

int bi_exit();
int bi_chdir(char const *new_dir);
int bi_set_env();
int bi_unset_env();

char *get_pwd();
void print_env(char **list, int oi);

#endif /*HSH_H*/
