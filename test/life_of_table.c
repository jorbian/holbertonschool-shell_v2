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

/**
 * modify_symbol_value - changes the value of the specified symbol with key
 * @key: the key that needs to be modified
 * @new_value: the new value that needs to be put there
*/
void modify_symbol_value(const char *key, char *new_value)
{
	size_t i;

	symbol_t *current_symbol;

	if (!symbol_table || !key || !new_value)
		return;

	i = key_index((unsigned char *)key, symbol_table->max_length);

	current_symbol = symbol_table->entries[i];

	while (current_symbol)
	{
		if (_strcmp(current_symbol->key, key) == 0)
			current_symbol->value = _strdup(new_value);

		current_symbol = current_symbol->next;
	}
	free(new_value);
}

/**
 * delete_symbol - deletes the symbol matching the given key
 * @key: the key value pair that needs to be deleted
*/
void delete_symbol(const char *key)
{
	size_t index;

	symbol_t *current_symbol, *previous_symbol;

	if (symbol_table == NULL || key == NULL)
		return;

	index = key_index((unsigned char *)key, symbol_table->max_length);

	current_symbol = symbol_table->entries[index];
	previous_symbol = NULL;

	while (current_symbol)
	{
		if (_strcmp(current_symbol->key, key) == 0)
		{
			if (!previous_symbol)
				symbol_table->entries[index] = current_symbol->next;
			else
				previous_symbol->next = current_symbol->next;

			free(current_symbol->key);
			free(current_symbol->value);
			free(current_symbol);

			symbol_table->current_length--;

			return;
		}
		previous_symbol = current_symbol;
		current_symbol = current_symbol->next;
	}
}

/**
 * swap_symbol_values - swaps whatever the values of two symbols are
 * @key0: the first of two keys that need swapped
 * @key1: the second of two keys that need swapped
*/
void swap_symbol_values(const char *key0, const char *key1)
{
	size_t index[2];

	char *original_val0;
	char *original_val1;

	if (!key0 || !key1)
		return;

	index[0] = key_index((unsigned char *)key0, symbol_table->max_length);
	index[1] = key_index((unsigned char *)key1, symbol_table->max_length);

	original_val0 = retrieve_symbol_value(key0);
	original_val1 = retrieve_symbol_value(key1);

	modify_symbol_value(key0, original_val1);
	modify_symbol_value(key1, original_val0);
}
