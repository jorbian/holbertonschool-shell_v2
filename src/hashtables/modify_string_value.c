#include "hashtable.h"

/**
 * modify_string_nodee - changes the value of the specified symbol with key
 * @key: the key that needs to be modified
 * @new_value: the new value that needs to be put there
*/
void modify_string_node(table_t *table, const char *key, char *new_value)
{
	size_t i;

	node_t *current_symbol;

	if (!table || !key || !new_value)
		return;

	i = key_index((unsigned char *)key, table->max_length);

	current_symbol = table->array[i];

	while (current_symbol)
	{
		if (_strcmp(current_symbol->key, key) == 0)
			current_symbol->value = _strdup(new_value);

		current_symbol = current_symbol->next;
	}
	free(new_value);
}
