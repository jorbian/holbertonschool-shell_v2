#ifndef ENVS_H
#define ENVS_H

/**
 * struct pathlist_s - struct for putting PATH into a linked list
 * @file_path: the PATH
 * @next: pointer to next node
 */
typedef struct pathlist_s
{
	char *file_path;
	struct pathlist_s *next;
} path_t;

char *get_key(char *str);
char *get_value(char *str);
path_t *path_llist(path_t **head, char *path);

#endif