#include "hsh.h"

char **create_path_list()
{
	char *path_string = NULL;
	char **path_list = NULL;

	if (symbol_table == NULL)
		return (NULL);

	path_string = _strdup(
		retrieve_string_value(symbol_table, "PATH")
	);

	path_list = tokenize_string(path_string, ":");
	if (path_list == NULL)
		return (NULL);

	free(path_string);

	return (path_list);
}
