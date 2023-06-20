#include "hashtable.h"

/**
 * swap_symbol_values - swaps whatever the values of two string nodes are
 * @key0: the first of two keys that need swapped
 * @key1: the second of two keys that need swapped
*/
void swap_string_values(table_t *symbol_table, const char *key0, const char *key1)
{
	char *original_val0;
	char *original_val1;

	if (!key0 || !key1 || symbol_table->datatype != STRING)
		return;

	original_val0 = retrieve_string_value(symbol_table, key0);
	original_val1 = retrieve_string_value(symbol_table, key1);

	modify_string_node(symbol_table, key0, original_val1);
	modify_string_node(symbol_table, key1, original_val0);
}
