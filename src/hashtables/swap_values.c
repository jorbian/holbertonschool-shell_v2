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

/**
 * delete_node - deletes a node in a hash table
 * @hash_table: poinnter to the hash table with node to delete
 * @key: the key that needs to be deleted
*/
void delete_node(table_t *hash_table, char *key)
{
	size_t index = key_index((unsigned char *)key, hash_table->max_length);

	node_t *current = hash_table->array[index];
	node_t *prev = NULL;

	while (current != NULL)
	{
		if (_strcmp(current->key, key) == 0)
		{
			if (prev == NULL)
				hash_table->array[index] = current->next;
			else
				prev->next = current->next;

			free(current->key);
			free(current->value);
			free(current);

			hash_table->current_length--;

			return;
		}
		prev = current;
		current = current->next;
	}
}
