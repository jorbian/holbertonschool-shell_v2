#include "hashtable.h"

static int check_capactiy(const table_t *hash_table);
static node_t *initalize_string_node(const char *key, const char *value);
static int place_on_table(table_t *hash_table, node_t *new_node);

/**
 * new_string_node - sets an element of a hash table
 * @string_table: pointer to a hash table struct
 * @key: search object to indicate @value
 * @value: void pointer castable back to (char *), i.e. a string
 *
 * Return: 0 on success, 1 on fail
 */
int new_string_node(table_t *string_table, const char *key, const void *value)
{
	node_t *new_node;

	int table_at_capacity = check_capactiy(string_table);

	int cannot_create_node = (
		!string_table ||
		key == NULL ||
		*key == '\0' ||
		table_at_capacity ||
		string_table->datatype != STRING
	);

	if (cannot_create_node)
		return (EXIT_FAILURE);

	new_node = initalize_string_node(key, (char *)value);
	if (new_node == NULL)
		return (EXIT_FAILURE);

	return (place_on_table(string_table, new_node));
}

/**
 * create_symbol - allocates memory for node and intializes key
 * @key: the string representing the symbol
 *
 * Return: Pointer to the newly created symbol.
*/
static node_t *initalize_string_node(const char *key, const char *value)
{
	node_t *new_node;

	new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;

	return (new_node);
}

/**
 * place_on_table - puts the symbol where it needs to go on table
 * @hash_table: pointer to a hash table struct
 * @new_node: pointer to the symbol we're creating
 *
 * Return: EXIT_SUCESS '0' (if nothing goes wrong) --
 * EXIT_FAILURE '1' (if something does)
*/
static int place_on_table(table_t *hash_table, node_t *new_node)
{
	size_t i;

	node_t *current_node;

	i = key_index((unsigned char *)new_node->key, hash_table->max_length);

	current_node = hash_table->array[i];

	if (current_node)
	{
		if (strcmp(current_node->key, new_node->key) == 0)
		{
			new_node->next = current_node;
			hash_table->array[i] = new_node;
			return (EXIT_FAILURE);
		}
		while (current_node->next)
		{
			if (strcmp(current_node->next->key, new_node->key) == 0)
			{
				NEXT_ELEM(new_node) = NEXT_ELEM(current_node->next);
				FREE_ALL_SNODES(NEXT_ELEM(current_node));
				NEXT_ELEM(current_node) = new_node;
				return (EXIT_FAILURE);
			}
			current_node = current_node->next;
		}
	}
	NEXT_ELEM(new_node) = hash_table->array[i];
	hash_table->array[i] = new_node;
	hash_table->current_length++;

	return (EXIT_SUCCESS);
}

/**
 * check_capactiy - true or false whether or not the table is at capacity
 * @hash_table: pointer to the hash table that needs to be freed.
 *
 * Return: '1' for True, '0' for False
*/
static int check_capactiy(const table_t *hash_table)
{
	return (
		hash_table->current_length >= hash_table->max_length
	);
}
