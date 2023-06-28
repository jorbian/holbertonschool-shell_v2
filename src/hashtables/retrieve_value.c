#include "hashtable.h"

/**
 * retrieve_value - gets a matched value from a hash table
 * @table: the hash table we're working with
 * @key: key to search for in table
 *
 * Return: matched value in table, or NULL if no match
 */
char *retrieve_value(table_t *table, const char *key)
{
	size_t i;
	char *requested_value = NULL;
	node_t *cmp;

	if (!table || !key || *key == '\0')
		return (NULL);

	i = key_index((unsigned char *)key, table->max_length);

	cmp = table->array[i];

	for (; cmp; cmp = cmp->next)
	{
		if (_strcmp(key, cmp->key) == 0)
			requested_value = cmp->value;
	}
	return (requested_value);
}

/**
 * modify_node - changes the value of the specified symbol with key
 * @table: hash table with node to modify
 * @key: the key that needs to be modified
 * @new_value: the new value that needs to be put there
*/
void modify_node(table_t *table, const char *key, char *new_value)
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
		{
			free(current_symbol->value);
			current_symbol->value = string_dup(new_value);
		}

		current_symbol = current_symbol->next;
	}
	free(new_value);
}
