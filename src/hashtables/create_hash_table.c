#include "hashtable.h"

/**
 * create_hash_table - creates and initializes an empty hash table
 * @size: number of elements to store in the table
 * Return: pointer to new table
 */
table_t *create_hash_table(size_t max_length, enum type_t type)
{
	size_t i;
	
    table_t *new_hash_table;

	new_hash_table = malloc(sizeof(table_t));

	if (!new_hash_table || max_length == 0)
		return (NULL);

	/* Allocate table array */
	new_hash_table->array = malloc(sizeof(node_t *) * max_length);

	/* Check failed malloc */
	if (!new_hash_table->array)
	{
		free(new_hash_table);
		return (NULL);
	}

	/* Set each to null */
	for (i = 0; i < max_length; i++)
		new_hash_table->array[i] = NULL;

	new_hash_table->datatype = type;
	new_hash_table->max_length = max_length;
	new_hash_table->current_length = 0;

	return (new_hash_table);
}
