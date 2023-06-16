#include "include/symbol_table.h"

/**
 * create_symbol_table - creates and initializes an empty hash table
 * @size: number of elements to store in the table
 * Return: pointer to new table
 */
int create_symbol_table(size_t max_length)
{
	size_t i;
	
	symbol_table = malloc(sizeof(table_t));

	if (!symbol_table || max_length == 0)
		return (EXIT_FAILURE);

	/* Allocate table entries */
	symbol_table->entries = malloc(sizeof(symbol_t *) * max_length);

	/* Check failed malloc */
	if (!symbol_table->entries)
	{
		free(symbol_table);
		return (EXIT_FAILURE);
	}

	/* Set each to null */
	for (i = 0; i < max_length; i++)
		symbol_table->entries[i] = NULL;

	symbol_table->max_length = max_length;
	symbol_table->current_length = 0;

	return (EXIT_SUCCESS);
}

/**
 * hash_table_delete - frees all elements of @ht
 * @ht: hash table to delete
 */
void delete_symbol_table()
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

/**
 * key_index - returns location to store value in symbol table
 * @key: string to store
 * @size: number of elements in table
 * Return: location to store @key
 */
size_t key_index(const unsigned char *key, size_t max_length)
{
	return (hash_djb2(key) % max_length);
}

/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 * Return: hash value
 */
static size_t hash_djb2(const unsigned char *str)
{
	size_t hash;
	int c;

	hash = HASH_VALUE;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash);
}
