#include "include/symbol_table.h"

/**
 * retrieve_symbol_value - gets a matched value from a hash table
 * @key: key to search for in table
 *
 * Return: matched value in table, or NULL if no match
 */
char *retrieve_symbol_value(const char *key)
{
	size_t i;
	char *requested_value = NULL;
	symbol_t *cmp;

	if (!symbol_table || !key || *key == '\0')
		return (NULL);

	i = key_index((unsigned char *)key, symbol_table->max_length);

	cmp = symbol_table->entries[i];

	for (; cmp; cmp = cmp->next)
	{
		if (_strcmp(key, cmp->key) == 0)
			requested_value = cmp->value;
	}
	return (requested_value);
}
