#ifndef BUILTINS_H
#define BUILTINS_H

#define NUM_OF_BILTNS 6
#define BLTN_NAME_LEN 9
#define BUILTIN_NAMES {"exit", "cd", "setenv", "unsetenv", "env"}
#define BUILTIN_FPTRS {exit_sh, change_dir, set_var, unset_var, list_envs}

void exit_sh(char **args);
void change_dir(char **args);
void set_var(char **args);
void unset_var(char **args);
void list_envs(char **args);

#endif
