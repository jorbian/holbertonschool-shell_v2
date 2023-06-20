#include "hashtable.h"

/**
 * hash_table_delete - frees all elements of @ht
 * @ht: hash table to delete
 */
void delete_hash_table(table_t *hash_table)
{
	size_t i;

	node_t *current_node;

	if (!hash_table || hash_table->max_length == 0)
		return;

	for (i = 0; i < hash_table->max_length; i++)
	{
		if (hash_table->array[i])
		{
			while (hash_table->array[i])
			{
				current_node = hash_table->array[i]->next;

				free(hash_table->array[i]->key);
                if ((hash_table->datatype == STRING))
				    free(hash_table->array[i]->value);
				free(hash_table->array[i]);

				hash_table->array[i] = current_node;
			}
		}
	}
	free(hash_table->array);
	free(hash_table);
}
