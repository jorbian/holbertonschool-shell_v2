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

#include "my_strings.h"
#include "builtins.h"

/*execution functions*/
void prompt(void);
char *find_command(char **tokenized, env_t *head);
char *create_command(char *filename, path_t *path_llist);
char *execute_command(char **cmd, char *status);

#endif /*HSH_H*/
