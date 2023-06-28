#include "hashtable.h"

enum str_lens {KEY, VALUE, ARRAY_NODE};

/**
 * list_all_nodes - lists the keys and values of string hash table
 * @table: string table whose values needs to be listed
 *
 * Description: Lists in the format "key=value\n" for every key, value pair
*/
void list_all_nodes(table_t *table)
{
	size_t i = 0;

	node_t *current_node;

	for (i = 0; i < table->max_length; i++)
	{
		current_node = table->array[i];
		for (; current_node != NULL; current_node = current_node->next)
			printf("%s=%s\n", current_node->key, (char *)current_node->value);
	}
}

/**
 * cast_to_array - casts a hash table to an array
 * @table: hash table that needs converted to an array
 *
 * Return: Pointer to the first element of new array.
*/
char **cast_to_array(table_t *table)
{
	size_t index[2] = {0, 0};
	size_t string_len[3] = {0, 0, 0};
	size_t array_length = table->current_length;

	node_t *current_node;

	char **new_array = new_string_array(array_length);
	if (new_array == NULL)
		return (NULL);

	for (index[0] = 0; index[0] < table->max_length; index[0]++)
	{
		current_node = table->array[index[0]];

		for (; current_node != NULL; current_node = current_node->next)
		{
			string_len[KEY] = _strlen(current_node->key);
			string_len[VALUE] = _strlen(current_node->value);
			string_len[ARRAY_NODE] = string_len[KEY] + string_len[VALUE] + 2;

			new_array[index[1]] = malloc(sizeof(char) * string_len[ARRAY_NODE]);

			sprintf(
				new_array[index[1]],
				"%s=%s",
				current_node->key,
				current_node->value
			);
			index[1]++;
		}
	}
	return (new_array);
}
