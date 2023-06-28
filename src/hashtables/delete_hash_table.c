#include "hashtable.h"

/**
 * delete_hash_table - frees all elements of @ht
 * @table: hash table to delete
 */
void delete_hash_table(table_t *table)
{
	size_t i;

	node_t *current_node;

	if (!table || table->max_length == 0)
		return;

	for (i = 0; i < table->max_length; i++)
	{
		if (table->array[i])
		{
			while (table->array[i])
			{
				current_node = table->array[i]->next;

				free(table->array[i]->key);
				free(table->array[i]->value);
				free(table->array[i]);

				table->array[i] = current_node;
			}
		}
	}
	free(table->array);
	free(table);
}
