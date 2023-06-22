#include "hsh.h"

/**
 * create_command - created the command to execute
 * @filename: the file name to be executed
 * @path_llist: linked list made from PATH
 * 
 * Return: NULL if NULL or the filename to execute
 */
char *create_command(char *filename)
{
	struct stat st;
	char *file;

	if (stat(filename, &st) == 0)
		return (filename);

	return (NULL);
}
