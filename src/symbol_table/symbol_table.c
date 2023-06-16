#include "include/symbol_table.h"

/**
 * create_symbol_table - creates and initializes an empty hash table
 * @size: number of elements to store in the table
 * Return: pointer to new table
 */
table_t *create_symbol_table(size_t max_length)
{
	size_t i;
	
	symbol_table = malloc(sizeof(table_t));

	if (!symbol_table || max_length == 0)
		return (NULL);

	/* Allocate table entries */
	symbol_table->entries = malloc(sizeof(symbol_t *) * max_length);

	/* Check failed malloc */
	if (!symbol_table->entries)
	{
		free(symbol_table);
		return (NULL);
	}

	/* Set each to null */
	for (i = 0; i < max_length; i++)
		symbol_table->entries[i] = NULL;

	symbol_table->max_length = max_length;
	symbol_table->current_length = 0;

	return (symbol_table);
}

/**
 * hash_table_delete - frees all elements of @ht
 * @ht: hash table to delete
 */
void delete_symbol_table(table_t *symbol_table)
{
	size_t i;
	symbol_t *current_symbol;

	if (!symbol_table || symbol_table->max_length == 0)
		return;

	for (i = 0; i < symbol_table->max_length; i++)
	{
		if (symbol_table->entries[i])
		{
			while (symbol_table->entries[i])
			{
				current_symbol = symbol_table->entries[i]->next;
				free(symbol_table->entries[i]->key);
				free(symbol_table->entries[i]->value);
				free(symbol_table->entries[i]);
				symbol_table->entries[i] = current_symbol;
			}
		}
	}
	free(symbol_table->entries);
	free(symbol_table);
}
