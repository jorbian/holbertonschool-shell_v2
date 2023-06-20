#include "hashtable.h"
#include "builtins.h"

/**
 * find_builtin - gets a matched value from a hash table
 * @key: key to search for in table
 *
 * Return: matched value in table, or NULL if no match
 */
builtin_t find_builtin(table_t *symbol_table, const char *key)
{
	size_t i;
	node_t *cmp;

	if (!symbol_table || !key || *key == '\0')
		return (NULL);

	i = key_index((unsigned char *)key, symbol_table->max_length);

	cmp = symbol_table->array[i];

	for (; cmp; cmp = cmp->next)
	{
		if (_strcmp(key, cmp->key) == 0)
				return (cmp->value);
	}
	return (NULL);
}
