#include "hashtable.h"

/**
 * list_all_string_nodes - lists the keys and values of string hash table
 * @string_table: string table whose values needs to be listed
 * 
 * Description: Lists in the format "key=value\n" for every key, value pair
*/
void list_all_string_nodes(table_t *string_table)
{
	size_t i = 0;

	node_t *current_node;

	if (!string_table | (string_table->datatype != STRING))
		return;

	for (i = 0; i < string_table->max_length; i++)
	{
		current_node = string_table->array[i];
		for (; current_node != NULL; current_node = current_node->next)
			printf("%s=%s\n", current_node->key, (char *)current_node->value);
	}
}
