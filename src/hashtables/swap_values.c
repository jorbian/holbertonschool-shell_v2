#include "hashtable.h"

/**
 * swap_node_values - swaps whatever the values of two string nodes are
 * @table: the symbol table
 * @key0: the first of two keys that need swapped
 * @key1: the second of two keys that need swapped
*/
void swap_node_values(table_t *table, const char *key0, const char *key1)
{
	char *original_val0;
	char *original_val1;

	if (!key0 || !key1)
		return;

	original_val0 = retrieve_value(table, key0);
	original_val1 = retrieve_value(table, key1);

	modify_node(table, key0, original_val1);
	modify_node(table, key1, original_val0);
}
