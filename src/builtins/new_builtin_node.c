#include "hashtable.h"
#include "builtins.h"

static node_t *initalize_builtin_node(const char *key);
static int place_on_table(table_t *hash_table, node_t *new_node);

/**
 * add_builtin - sets an element of a hash table
 * @string_table: pointer to a hash table struct
 * @key: search object to indicate @value
 * @value: void pointer castable back to (char *), i.e. a string
 *
 * Return: 0 on success, 1 on fail
 */
int add_builtin(table_t *builtin_table, const char *key, const void *value)
{
	node_t *new_node;

	int cannot_create_node = (
		!builtin_table ||
		key == NULL ||
		*key == '\0' ||
		builtin_table->datatype != BUILTIN
	);

	if (cannot_create_node)
		return (EXIT_FAILURE);

	new_node = initalize_builtin_node(key);
	if (new_node == NULL)
		return (EXIT_FAILURE);

    new_node->value = (builtin_t)value;

	return (place_on_table(builtin_table, new_node));
}

/**
 * initalize_builtin_node - allocates memory for node and intializes key
 * @key: the string representing the symbol
 *
 * Return: Pointer to the newly created symbol.
*/
static node_t *initalize_builtin_node(const char *key)
{
	node_t *new_node;

	new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = _strdup(key);
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
		if (_strcmp(current_node->key, new_node->key) == 0)
		{
			new_node->next = current_node;
			hash_table->array[i] = new_node;
			return (EXIT_FAILURE);
		}
		while (current_node->next)
		{
			current_node = current_node->next;
		}
	}
	NEXT_ELEM(new_node) = hash_table->array[i];
	hash_table->array[i] = new_node;
	hash_table->current_length++;

	return (EXIT_SUCCESS);
}
