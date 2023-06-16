#include "symbol_table.h"

/**
 * swap_symbol_values - swaps whatever the values of two symbols are
 * @key0: the first of two keys that need swapped
 * @key1: the second of two keys that need swapped
*/
void swap_symbol_values(table_t *symbol_table, const char *key0, const char *key1)
{
	size_t index[2];

	char *original_val0;
	char *original_val1;

	if (!key0 || !key1)
		return;

	index[0] = key_index((unsigned char *)key0, symbol_table->max_length);
	index[1] = key_index((unsigned char *)key1, symbol_table->max_length);

	original_val0 = retrieve_symbol_value(symbol_table, key0);
	original_val1 = retrieve_symbol_value(symbol_table, key1);

	modify_symbol_value(symbol_table, key0, original_val1);
	modify_symbol_value(symbol_table, key1, original_val0);
}
