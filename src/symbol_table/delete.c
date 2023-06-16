#include "symbol_table.h"

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
