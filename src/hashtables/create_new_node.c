#include "hashtable.h"

static int check_capactiy(const table_t *hash_table);
static node_t *initalize_node(const char *key, const char *value);
static int place_on_table(table_t *hash_table, node_t *new_node);

/**
 * create_new_node - sets an element of a hash table
 * @table: pointer to a hash table struct
 * @key: search object to indicate @value
 * @value: void pointer castable back to (char *), i.e. a string
 *
 * Return: 0 on success, 1 on fail
 */
int create_new_node(table_t *table, const char *key, const char *value)
{
	node_t *new_node;

	int table_at_capacity = check_capactiy(table);

	int cannot_create_node = (
		!table ||
		key == NULL ||
		*key == '\0' ||
		table_at_capacity
	);

	if (cannot_create_node)
		return (EXIT_FAILURE);

	new_node = initalize_node(key, value);
	if (new_node == NULL)
		return (EXIT_FAILURE);

	return (place_on_table(table, new_node));
}

/**
 * initalize_node - allocates memory for node and intializes key
 * @key: the string representing the symbol
 * @value: value that key is supposed to represent
 *
 * Return: Pointer to the newly created symbol.
*/
static node_t *initalize_node(const char *key, const char *value)
{
	node_t *new_node;

	new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = _strdup(key);
	new_node->value = _strdup(value);
	new_node->next = NULL;

	return (new_node);
}

/**
 * place_on_table - puts the symbol where it needs to go on table
 * @table: pointer to a hash table struct
 * @new_node: pointer to the symbol we're creating
 *
 * Return: EXIT_SUCESS '0' (if nothing goes wrong) --
 * EXIT_FAILURE '1' (if something does)
*/
static int place_on_table(table_t *table, node_t *new_node)
{
	size_t i;

	node_t *current_node;

	i = key_index((unsigned char *)new_node->key, table->max_length);

	current_node = table->array[i];

	if (current_node)
	{
		if (_strcmp(current_node->key, new_node->key) == 0)
		{
			new_node->next = current_node;
			table->array[i] = new_node;
			return (EXIT_FAILURE);
		}
		while (current_node->next)
		{
			if (_strcmp(current_node->next->key, new_node->key) == 0)
			{
				NEXT_ELEM(new_node) = NEXT_ELEM(current_node->next);
				FREE_ALL_SNODES(NEXT_ELEM(current_node));
				NEXT_ELEM(current_node) = new_node;
				return (EXIT_FAILURE);
			}
			current_node = current_node->next;
		}
	}
	NEXT_ELEM(new_node) = table->array[i];
	table->array[i] = new_node;
	table->current_length++;

	return (EXIT_SUCCESS);
}

/**
 * check_capactiy - true or false whether or not the table is at capacity
 * @table: pointer to the hash table that needs to be freed.
 *
 * Return: '1' for True, '0' for False
*/
static int check_capactiy(const table_t *table)
{
	return (
		table->current_length >= table->max_length
	);
}
